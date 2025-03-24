#include<iostream>
#include"Gameplay.h"
int main()
{
	/*Basic::Console_Setup();
	vector<Lane*> Lanelist;
	Lanelist.push_back(new Lane(1, GRASS, 15, 10));
	Lanelist.push_back(new Lane(5, HIGH_WAY, 15, 10));
	Lanelist.push_back(new Lane(9, HIGH_WAY, 15, 10));
	Lanelist.push_back(new Lane(13, GRASS, 15, 10));
	Lanelist.push_back(new Lane(17, WATER, 15, 10));
	Lanelist.push_back(new Lane(21, GRASS, 15, 10));
	Lanelist.push_back(new Lane(25, HIGH_WAY, 15, 10));
	Lanelist.push_back(new Lane(29, GRASS, 15, 10));
	for (auto& it : Lanelist)
		it->Draw();
	Player *myPlayer = new Player(STARTING_POINT, CHICK, HORIZONTAL_SPEED, VERTICAL_SPEED);
	int bgColor = GREEN;
	myPlayer->Draw(1, bgColor);
	while (true)
	{
		if (myPlayer->move_player(Lanelist)) {
		}
	}*/

	Basic::Console_Setup();
	UserInterface::DrawMenuGame();
	Basic::gotoXY(CONSOLE_WIDTH, CONSOLE_HEIGHT);
}

//NGUYEN TRAN DUC THIEN 23/11