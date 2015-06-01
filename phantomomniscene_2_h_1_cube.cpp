#include  "phantomoniscene_2_h_1_cube.h"

//cube 1 rot
voxelengine::Vector3 PhantomOMNIScene_2_h_1_cube::cube1rot = voxelengine::Vector3(0, 0, 0);
//Is bbtn 1 pressed on ANY device?
bool PhantomOMNIScene_2_h_1_cube::bBtn1Down = false;

voxelengine::Vector3 PhantomOMNIScene_2_h_1_cube::amountOfRot;

bool PhantomOMNIScene_2_h_1_cube::rotateCube = false;

//stores first touch position (touches the cube)
voxelengine::Vector3 PhantomOMNIScene_2_h_1_cube::touchPos = voxelengine::Vector3(0, 0, 0);
//stores release position
voxelengine::Vector3 PhantomOMNIScene_2_h_1_cube::releasePos = voxelengine::Vector3(0, 0, 0);

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////
PhantomOMNIScene_2_h_1_cube::touchShapeCallback(HLenum event, HLuint object, HLenum thread, HLcache *cache, void* userdata)

Purpose: called when phantom touches a shape.
notifies user of interaction.

Parameters: HLenum event: what happened?
HLuint object: object ID
HLenum thread: what thread this callback is running on
HLcache *cache: cache data
void* userdata: NULL for now.

*////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void HLCALLBACK PhantomOMNIScene_2_h_1_cube::touchShapeCallback(HLenum event, HLuint object, HLenum thread, HLcache *cache, void* userdata)
{
	printf("Touched shape with ID %d\n", object);
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////
PhantomOMNIScene_2_h_1_cube::untouchShapeCallback(HLenum event, HLuint object, HLenum thread, HLcache *cache, void* userdata)

Purpose: called when phantom untouches a shape.
notifies user of interaction.

Parameters: HLenum event: what happened?
HLuint object: object ID
HLenum thread: what thread this callback is running on
HLcache *cache: cache data
void* userdata: NULL for now.

*////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void HLCALLBACK PhantomOMNIScene_2_h_1_cube::untouchShapeCallback(HLenum event, HLuint object, HLenum thread, HLcache *cache, void* userdata)
{
	printf("Uouched shape with ID %d\n", object);
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////
PhantomOMNIScene_2_h_1_cube::touchCubeCallback(HLenum event, HLuint object, HLenum thread, HLcache *cache, void* userdata)

Purpose: called when phantom touches the cube.
notifies user of interaction and stores
pen position in touchPos

Parameters: HLenum event: what happened?
HLuint object: object ID
HLenum thread: what thread this callback is running on
HLcache *cache: cache data
void* userdata: NULL for now.

*////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void HLCALLBACK PhantomOMNIScene_2_h_1_cube::touchCubeCallback(HLenum event, HLuint object, HLenum thread, HLcache *cache, void* userdata)
{
	printf("Touched CUBE with ID %d\n", object);

	hduVector3Dd proxypos;
	hlCacheGetDoublev(cache, HL_PROXY_POSITION, proxypos);
	touchPos = voxelengine::Vector3(proxypos[0], proxypos[1], proxypos[2]);

	//printf("touchPos POS: %f\n", touchPos.x);
	//rot = true;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////
PhantomOMNIScene_2_h_1_cube::untouchCubeCallback(HLenum event, HLuint object, HLenum thread, HLcache *cache, void* userdata)

Purpose: called when phantom untouches the cube.
notifies user of interaction, stores
untouch pos in releasePos and then
calculates rotation of cube based on pen movement.
if distance < 0.21, rotation on all axises is set to zero.

Parameters: HLenum event: what happened?
HLuint object: object ID
HLenum thread: what thread this callback is running on
HLcache *cache: cache data
void* userdata: NULL for now.

*////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void HLCALLBACK PhantomOMNIScene_2_h_1_cube::untouchCubeCallback(HLenum event, HLuint object, HLenum thread, HLcache *cache, void* userdata)
{
	printf("Unouched CUBE with ID %d\n", object);

	hduVector3Dd proxypos;
	hlCacheGetDoublev(cache, HL_PROXY_POSITION, proxypos);

	releasePos = voxelengine::Vector3(proxypos[0], proxypos[1], proxypos[2]);
	voxelengine::Vector3 diff = voxelengine::Vector3((releasePos.x - touchPos.x), (releasePos.y - touchPos.y), (releasePos.z - touchPos.z));

	float distance = voxelengine::Vector3::distance(releasePos, touchPos);

	if (distance < 0.21f)
	{
		amountOfRot.x = 0;
		amountOfRot.y = 0;
		amountOfRot.z = 0;
		return;
	}
	amountOfRot.x = diff.x;
	amountOfRot.y += -1.0f * (diff.y);
	amountOfRot.z += diff.z;
	rotateCube = true;

}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////
PhantomOMNIScene_holo::touchCube2Callback(HLenum event, HLuint object, HLenum thread, HLcache *cache, void* userdata)

Purpose: called when phantom untouches the cube.
notifies user of interaction, stores
untouch pos in releasePos and then
calculates rotation of cube based on pen movement.
if distance < 0.21, rotation on all axises is set to zero.

Parameters: HLenum event: what happened?
HLuint object: object ID
HLenum thread: what thread this callback is running on
HLcache *cache: cache data
void* userdata: NULL for now.

*////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*void HLCALLBACK PhantomOMNIScene_holo::touchCube2Callback(HLenum event, HLuint object, HLenum thread, HLcache *cache, void *userdata)
{
printf("Touched CUBE with ID %d\n", object);

hduVector3Dd proxypos;
hlCacheGetDoublev(cache, HL_PROXY_POSITION, proxypos);
touchPos = voxelengine::Vector3(proxypos[0], proxypos[1], proxypos[2]);

//printf("touchPos POS: %f\n", touchPos.x);
//rot = true;
}*/

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////
PhantomOMNIScene_holo::untouchCube2Callback(HLenum event, HLuint object, HLenum thread, HLcache *cache, void* userdata)

Purpose: called when phantom untouches the cube.
notifies user of interaction, stores
untouch pos in releasePos and then
calculates rotation of cube based on pen movement.
if distance < 0.21, rotation on all axises is set to zero.

Parameters: HLenum event: what happened?
HLuint object: object ID
HLenum thread: what thread this callback is running on
HLcache *cache: cache data
void* userdata: NULL for now.

*////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*void HLCALLBACK PhantomOMNIScene_holo::untouchCube2Callback(HLenum event, HLuint object, HLenum thread, HLcache *cache, void *userdata)
{
printf("Unouched CUBE with ID %d\n", object);

hduVector3Dd proxypos;
hlCacheGetDoublev(cache, HL_PROXY_POSITION, proxypos);

releasePos = voxelengine::Vector3(proxypos[0], proxypos[1], proxypos[2]);
voxelengine::Vector3 diff = voxelengine::Vector3((releasePos.x - touchPos.x), (releasePos.y - touchPos.y), (releasePos.z - touchPos.z));

float distance = voxelengine::Vector3::distance(releasePos, touchPos);

if (distance < 0.21f)
{
cube1rot.x = 0;
cube1rot.y = 0;
cube1rot.z = 0;

return;
}

cube1rot.x = diff.x / 2;
cube1rot.y = -1.0f * (diff.y / 2);
cube1rot.z = diff.z / 2;
}*/

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////
PhantomOMNIScene_holo::button1down(HLenum event, HLuint object, HLenum thread, HLcache *cache, void* userdata)

Purpose: notifices user when button 1 is down.
and swaps bBtn1Down' value.

Parameters: HLenum event: what happened?
HLuint object: object ID
HLenum thread: what thread this callback is running on
HLcache *cache: cache data
void* userdata: NULL for now.

*////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void HLCALLBACK PhantomOMNIScene_2_h_1_cube::button1down(HLenum event, HLuint object, HLenum thread, HLcache *cache, void *userdata)
{
	printf("Button 1 down\n");
	bBtn1Down = !bBtn1Down;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////
PhantomOMNIScene_holo::button1up(HLenum event, HLuint object, HLenum thread, HLcache *cache, void* userdata)

Purpose: notifices user when button 1 is up.
and swaps bBtn1Down's value.

Parameters: HLenum event: what happened?
HLuint object: object ID
HLenum thread: what thread this callback is running on
HLcache *cache: cache data
void* userdata: NULL for now.

*////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void HLCALLBACK PhantomOMNIScene_2_h_1_cube::button1up(HLenum event, HLuint object, HLenum thread, HLcache *cache, void *userdata)
{
	printf("Bacon 1 up\n");
	bBtn1Down = !bBtn1Down;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////
PhantomOMNIScene_2_h_1_cube::button1downoncube(HLenum event, HLuint object, HLenum thread, HLcache *cache, void* userdata)

Purpose: notifices user when button 1 is down and touching cube.

Parameters: HLenum event: what happened?
HLuint object: object ID
HLenum thread: what thread this callback is running on
HLcache *cache: cache data
void* userdata: NULL for now.

*////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void HLCALLBACK PhantomOMNIScene_2_h_1_cube::button1downoncube(HLenum event, HLuint object, HLenum thread, HLcache *cache, void *userdata)
{
	printf("Button 1 down on CUBE\n");
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////
PhantomOMNIScene_2_h_1_cube::button1uponcube(HLenum event, HLuint object, HLenum thread, HLcache *cache, void* userdata)

Purpose: notifices user when button 1 is up and touching cube.

Parameters: HLenum event: what happened?
HLuint object: object ID
HLenum thread: what thread this callback is running on
HLcache *cache: cache data
void* userdata: NULL for now.

*////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void HLCALLBACK PhantomOMNIScene_2_h_1_cube::button1uponcube(HLenum event, HLuint object, HLenum thread, HLcache *cache, void *userdata)
{
	printf("Btton 1 up on CUBE\n");
}

PhantomOMNIScene_2_h_1_cube::PhantomOMNIScene_2_h_1_cube(OpenGLRenderer *renderer) : Scene(renderer)
{
	gCursorDisplayList = 0;
	gCubeDisplayList = 0;
	initGL();

	initHD("PHANToM 1", ghHD1);
	initHD("PHANToM 2", ghHD2);

	initHL(ghHD1, ghHLRC1);
	initHL(ghHD2, ghHLRC2);

	printf("Generated shape id: %d\n", gMyShapeId);

	hlMakeCurrent(ghHLRC1);
	updateWorkspace();
	hlMakeCurrent(ghHLRC2);
	updateWorkspace();
}

/*//////////////////////////////////////////////////////////////////////////////
PhantomOMNIScene_holo::updateWorkspace()

Purpose: Updates Haptic IRL workspace to fit projection,
then calculates cursor scale.

Note: Don't forget to call hlMakeCurrent() if you wish to change current device.
*////////////////////////////////////////////////////////////////////////////////
void PhantomOMNIScene_2_h_1_cube::updateWorkspace()
{
	GLdouble projection[16];
	GLdouble modelview[16];
	GLint viewport[4];

	glGetDoublev(GL_PROJECTION_MATRIX, projection);
	glGetDoublev(GL_MODELVIEW_MATRIX, modelview);
	glGetIntegerv(GL_VIEWPORT, viewport);

	hlMatrixMode(HL_TOUCHWORKSPACE);
	hlLoadIdentity();

	hluFitWorkspace(projection);

	gCursorScale = hluScreenToModelScale(modelview, projection, viewport);
	gCursorScale *= cursor_size_pixels;
}

void PhantomOMNIScene_2_h_1_cube::resize(int w, int h)
{


}


PhantomOMNIScene_2_h_1_cube::~PhantomOMNIScene_2_h_1_cube()
{
}

void PhantomOMNIScene_2_h_1_cube::initGL()
{
	static const GLfloat light_model_ambient[] = { 0.3f, 0.3f, 0.3f, 1.0f };
	static const GLfloat light0_diffuse[] = { 0.9f, 0.9f, 0.9f, 0.9f };
	static const GLfloat light0_direction[] = { 0.0f, -0.4f, 1.0f, 0.0f };

	// Cull back faces.

	// Setup other misc features.
	glEnable(GL_LIGHTING);
	glEnable(GL_NORMALIZE);
	glShadeModel(GL_SMOOTH);

	// Setup lighting model.
	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_FALSE);
	glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, light_model_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diffuse);
	glLightfv(GL_LIGHT0, GL_POSITION, light0_direction);
	glEnable(GL_LIGHT0);

	static const double kFovY = 40;

	double nearDist, farDist, aspect;

	glViewport(0, 0, RES_W, RES_H);

	nearDist = 1.0 / tan((kFovY / 2.0) * PI / 180.0) + 0.8f;
	farDist = nearDist + 4.0;
	aspect = (double)RES_W / RES_H;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(kFovY, aspect, nearDist, farDist);

	// Place the camera down the Z axis looking at the origin.
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0, 0, nearDist + 1.2,
		0, 0, 0,
		0, 1, 0);
}

void PhantomOMNIScene_2_h_1_cube::initHD(HDstring pConfigName, HHD &ghHD)
{
	HDErrorInfo error;
	ghHD = hdInitDevice(pConfigName);
	if (HD_DEVICE_ERROR(error = hdGetError()))
	{
		hduPrintError(stderr, &error, "Failed to initialize haptic device");
		fprintf(stderr, "Press any key to exit");
		getchar();
		exit(-1);
	}

	printf("Initiated haptic device with serial: %s\n", hdGetString(HD_DEVICE_SERIAL_NUMBER));
}

void PhantomOMNIScene_2_h_1_cube::initHL(HHD hHD, HHLRC &hHLRC)
{
	hHLRC = hlCreateContext(hHD);
	hlMakeCurrent(hHLRC);

	hlEnable(HL_HAPTIC_CAMERA_VIEW);

	hlTouchableFace(HL_FRONT);
	gMyShapeId = hlGenShapes(1);

	hlAddEventCallback(HL_EVENT_TOUCH, HL_OBJECT_ANY, HL_CLIENT_THREAD, &touchShapeCallback, NULL);
	hlAddEventCallback(HL_EVENT_UNTOUCH, HL_OBJECT_ANY, HL_CLIENT_THREAD, &untouchShapeCallback, NULL);

	hlAddEventCallback(HL_EVENT_1BUTTONDOWN, HL_OBJECT_ANY, HL_CLIENT_THREAD, &button1down, NULL);
	hlAddEventCallback(HL_EVENT_1BUTTONUP, HL_OBJECT_ANY, HL_CLIENT_THREAD, &button1up, NULL);
	hlAddEventCallback(HL_EVENT_1BUTTONDOWN, gMyShapeId, HL_CLIENT_THREAD, &button1downoncube, NULL);
	hlAddEventCallback(HL_EVENT_1BUTTONUP, gMyShapeId, HL_CLIENT_THREAD, &button1uponcube, NULL);
	hlAddEventCallback(HL_EVENT_TOUCH, gMyShapeId, HL_CLIENT_THREAD, &touchCubeCallback, NULL);
	hlAddEventCallback(HL_EVENT_UNTOUCH, gMyShapeId, HL_CLIENT_THREAD, &untouchCubeCallback, NULL);
}

/*////////////////////////////////////////////////////////////////////////////
PhantomOMNIScene_2_h_1_cube::Update(float dt)

Purpose: Checks for haptic device(s) error
and also enables camera movability (not used)
also updates rotations on all 4 (haptically 5) cubes

Parameters: float dt: time passed since last update (in Seconds) (not used)

*//////////////////////////////////////////////////////////////////////////////
void PhantomOMNIScene_2_h_1_cube::Update(float dt)
{

	HLerror error;

	while (HL_ERROR(error = hlGetError()))
	{
		fprintf(stderr, "HL Error: %s\n", error.errorCode);

		if (error.errorCode == HL_DEVICE_ERROR)
		{
			hduPrintError(stderr, &error.errorInfo,
				"Error during haptic rendering\n");
		}
	}

	if (rotateCube)
	{

		if (cube1rot.x > 360)
			cube1rot.x = 0;
		if (cube1rot.y > 360)
			cube1rot.y = 0;
		if (cube1rot.z > 360)
			cube1rot.z = 0;

		cube1rot.x += amountOfRot.x;
		cube1rot.y += amountOfRot.y;
		cube1rot.z += amountOfRot.z;
	}
}

/*/////////////////////////////////////////////////////////////////////
PhantomOMNIScene_2_h_1_cube::drawCursor(Vector3 color)

Purpose: draws the pens position as a sphere with specified color
also scales down cursor to specified gCursorScale.
draws via GLUT

Parameters: Vector3 color: RGB color components that range from 0 to 1 (x=r, y=g, z=b)

Make sure to call hlMakeCurrent to setup correct device.
*/////////////////////////////////////////////////////////////////////
void PhantomOMNIScene_2_h_1_cube::drawCursor(voxelengine::Vector3 color)
{
	static const double kCursorRadius = 0.5;
	static const double kCursorHeight = 1.5;
	static const int kCursorTess = 1000;
	HLdouble proxyxform[16];

	GLUquadricObj *qobj = 0;

	glPushAttrib(GL_CURRENT_BIT | GL_ENABLE_BIT | GL_LIGHTING_BIT);
	glPushMatrix();

	if (!gCursorDisplayList)
	{
		gCursorDisplayList = glGenLists(1);
		glNewList(gCursorDisplayList, GL_COMPILE);
		qobj = gluNewQuadric();

		gluSphere(qobj, 0.5f, kCursorTess, kCursorTess);

		gluDeleteQuadric(qobj);
		glEndList();
	}

	// Get the proxy transform in world coordinates.
	hlGetDoublev(HL_PROXY_TRANSFORM, proxyxform);
	glMultMatrixd(proxyxform);

	// Apply the local cursor scale factor.
	glScaled(gCursorScale, gCursorScale, gCursorScale);

	glEnable(GL_COLOR_MATERIAL);
	m_renderer->ImmediateColor(color.x, color.y, color.z);

	glCallList(gCursorDisplayList);

	glPopMatrix();
	glPopAttrib();
}

/*/////////////////////////////////////
PhantomOMNIScene_holo::drawSceneHaptics()

Purpose: Sets upp material data (HL_STIFFNESS, HL_DAMPING, HL_STATIC_FRICTION, HL_DYNAMIC_FRCTION)
then draws gMyShape to the haptic device(s).
also checks for events.

*///////////////////////////////////////
void PhantomOMNIScene_2_h_1_cube::drawSceneHaptics(HLuint shapeid)
{
	hlBeginFrame();

	hlMaterialf(HL_FRONT_AND_BACK, HL_STIFFNESS, 1.0f);
	hlMaterialf(HL_FRONT_AND_BACK, HL_DAMPING, 1.0f);
	hlMaterialf(HL_FRONT_AND_BACK, HL_STATIC_FRICTION, 0.2f);
	hlMaterialf(HL_FRONT_AND_BACK, HL_DYNAMIC_FRICTION, 0.3f);

	hlBeginShape(HL_SHAPE_FEEDBACK_BUFFER, shapeid);

	//glRotatef(45, 0, 1, 0);
	glutSolidCube(1);

	hlEndShape();

	hlEndFrame();

	hlCheckEvents();
}


void PhantomOMNIScene_2_h_1_cube::Render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	glRotatef(cube1rot.x, 0, 1, 0);
	glRotatef(cube1rot.y, 1, 0, 0);
	glRotatef(cube1rot.z, 0, 0, 1);

	hlMakeCurrent(ghHLRC1);
	drawSceneHaptics(gMyShapeId);
	hlMakeCurrent(ghHLRC2);
	drawSceneHaptics(gMyShapeId);

	hlMakeCurrent(ghHLRC1);
	drawCursor(voxelengine::Vector3(1, 1, 1));

	hlMakeCurrent(ghHLRC2);
	drawCursor(voxelengine::Vector3(1, 1, 1));
	glPopMatrix();

	glPushMatrix();
	glRotatef(cube1rot.x, 0, 1, 0);
	glRotatef(cube1rot.y, 1, 0, 0);
	glRotatef(cube1rot.z, 0, 0, 1);

	glPushAttrib(GL_CURRENT_BIT | GL_ENABLE_BIT | GL_LIGHTING_BIT);
	glEnable(GL_COLOR_MATERIAL);

	if (!gCubeDisplayList)
	{
		gCubeDisplayList = glGenLists(1);

		glNewList(gCubeDisplayList, GL_COMPILE);
		m_renderer->glImmediateCube(1.0f);
		glEndList();
	}
	glCallList(gCubeDisplayList);
	glPopAttrib();
	glPopMatrix();
}

void PhantomOMNIScene_2_h_1_cube::free()
{

}