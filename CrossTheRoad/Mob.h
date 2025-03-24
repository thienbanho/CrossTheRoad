#pragma once
#include "Hitbox.h"
#include<condition_variable>
#define RED_CAR		0
#define BLUE_CAR	1
#define TRUCK		2
#define SHARK		3
const int MobWidth[4] = { 8,8,9 };
const int MobHeight[4] = { 3,3,3 };

const int MobLane[4] = { 1,1,1 };

class Mob
{
	Hitbox* mobBox;
	int type, speed, delay;
	bool status, display;

public:

	Mob();
	Mob(Point2D pos, int mob_type, int spd, int dly);
	Mob(const Mob& other);
	Mob& operator=(const Mob& other);
	~Mob();

	// get - set position of mob
	void set_position(int, int);
	Point2D get_position();

	// get - set status
	void set_status(bool);
	bool get_status();

	// get - set type
	void set_type(int);
	int get_type();

	// get - set size
	void set_height(int);
	int get_height();
	void set_width(int);
	int get_width();
	void set_size(int, int);

	//get - set delay
	void set_delay(int);
	int get_delay();
	// get - set speed
	void set_speed(int);
	int get_speed();

	//get - set display
	void set_display(bool);
	bool get_display(bool);

	//get hitbox
	Hitbox* get_hitbox();

	//move mob
	void move_left();
	void move_right();

	//Draw mob
	void Draw_Right(bool);
};

