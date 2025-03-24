#include "Player.h"

mutex Playermtx;

Player::Player()
{
	playerBox = new Hitbox();
	status = true;
	type = 1;
	v_speed = 0;
	h_speed = 0;
	display = 1;
}

Player::Player(Point2D pos, int newType, int newHspd, int newVspd)
{
	if (newType < PEROT || newType > DOGO)
		*this = Player();
	else
	{
		type = newType;
		status = 1;
		h_speed = newHspd;
		v_speed = newVspd;
		display = 1;
		playerBox = new Hitbox(pos,PlayerWidth[type],PlayerHeight[type],1,1,0);
	}

	
}

Player::~Player()
{
	if (playerBox != nullptr)
		delete playerBox;
}

void Player::set_position(int px, int py)
{
	playerBox->setUpLeft(Point2D(px, py));
}

Point2D Player::get_position()
{
	return playerBox->getUpLeft();
}

void Player::set_status(bool status)
{
	status = status;
}

bool Player::get_status()
{
	return status;
}

void Player::set_type(short type)
{
	type = type;
}

short Player::get_type()
{
	return type;
}

void Player::set_height(int height)
{
	playerBox->setHeight(height);
}

int Player::get_height()
{
	return playerBox->getHeight();
}

void Player::set_width(int width)
{
	playerBox->setWidth(width);
}

int Player::get_width()
{
	return playerBox->getWidth();
}

void Player::set_size(int width, int height)
{
	set_width(width);
	set_height(height);
}

void Player::set_Vspeed(int vspeed)
{
	v_speed = vspeed;
}

int Player::get_Vspeed()
{
	return v_speed;
}

void Player::set_Hspeed(int hspeed)
{
	h_speed = hspeed;
}

int Player::get_Hspeed()
{
	return h_speed;
}

void Player::set_speed(int vspeed, int hspeed)
{
	set_Vspeed(vspeed);
	set_Hspeed(hspeed);
}

void Player::set_display(bool mode)
{
	display = mode;
}

bool Player::get_display(bool)
{
	return display;
}

bool Player::get_impact()
{
	return playerBox->getColli();
}

void Player::set_impact(bool imp)
{
	playerBox->setColli(imp);
}

void Player::move_left(int background_Color) //dthien
{

	Draw(false, background_Color);
	int temp = get_position().getX() - get_Hspeed();
	set_position(temp > 1 ? temp : 1, get_position().getY());
	Draw(true, background_Color);
}

void Player::move_right(int background_Color) //dthien
{
	Draw(false, background_Color);
	int temp = get_position().getX() + get_Hspeed();
	set_position(temp < CONSOLE_WIDTH - 4 ? temp : CONSOLE_WIDTH - 4, get_position().getY());
	Draw(true, background_Color);
}

void Player::move_up(vector<Lane*> lanelist) //dthien
{
	int lane = get_position().getY();
	int down = lane / 4 + 1;
	if (down >= lanelist.size()) down = lanelist.size() - 1;
	int up = lane / 4 - 1;
	if (up < 0) up = 0;
	Draw(false, lanelist[lane/4]->get_backgroundCoLor());
	int temp = get_position().getY() - get_Vspeed();
	set_position(get_position().getX(), temp > 1 ? temp : 1);
	Draw(true, lanelist[up]->get_backgroundCoLor());
}

void Player::move_down(vector<Lane*> lanelist) //dthien
{
	int lane = get_position().getY();
	int down = lane / 4 + 1;
	if (down >= lanelist.size()) down = lanelist.size() - 1;
	int up = lane / 4 - 1;
	if (up < 0) up = 0;
	Draw(false, lanelist[lane/4]->get_backgroundCoLor());
	int temp = get_position().getY() + get_Vspeed();
	set_position(get_position().getX(), temp < CONSOLE_HEIGHT - 1 ? temp : CONSOLE_HEIGHT - 1);
	Draw(true, lanelist[down]->get_backgroundCoLor());
}

bool Player::move_player(vector<Lane*> lanelist) //dthien
{
	int lane = get_position().getY();
	int down = lane / 4 + 1;
	if (down >= lanelist.size()) down = lanelist.size() - 1;
	int up = lane / 4 - 1;
	if (up < 0) up = 0;
	switch (Basic::getKeyInput())
	{
	case 1:
		move_up(lanelist); 
		return true;
	case 2:
		move_left(lanelist[lane / 4]->get_backgroundCoLor()); 
		return true;
	case 3:
		move_down(lanelist); 
		return true;
	case 4:
		move_right(lanelist[lane / 4]->get_backgroundCoLor()); 
		return true;
	default: break; return false;
	}
}



void Player::Draw(bool mode, int background_Color) //dthien
{
	switch (type)
	{
	case PEROT:
		UserInterface::DrawParrot(get_position().getX(), get_position().getY(), mode, background_Color); break;
	case PENGUIN:
		UserInterface::DrawPenguin(get_position().getX(), get_position().getY(), mode, background_Color); break;
	case CHICK:
		UserInterface::DrawChicken(get_position().getX(), get_position().getY(), mode, background_Color); break;
	case BEE:
		UserInterface::DrawBee(get_position().getX(), get_position().getY(), mode, background_Color); break;
	case DOGO:
		UserInterface::DrawDog(get_position().getX(), get_position().getY(), mode, background_Color); break;
	default:break;
	}
}

