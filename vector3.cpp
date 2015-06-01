#include "vector3.h"


/*
Vector3::Vector3()

Purpose: Constructor. Initializes x,y,z to zero.

*/
voxelengine::Vector3::Vector3()
{
	x = y = z = 0;
}

/*
Vector3::Vector3(float x, float y, float z)

Purpose: Constructor. Initializes x,y,z to specified parameters

Parameters: float x: specified X axis value
			float y: specified Y axis value
			float z: specified Z axis value

*/
voxelengine::Vector3::Vector3(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

/*
Vector3::distance(Vector3 v1, Vector3 v2)

Purpose: Finds distance between 2 vectors in 3D space
		using basic pythagorean theorem

Note: Since this function is built around pythagorean theorem, sqrt is used (heavy operation)
*/
float voxelengine::Vector3::distance(voxelengine::Vector3 v1, voxelengine::Vector3 v2)
{
	float dx = v2.x - v1.x;
	float dy = v2.y - v1.y;
	float dz = v2.z - v1.z;

	return sqrt((float)(dx * dx + dy * dy + dz * dz));
}


voxelengine::Vector3::~Vector3()
{
}
