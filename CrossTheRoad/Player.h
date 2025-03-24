#pragma once
#include"Hitbox.h"
#include"Lane.h"
#include<condition_variable>
#define PEROT		0
#define PENGUIN		1
#define CHICK		2
#define BEE			3
#define	DOGO		4	



const int PlayerWidth[5] = {5,5,5,7,7};
const int PlayerHeight[5] = { 3,3,3,3,3 };

class Player
{
private:
	Hitbox* playerBox;	//Hitbox of player
	bool status;	//Status 1 : alive, 0 : dead
	short type;	//There are 4 type to choose

	//Speed of player
	int v_speed;
	int h_speed;


	bool display;	//Display on screen
public:
	Player();
	Player(Point2D, int, int, int);
	~Player();



	//get - set position of player (up left of hit box)
	void set_position(int, int);
	Point2D get_position();

	//get - set status
	void set_status(bool);
	bool get_status();

	// get - set type
	void set_type(short);
	short get_type();

	//get - set size
	void set_height(int);
	int get_height();
	void set_width(int);
	int get_width();
	void set_size(int, int);

	//get - set speed
	void set_Vspeed(int);
	int get_Vspeed();
	void set_Hspeed(int);
	int get_Hspeed();
	void set_speed(int, int);

	//get - set display
	void set_display(bool);
	bool get_display(bool);

	//get - set collision of hitbox
	bool get_impact();
	void set_impact(bool);

	//move player
	void move_left(int background_Color); //dthien
	void move_right(int background_Color); //dthien
	void move_up(vector<Lane*> lanelist); //dthien
	void move_down(vector<Lane*> lanelist); //dthien
	bool move_player(vector<Lane*> lanelist); //dthien

	void Draw(bool mode, int background_Color); //dthien
};

