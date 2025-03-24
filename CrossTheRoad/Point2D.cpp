#include "Point2D.h"
Point2D::Point2D()
{
	x = 0;
	y = 0;
}

Point2D::Point2D(int px, int py)
{
	x = px;
	y = py;
}

void Point2D::set(int px, int py)
{
	x = px;
	y = py;
}

int Point2D::getX()
{
	return x;
}

int Point2D::getY()
{
	return y;
}
