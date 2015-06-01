#pragma once

#include "scene.h"
#include "vector3.h"
#include "camera.h"
#include <HL/hl.h>

#include <HDU/hduMatrix.h>
#include <HDU/hduError.h>

#include <HLU/hlu.h>

#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <Windows.h>

class PhantomOMNIScene_holo : public Scene
{
private:
	HHD ghHD1;
	HHD ghHD2;

	HHLRC ghHLRC1;
	HHLRC ghHLRC2;

	HLuint gMyShapeId, gMyShapeId2;

	static const int cursor_size_pixels = 25;
	double gCursorScale;
	GLuint gCursorDisplayList;
	GLuint gCubeDisplayList;

	Camera *camera;

	bool lockXAxis;
	bool lockYAxis;
	bool lockZAxis;

	bool bDrawGrid;

	static bool rotateCubes;
	static voxelengine::Vector3 amountOfRot;

	static voxelengine::Vector3 cube1rot;
	static voxelengine::Vector3 cube2rot;

	static bool bBtn1Down;

	GLdouble m1[16], m2[16], m3[16], m4[16];

	static voxelengine::Vector3 touchPos;
	static voxelengine::Vector3 releasePos;

public:
	PhantomOMNIScene_holo(OpenGLRenderer *renderer);
	~PhantomOMNIScene_holo();

	void initGL();

	//depricated
	void initHL();

	void freeHL();
	//depricated
	void drawCursor();

	//depricated
	void drawSceneHaptics();

	void updateWorkspace();

	void resize(int w, int h);
	void Update(float dt);
	void Render();


	static void HLCALLBACK touchShapeCallback(HLenum event, HLuint object, HLenum thread, HLcache *cache, void* userdata);
	static void HLCALLBACK untouchShapeCallback(HLenum event, HLuint object, HLenum thread, HLcache *cache, void *userdata);

	static void HLCALLBACK touchCubeCallback(HLenum event, HLuint object, HLenum thread, HLcache *cache, void *userdata);
	static void HLCALLBACK untouchCubeCallback(HLenum event, HLuint object, HLenum thread, HLcache *cache, void *userdata);

	//static void HLCALLBACK touchCube2Callback(HLenum event, HLuint object, HLenum thread, HLcache *cache, void *userdata);
	//static void HLCALLBACK untouchCube2Callback(HLenum event, HLuint object, HLenum thread, HLcache *cache, void *userdata);

	static void HLCALLBACK button1down(HLenum event, HLuint object, HLenum thread, HLcache *cache, void *userdata);
	static void HLCALLBACK button1up(HLenum event, HLuint object, HLenum thread, HLcache *cache, void *userdata);

	static void HLCALLBACK button1downoncube(HLenum event, HLuint object, HLenum thread, HLcache *cache, void *userdata);
	static void HLCALLBACK button1uponcube(HLenum event, HLuint object, HLenum thread, HLcache *cache, void *userdata);

	void initHD(HDstring pConfigName, HHD &ghHD);
	void initHL(HHD hHD, HHLRC &hHLRC, HLuint &shapeid);
	void initHL(HHD hHD, HHLRC &hHLRC);
	void drawCursor(voxelengine::Vector3 color);

	void drawSceneHaptics(HLuint shapeid);

	void drawFaces();

	void drawGrid(float angle, float x, float y, float z);
	void drawGrid();

	void free();

	void toggleGrid();
	void toggleAxis();

	void drawHapticFaces();
};

