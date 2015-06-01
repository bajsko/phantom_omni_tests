
#pragma once
#include "openglrenderer.h"
#include "input.h"

class Camera
{
private:

	float pitch;
	float yaw;
public:
	Camera();
	~Camera();

	void moveCamera(float angle, float dir);
	void control();
	void update();
	float x;
	float y;
	float z;
};

