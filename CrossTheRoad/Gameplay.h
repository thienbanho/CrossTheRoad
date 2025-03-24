#pragma once
//#include"Lane.h"
#include"Player.h"
#include"Proccess.h"


#define STARTING_POINT Point2D(50,21)

#define VERTICAL_SPEED		4
#define HORIZONTAL_SPEED	2	


class Gameplay
{
private:
	vector<Lane*> laneList;
	bool finish, pause, run, playerMove;
	Player* myPlayer;
public:
	Gameplay() = default;
	


	void setup_round1();
	void setup_start(int);
	void set_character(int);

	void start_game();
	void game_proccess();
	void start_player();
	void start_lane();


	void clearList();

};

