/*
TODO: Make this class useable.
*/

#include "camera.h"


Camera::Camera()
{
	x = 0;
	y = 0;
	z = 0;
	yaw = 0;
	pitch = 0;
}


Camera::~Camera()
{
}

void Camera::moveCamera(float dist, float dir)
{
	float rad = (yaw + dir) * PI / 180.0f;
	x -= sin(rad) * dist;
	z -= cos(rad) * dist;
}

void Camera::control()
{
	float movevel = 0.001f;

	if (keys[22]) //w
	{
		moveCamera(movevel, 0);
	}

	if (keys[18]) //s
	{
		moveCamera(movevel, 180);
	}

	if (keys[3]) //d
	{
		moveCamera(movevel, -90);
	}

	if (keys[0]) //a
	{
		moveCamera(movevel, 90);
	}

	if (keys[71])
	{
		yaw -= 0.00001f;
	}
	
	if (keys[72])
	{
		yaw += 0.000001f;
	}
}

void Camera::update()
{
	/*glRotatef(-yaw, 1, 0, 0);
	glRotatef(-pitch, 0, 1, 0);*/
	glTranslatef(-x, -y, -z);
}