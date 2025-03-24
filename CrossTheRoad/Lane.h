#pragma once
#include "Mob.h"
#include <vector>
#include<condition_variable>
#define GRASS		0
#define HIGH_WAY	1
#define WATER		2
#define RAIL_WAY	3
#define LANE_HEIGHT 4
#define MOB_GAP		40



class Lane
{
private:
	int position;	//up point on y axis
	int type;		//type of lane
	bool status;	//on - off <=> red light - green light
	vector<Mob*> mobsList;		//List of mobs
	bool player_in;	//1 : player is on lane else 0
	int speed;
	int delay;

	int background_Color; //dthien new
public:

	Lane();
	Lane(int pos, int laneType, int spd, int dly);
	Lane(const Lane&);
	Lane& operator=(const Lane& other);
	~Lane();

	void set_position(int);
	int get_position();

	void set_type(int);
	int get_type();

	void set_stat(bool);
	bool get_stat();

	bool player_isIn();
	void set_playerIn(bool);

	int get_speed();
	void set_speed(int);

	int get_delay();
	void set_delay(int);

	int get_backgroundCoLor(); //dthien new
	void set_backgroundColor(int); //dthien new

	void clearList();

	void generate_HighwayMobs(int red = 0, int blu = 0, int truk = 0, int gap = 30);

	void Draw();

	void run();

	void mob_render();
};
