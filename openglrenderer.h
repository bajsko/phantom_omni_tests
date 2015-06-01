/*
//# OpenGLRenderer
// My own OpenGL rendering utility
// Originally intended for my voxel game,
// but worked perfectly in this project aswell.


// Thanks to AlwaysGeeky and NeHe for their awesome articles about both
// game programming and opengl programming in general.


//Author: Klas.
*/


#pragma once

#include <SFML/OpenGL.hpp>
#include <GL\glut.h>
#include <math.h>
#include "vector3.h"

#define PI 3.1415926535897932384626433832795

enum RM_MODE
{
	RM_VERTEX_ARRAY = 0,
	RM_VBO,
	RM_VAO,
};

enum IM_MODE
{
	IM_QUADS = 0,
	IM_TRIANGLES,
	IM_LINES,
	IM_POINTS
};

struct VideoSettings
{
	bool m_depth;
	int m_width;
	int m_height;
	float m_aspect;
};

struct OGL_Color
{
	float r;
	float g;
	float b;
	float a;
};

enum OGL_MatrixMode
{
	OGL_Projection,
	OGL_Modelview,
};


class OpenGLRenderer
{
private:
	VideoSettings videoMode;

	void OGLPerspective(float fovy, float aspect, float zNear, float zFar);
	void OGLOrtho(float left, float right, float bottom, float top, float znear, float zfar);

public:
	OpenGLRenderer(void);
	OpenGLRenderer(int width, int height);
	~OpenGLRenderer(void);

	void InitRenderer();

	void SetPerspective(float deg, float aspect, float zNear, float zFar);
	void SetOrtho(float l, float r, float b, float t, float znear, float zfar);

	void PushMatrix();
	void PopMatrix();

	void PreRender();

	void BeginImmediateMode(IM_MODE mode);
	void EndImmediateMode();

	void EnableWireframe();
	void DisableWireframe();

	void TranslateWorldMatrix(float x, float y, float z);
	void RotateWorldMatrix(float deg, float x, float y, float z);

	void SetViewport(int w, int h);

	void ImmediateVertex(float x, float y, float z);
	void ImmediateColor(float r, float g, float b);
	void ImmediateColorAlpha(float r, float g, float b, float a);
	void ImmediateNormal(float x, float y, float z);

	void glImmediateCube(float size);
	void glImmediateCube(float size, voxelengine::Vector3 front, voxelengine::Vector3 back, voxelengine::Vector3 top, voxelengine::Vector3 bottom, voxelengine::Vector3 left, voxelengine::Vector3 right);

	void SetMatrixMode(OGL_MatrixMode mode);

	void Dispose();

};

