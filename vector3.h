#pragma once

#include <math.h>

namespace voxelengine
{
	
	class Vector3
	{
	public:
		Vector3();
		Vector3(float x, float y, float z);
		~Vector3();

		float x;
		float y;
		float z;
		
		static float distance(voxelengine::Vector3 v1, voxelengine::Vector3 v2);
	};
}

