#include "Gameplay.h"
mutex gamemtx;
void Gameplay::setup_start(int plType)
{
	finish = false;
	pause = false;
	run = true;
	
	set_character(plType);
	myPlayer->Draw(1, GREEN);
}

void Gameplay::set_character(int newType)
{
	if (myPlayer != nullptr)
		delete myPlayer;
	myPlayer = new Player(STARTING_POINT, newType, HORIZONTAL_SPEED, VERTICAL_SPEED);
}

void Gameplay::start_game()
{
	Basic::Console_Setup();
	Basic::Console_ClearScreen();
	setup_start(PENGUIN);
	setup_round1();

	thread lane_Thread(&Gameplay::start_lane, this);
	thread player_Thread(&Gameplay::start_player, this);
	//thread process_Thread(&Gameplay::game_proccess, this);
	Basic::joinThread(&lane_Thread);
	Basic::joinThread(&player_Thread);
	//Basic::joinThread(&process_Thread);
}

void Gameplay::game_proccess() //dthien
{
	while (run)
	{
		for (auto it : laneList)
		{
			if (Process::player_isIn(myPlayer, it))
			{
				if (playerMove)
				{
					it->Draw(); myPlayer->Draw(1, GREEN); 
					playerMove = false;
				}
			}
		}
	}
	
}

void Gameplay::start_player() //dthien
{
	while (run)
	{
		if (myPlayer->move_player(laneList))
			playerMove = true; Basic::sleepFor_milisec(50);
		
	}
}

void Gameplay::start_lane()
{
	if (run)
	{
		vector<thread> threadList;
		for (auto& it : laneList)
		{
			threadList.push_back(thread(&Lane::run, &*(it)));
		}
		for (auto& it : threadList)
		{
			Basic::joinThread(&it);
		}
	}
}

void Gameplay::clearList()
{
	for (auto& it : laneList)
		if (it != nullptr) delete it;
	laneList.clear();
}

void Gameplay::setup_round1()
{
	clearList();
	laneList.push_back(new Lane(7, HIGH_WAY, 15,10));
	laneList.push_back(new Lane(11, HIGH_WAY, 20,20));
	laneList.push_back(new Lane(15, HIGH_WAY, 25,50));
	laneList[0]->generate_HighwayMobs(1, 0, 1, 50);
	laneList[1]->generate_HighwayMobs(1, 1, 1, 50);
	laneList[2]->generate_HighwayMobs(2, 2, 0, 30);
	for (auto& it : laneList)
		it->Draw();
}