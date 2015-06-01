#pragma once

#include "scene.h"

#include <HL/hl.h>

#include <HDU/hduMatrix.h>
#include <HDU/hduError.h>

#include <HLU/hlu.h>

#include <vector>

typedef struct Face
{
	HLuint ID;
	GLuint displayList;
} Face;

class PhantomOMNIScene_1_h_1_cube : public Scene
{
private:
	HHD ghHD1;
	HHD ghHD2;
	HHLRC ghHLRC1;
	HHLRC ghHLRC2;

	//HLuint gMyShapeId;
	std::vector<Face> faces;

	static const int cursor_size_pixels = 25;
	double gCursorScale;
	GLuint gCursorDisplayList;
	GLuint gCubeDisplayList;

	static bool rotateCube;
	static voxelengine::Vector3 amountOfRot;

	static voxelengine::Vector3 cube1rot;
	static voxelengine::Vector3 touchPos;
	static voxelengine::Vector3 releasePos;

	static bool bBtn1Down;
public:
	PhantomOMNIScene_1_h_1_cube(OpenGLRenderer *renderer);
	~PhantomOMNIScene_1_h_1_cube();

	void initGL();

	void initHD(HDstring pConfigName, HHD &ghHD);
	void initHL(HHD hHD, HHLRC &hHLRC);

	void updateWorkspace();

	void drawCursor(voxelengine::Vector3 color);

	static void HLCALLBACK touchShapeCallback(HLenum event, HLuint object, HLenum thread, HLcache *cache, void* userdata);
	static void HLCALLBACK untouchShapeCallback(HLenum event, HLuint object, HLenum thread, HLcache *cache, void *userdata);

	static void HLCALLBACK touchCubeCallback(HLenum event, HLuint object, HLenum thread, HLcache *cache, void *userdata);
	static void HLCALLBACK untouchCubeCallback(HLenum event, HLuint object, HLenum thread, HLcache *cache, void *userdata);

	static void HLCALLBACK button1down(HLenum event, HLuint object, HLenum thread, HLcache *cache, void *userdata);
	static void HLCALLBACK button1up(HLenum event, HLuint object, HLenum thread, HLcache *cache, void *userdata);

	static void HLCALLBACK button1downoncube(HLenum event, HLuint object, HLenum thread, HLcache *cache, void *userdata);
	static void HLCALLBACK button1uponcube(HLenum event, HLuint object, HLenum thread, HLcache *cache, void *userdata);

	void drawSceneHaptics(HLuint shapeid);

	void resize(int w, int h);
	void Update(float dt);
	void Render();

	void createFaces();

	void free();
};

