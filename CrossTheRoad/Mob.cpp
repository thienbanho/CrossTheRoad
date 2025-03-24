#include "Mob.h"

Mob::Mob()
{
	mobBox = nullptr;
	type = speed = delay = 0;
	status = display = false;
}

Mob::Mob(Point2D pos, int mob_type, int spd, int dly)
{
	if (mob_type < RED_CAR || mob_type > SHARK) *this = Mob();
	else {
		type = mob_type;
		delay = dly;
		speed = spd;
		status = true;
		display = true;
		mobBox = new Hitbox(pos, MobWidth[type], MobHeight[type], Hitbox::Hitbox::ShowHitbox::on, Hitbox::HitboxType::mob, false);
	}
}

Mob::Mob(const Mob& other)
{
	type = other.type;
	speed = other.speed;
	delay = other.delay;
	status = other.status;
	display = other.display;
	mobBox = new Hitbox(other.mobBox->getUpLeft(), MobWidth[type],MobHeight[type], Hitbox::Hitbox::ShowHitbox::on, Hitbox::HitboxType::mob, false);
}

Mob& Mob::operator=(const Mob& other)
{
	if (this != &other)
	{
		this->type = other.type;
		this->speed = other.speed;
		this->delay = other.delay;
		this->status = other.status;
		this->display = other.display;
		if (this->mobBox != nullptr)
			delete mobBox;
		mobBox = new Hitbox(other.mobBox->getUpLeft(), MobWidth[type], MobHeight[type], Hitbox::Hitbox::ShowHitbox::on, Hitbox::HitboxType::mob, false);
	}
	return *this;
}

Mob::~Mob()
{
	if (mobBox)
	{
		delete mobBox;
		mobBox = nullptr;
	}
}

void Mob::set_position(int px, int py)
{
	mobBox->setUpLeft(Point2D(px, py));
}

Point2D Mob::get_position()
{
	return mobBox->getUpLeft();
}

void Mob::set_status(bool st)
{
	status = st;
}

bool Mob::get_status()
{
	return status;
}

void Mob::set_type(int t)
{
	type = t;
}

int Mob::get_type()
{
	return type;
}

void Mob::set_height(int height)
{
	mobBox->setHeight(height);
}

int Mob::get_height()
{
	return mobBox->getHeight();
}

void Mob::set_width(int width)
{
	mobBox->setWidth(width);
}

int Mob::get_width()
{
	return mobBox->getWidth();
}

void Mob::set_size(int width, int height)
{
	mobBox->setWidth(width);
	mobBox->setHeight(height);
}

void Mob::set_delay(int newDly)
{
	delay = newDly;
}

int Mob::get_delay()
{
	return delay;
}

void Mob::set_speed(int spd)
{
	speed = spd;
}

int Mob::get_speed()
{
	return speed;
}

void Mob::set_display(bool d)
{
	display = d;
}

bool Mob::get_display(bool)
{
	return display;
}

Hitbox* Mob::get_hitbox()
{
	return mobBox;
}

void Mob::move_left()
{
	set_position(mobBox->getUpLeft().getX() - speed, mobBox->getUpLeft().getY());
}

void Mob::move_right()
{
	int count = speed;
	do
	{
		int temp = (mobBox->getUpLeft().getX()) % (CONSOLE_WIDTH - 6 + 9) + 1;
		set_position(temp, mobBox->getUpLeft().getY());
		Draw_Right(1);
		Basic::sleepFor_milisec(delay);
	} while (count--);
	//Basic::sleepFor_milisec(delay);
}

void Mob::Draw_Right(bool mode)
{
	UserInterface::DrawVehicle_Right(type, get_position().getX(), get_position().getY(), mode, WHITE, MobLane[type]);
}
