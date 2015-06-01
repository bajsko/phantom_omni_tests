#include "phantomomniscene_holo.h"

//cube 1 rot
voxelengine::Vector3 PhantomOMNIScene_holo::cube1rot = voxelengine::Vector3(0, 0, 0);
//cube 2 rot
voxelengine::Vector3 PhantomOMNIScene_holo::cube2rot = voxelengine::Vector3(0, 0, 0);

//Is bbtn 1 pressed on ANY device?
bool PhantomOMNIScene_holo::bBtn1Down = false;

voxelengine::Vector3 PhantomOMNIScene_holo::amountOfRot;

bool PhantomOMNIScene_holo::rotateCubes = false;

//stores first touch position (touches the cube)
voxelengine::Vector3 PhantomOMNIScene_holo::touchPos = voxelengine::Vector3(0, 0, 0);
//stores release position
voxelengine::Vector3 PhantomOMNIScene_holo::releasePos = voxelengine::Vector3(0, 0, 0);



/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////
PhantomOMNIScene_holo::touchShapeCallback(HLenum event, HLuint object, HLenum thread, HLcache *cache, void* userdata)

Purpose: called when phantom touches a shape.
notifies user of interaction.

Parameters: HLenum event: what happened?
HLuint object: object ID
HLenum thread: what thread this callback is running on
HLcache *cache: cache data
void* userdata: NULL for now.

*////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void HLCALLBACK PhantomOMNIScene_holo::touchShapeCallback(HLenum event, HLuint object, HLenum thread, HLcache *cache, void* userdata)
{
	printf("Touched shape with ID %d\n", object);
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////
PhantomOMNIScene_holo::untouchShapeCallback(HLenum event, HLuint object, HLenum thread, HLcache *cache, void* userdata)

Purpose: called when phantom untouches a shape.
notifies user of interaction.

Parameters: HLenum event: what happened?
HLuint object: object ID
HLenum thread: what thread this callback is running on
HLcache *cache: cache data
void* userdata: NULL for now.

*////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void HLCALLBACK PhantomOMNIScene_holo::untouchShapeCallback(HLenum event, HLuint object, HLenum thread, HLcache *cache, void* userdata)
{
	printf("Uouched shape with ID %d\n", object);
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////
PhantomOMNIScene_holo::touchCubeCallback(HLenum event, HLuint object, HLenum thread, HLcache *cache, void* userdata)

Purpose: called when phantom touches the cube.
notifies user of interaction and stores
pen position in touchPos

Parameters: HLenum event: what happened?
HLuint object: object ID
HLenum thread: what thread this callback is running on
HLcache *cache: cache data
void* userdata: NULL for now.

*////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void HLCALLBACK PhantomOMNIScene_holo::touchCubeCallback(HLenum event, HLuint object, HLenum thread, HLcache *cache, void* userdata)
{
	printf("Touched CUBE with ID %d\n", object);

	hduVector3Dd proxypos;
	hlCacheGetDoublev(cache, HL_PROXY_POSITION, proxypos);
	touchPos = voxelengine::Vector3(proxypos[0], proxypos[1], proxypos[2]);

	//printf("touchPos POS: %f\n", touchPos.x);
	//rot = true;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////
PhantomOMNIScene_holo::untouchCubeCallback(HLenum event, HLuint object, HLenum thread, HLcache *cache, void* userdata)

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
void HLCALLBACK PhantomOMNIScene_holo::untouchCubeCallback(HLenum event, HLuint object, HLenum thread, HLcache *cache, void* userdata)
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
	rotateCubes = true;

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
void HLCALLBACK PhantomOMNIScene_holo::button1down(HLenum event, HLuint object, HLenum thread, HLcache *cache, void *userdata)
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
void HLCALLBACK PhantomOMNIScene_holo::button1up(HLenum event, HLuint object, HLenum thread, HLcache *cache, void *userdata)
{
	printf("Bacon 1 up\n");
	bBtn1Down = !bBtn1Down;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////
PhantomOMNIScene_holo::button1downoncube(HLenum event, HLuint object, HLenum thread, HLcache *cache, void* userdata)

Purpose: notifices user when button 1 is down and touching cube.

Parameters: HLenum event: what happened?
HLuint object: object ID
HLenum thread: what thread this callback is running on
HLcache *cache: cache data
void* userdata: NULL for now.

*////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void HLCALLBACK PhantomOMNIScene_holo::button1downoncube(HLenum event, HLuint object, HLenum thread, HLcache *cache, void *userdata)
{
	printf("Button 1 down on CUBE\n");
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////
PhantomOMNIScene_holo::button1uponcube(HLenum event, HLuint object, HLenum thread, HLcache *cache, void* userdata)

Purpose: notifices user when button 1 is up and touching cube.

Parameters: HLenum event: what happened?
HLuint object: object ID
HLenum thread: what thread this callback is running on
HLcache *cache: cache data
void* userdata: NULL for now.

*////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void HLCALLBACK PhantomOMNIScene_holo::button1uponcube(HLenum event, HLuint object, HLenum thread, HLcache *cache, void *userdata)
{
	printf("Btton 1 up on CUBE\n");
}


/*//////////////////////////////////////////////////////////////
PhantomOMNIScene_holo::PhantomOMNIScene_holo(OpenGLRenderer *renderer)

Purpose: Constructor. Init renderer to scene,
creates camera object, resets gCursorDisplayList
and initializes both OGL and HL

Parameters: OpenGLRenderer *renderer: Active OGLRenderer
*//////////////////////////////////////////////////////////////
PhantomOMNIScene_holo::PhantomOMNIScene_holo(OpenGLRenderer *renderer) : Scene(renderer)
{
	lockXAxis = false;
	lockYAxis = false;
	lockZAxis = false;

	camera = new Camera();
	gCursorDisplayList = 0;
	gCubeDisplayList = 0;
	initGL();

	initHD("PHANToM 1", ghHD1);
	initHD("PHANToM 2", ghHD2);

	initHL(ghHD1, ghHLRC1, gMyShapeId);
	initHL(ghHD2, ghHLRC2, gMyShapeId2);

	printf("Generated shape id: %d\n", gMyShapeId);

	hlMakeCurrent(ghHLRC1);
	updateWorkspace();
	hlMakeCurrent(ghHLRC2);
	updateWorkspace();
}

/*//////////////////////////////////////////////////
PhantomOMNIScene_holo::initGL()

Purpose: Overwrites OpenGLRenderer->InitRenderer()
entirely with a new perspective projection
and shading/lighting

*////////////////////////////////////////////////////
void PhantomOMNIScene_holo::initGL()
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
	camera->z = nearDist + 1.0;


	glGetDoublev(GL_MODELVIEW_MATRIX, m2);
}

/*/////////////////////////////////////////////////////////////////
PhantomOMNIScene_holo::initHD(HDstring pConfigName, HHD &ghHD)

Purpose: initiates a HHD handle based on specified ConfigName
prints hdGetError() if error occured

Parameters: HDstring pConfigName: Haptic device to initialize
HHD &ghHD: handle to initialize.

Note: Make sure ConfigName is set up via the configuration utility.
*///////////////////////////////////////////////////////////////////
void PhantomOMNIScene_holo::initHD(HDstring pConfigName, HHD &ghHD)
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

/*////////////////////////////////////////////////////////////////////
PhantomOMNIScene_holo::initHL(HHD hHD, HHLRC &hHLRC, HLuint &shapeid)

Purpose: initiates specified HHLRC handle based on
specified HHD. Also fills shapeid with a generated id,
and adds callbacks.

Parameters: HHD hHD: HHD handle
HHLRC &hHLRC: HHLRC handle to initialize
HLuint &shapeid: shapeid to generate
*////////////////////////////////////////////////////////////////////
void PhantomOMNIScene_holo::initHL(HHD hHD, HHLRC &hHLRC, HLuint &shapeid)
{
	hHLRC = hlCreateContext(hHD);
	hlMakeCurrent(hHLRC);

	hlEnable(HL_HAPTIC_CAMERA_VIEW);

	hlTouchableFace(HL_FRONT);
	shapeid = hlGenShapes(1);

	hlAddEventCallback(HL_EVENT_TOUCH, HL_OBJECT_ANY, HL_CLIENT_THREAD, &touchShapeCallback, NULL);
	hlAddEventCallback(HL_EVENT_UNTOUCH, HL_OBJECT_ANY, HL_CLIENT_THREAD, &untouchShapeCallback, NULL);

	hlAddEventCallback(HL_EVENT_1BUTTONDOWN, HL_OBJECT_ANY, HL_CLIENT_THREAD, &button1down, NULL);
	hlAddEventCallback(HL_EVENT_1BUTTONUP, HL_OBJECT_ANY, HL_CLIENT_THREAD, &button1up, NULL);
	hlAddEventCallback(HL_EVENT_1BUTTONDOWN, gMyShapeId, HL_CLIENT_THREAD, &button1downoncube, NULL);
	hlAddEventCallback(HL_EVENT_1BUTTONUP, gMyShapeId, HL_CLIENT_THREAD, &button1uponcube, NULL);
	hlAddEventCallback(HL_EVENT_TOUCH, gMyShapeId, HL_CLIENT_THREAD, &touchCubeCallback, NULL);
	hlAddEventCallback(HL_EVENT_UNTOUCH, gMyShapeId, HL_CLIENT_THREAD, &untouchCubeCallback, NULL);
}

/*//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
PhantomOMNIScene_holo::initHL()

Purpose: Generates correct Haptic handles and initializes
all callbacks. Also generates gMyShapeId.

Depricated. Use initHD(initHL(HDstring pConfigName, HHD &ghHD) & HHD hHD, HHLRC &hHLRC, HLuint &shapeid) instead.

*////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void PhantomOMNIScene_holo::initHL()
{
	//HDErrorInfo error;

	/*ghHD = hdInitDevice(HD_DEFAULT_DEVICE);
	if (HD_DEVICE_ERROR(error = hdGetError()))
	{
	hduPrintError(stderr, &error, "Failed to init haptic device");
	fprintf(stderr, "Exit");
	exit(-1);
	}

	ghHLRC = hlCreateContext(ghHD);
	hlMakeCurrent(ghHLRC);

	hlEnable(HL_HAPTIC_CAMERA_VIEW);
	gMyShapeId = hlGenShapes(1);

	hlTouchableFace(HL_FRONT);
	updateWorkspace();

	hlAddEventCallback(HL_EVENT_TOUCH, HL_OBJECT_ANY, HL_CLIENT_THREAD, &touchShapeCallback, NULL);
	hlAddEventCallback(HL_EVENT_UNTOUCH, HL_OBJECT_ANY, HL_CLIENT_THREAD, &untouchShapeCallback, NULL);
	hlAddEventCallback(HL_EVENT_TOUCH, gMyShapeId, HL_CLIENT_THREAD, &touchCubeCallback, NULL);
	hlAddEventCallback(HL_EVENT_UNTOUCH, gMyShapeId, HL_CLIENT_THREAD, &untouchCubeCallback, NULL);
	hlAddEventCallback(HL_EVENT_1BUTTONDOWN, HL_OBJECT_ANY, HL_CLIENT_THREAD, &button1down, NULL);
	hlAddEventCallback(HL_EVENT_1BUTTONUP,  HL_OBJECT_ANY, HL_CLIENT_THREAD, &button1up, NULL);
	hlAddEventCallback(HL_EVENT_1BUTTONDOWN, gMyShapeId, HL_CLIENT_THREAD, &button1downoncube, NULL);
	hlAddEventCallback(HL_EVENT_1BUTTONUP, gMyShapeId, HL_CLIENT_THREAD, &button1uponcube, NULL);

	printf("Successfully initiated haptic device.\n");*/
}

/*//////////////////////////////////////////////////////////////////////////////
PhantomOMNIScene_holo::updateWorkspace()

Purpose: Updates Haptic IRL workspace to fit projection,
then calculates cursor scale.

Note: Don't forget to call hlMakeCurrent() if you wish to change current device.
*////////////////////////////////////////////////////////////////////////////////
void PhantomOMNIScene_holo::updateWorkspace()
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

/*////////////////////////////////////////////////////
PhantomOMNIScene_holo::freeHL()

Purpose: Frees all data used by haptic device(s)
and releases gMyShapeId and all callbacks
*/////////////////////////////////////////////////////
void PhantomOMNIScene_holo::freeHL()
{

	hlDeleteShapes(gMyShapeId, 1);
	hlDeleteShapes(gMyShapeId2, 1);

	// free up the haptic rendering context
	hlMakeCurrent(NULL);

	if (ghHLRC1 != NULL)
	{
		hlDeleteContext(ghHLRC1);
	}

	if (ghHLRC2 != NULL)
	{
		hlDeleteContext(ghHLRC2);
	}

	// free up the haptic device
	if (ghHD1 != HD_INVALID_HANDLE)
	{
		hdDisableDevice(ghHD1);
	}

    if (ghHD2 != HD_INVALID_HANDLE)
	{
		hdDisableDevice(ghHD2);
	}

	hlRemoveEventCallback(HL_EVENT_TOUCH, gMyShapeId,
		HL_CLIENT_THREAD, touchCubeCallback);
	hlRemoveEventCallback(HL_EVENT_UNTOUCH, gMyShapeId,
		HL_CLIENT_THREAD, untouchCubeCallback);

	printf("%s", "Freed device(s)\n");
}


PhantomOMNIScene_holo::~PhantomOMNIScene_holo()
{
}

void PhantomOMNIScene_holo::resize(int w, int h)
{

}

/*////////////////////////////////////////////////////////////////////////////
PhantomOMNIScene_holo::Update(float dt)

Purpose: Checks for haptic device(s) error
and also enables camera movability (not used)
also updates rotations on all 4 (haptically 5) cubes

Parameters: float dt: time passed since last update (in Seconds) (not used)

*//////////////////////////////////////////////////////////////////////////////
void PhantomOMNIScene_holo::Update(float dt)
{

	camera->control();

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

	if (rotateCubes)
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

void PhantomOMNIScene_holo::toggleGrid()
{
	bDrawGrid = !bDrawGrid;
	printf("Phantom: Toggled grid!\n");
}

void PhantomOMNIScene_holo::toggleAxis()
{
	lockZAxis = !lockZAxis;
	lockYAxis = !lockYAxis;
	printf("Phantom: toggled Z and Y axis\n");
}

/*//////////////////////////////////////////////////////////////
PhantomOMNIScene_holo::drawCursor()

Purpose: draws the pens position as a cylindrical cursor
also scales down cursor to specified gCursorScale.
draws via GLUT

*///////////////////////////////////////////////////////////////
void PhantomOMNIScene_holo::drawCursor()
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
	m_renderer->ImmediateColor(0.0, 0.5, 1.0);

	glCallList(gCursorDisplayList);
	glPopAttrib();

	glPopMatrix();
}

/*/////////////////////////////////////////////////////////////////////
PhantomOMNIScene_holo::drawCursor(Vector3 color)

Purpose: draws the pens position as a sphere with specified color
also scales down cursor to specified gCursorScale.
draws via GLUT

Parameters: Vector3 color: RGB color components that range from 0 to 1 (x=r, y=g, z=b)

Make sure to call hlMakeCurrent to setup correct device.
*/////////////////////////////////////////////////////////////////////
void PhantomOMNIScene_holo::drawCursor(voxelengine::Vector3 color)
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
void PhantomOMNIScene_holo::drawSceneHaptics()
{
	hlBeginFrame();

	hlMaterialf(HL_FRONT_AND_BACK, HL_STIFFNESS, 1.0f);
	hlMaterialf(HL_FRONT_AND_BACK, HL_DAMPING, 1.0f);
	hlMaterialf(HL_FRONT_AND_BACK, HL_STATIC_FRICTION, 0.2f);
	hlMaterialf(HL_FRONT_AND_BACK, HL_DYNAMIC_FRICTION, 0.3f);

	hlBeginShape(HL_SHAPE_FEEDBACK_BUFFER, gMyShapeId2);

	//glRotatef(45, 0, 1, 0);
	glutSolidCube(1);

	hlEndShape();

	hlEndFrame();

	hlCheckEvents();
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////
PhantomOMNIScene_holo::drawSceneHaptics(HLint shapeid)

Purpose: Sets upp material data (HL_STIFFNESS, HL_DAMPING, HL_STATIC_FRICTION, HL_DYNAMIC_FRCTION)
then draws shapeid to the haptic device(s).
also checks for events.

Parameters: HLint shapeid: what shape to draw

*////////////////////////////////////////////////////////////////////////////////////////////////////
void PhantomOMNIScene_holo::drawSceneHaptics(HLuint shapeid)
{
	hlBeginFrame();

	hlMaterialf(HL_FRONT_AND_BACK, HL_STIFFNESS, 1.0f);
	hlMaterialf(HL_FRONT_AND_BACK, HL_DAMPING, 1.0f);
	hlMaterialf(HL_FRONT_AND_BACK, HL_STATIC_FRICTION, 0.2f);
	hlMaterialf(HL_FRONT_AND_BACK, HL_DYNAMIC_FRICTION, 0.3f);

	hlBeginShape(HL_SHAPE_FEEDBACK_BUFFER, shapeid);
	m_renderer->glImmediateCube(1.0f);

	hlEndShape();

	hlEndFrame();

	hlCheckEvents();
}


void PhantomOMNIScene_holo::drawGrid(float angle, float x, float y, float z)
{

	if (!bDrawGrid) return;

	int HALF_GRID_SIZE = 10;

	glRotatef(angle, x, y, z);
	glBegin(GL_LINES);
	glColor3f(0.75f, 0.75f, 0.75f);
	for (int i = -HALF_GRID_SIZE; i <= HALF_GRID_SIZE; i++)
	{
		glVertex3f((float)i / 2, 0, (float)-HALF_GRID_SIZE);
		glVertex3f((float)i / 2, 0, (float)HALF_GRID_SIZE);

		glVertex3f((float)-HALF_GRID_SIZE, 0, (float)i / 2);
		glVertex3f((float)HALF_GRID_SIZE, 0, (float)i / 2);
	}
	glEnd();
}

void PhantomOMNIScene_holo::drawGrid()
{
	if (!bDrawGrid)
		return;

	int HALF_GRID_SIZE = 10;

	glBegin(GL_LINES);
	glColor3f(0.75f, 0.75f, 0.75f);
	for (int i = -HALF_GRID_SIZE; i <= HALF_GRID_SIZE; i++)
	{
		glVertex3f((float)i / 2, 0, (float)-HALF_GRID_SIZE);
		glVertex3f((float)i / 2, 0, (float)HALF_GRID_SIZE);

		glVertex3f((float)-HALF_GRID_SIZE, 0, (float)i / 2);
		glVertex3f((float)HALF_GRID_SIZE, 0, (float)i / 2);
	}
	glEnd();
}


/*///////////////////////////////////////////////////
PhantomOMNIScene_holo::Render()

Purpose: This function handles ALL render related
stuff, OGL and HL. (calls drawSceneHaptics(), drawCursor(), and also
draws a cube from 4 different views)

(when i use the word loop i mean the for loop int i = loop)

Note: This function is currently a mess and very hard to
navigate. The haptic rendering happens in loop 0, every other loop
only manipulates the drawn cube. Takes up three matrices from the stack per run. (i think lol:p)

*//////////////////////////////////////////////////////
void PhantomOMNIScene_holo::Render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glDisable(GL_LIGHTING);

	static const double kFovY = 40;

	double nearDist;

	nearDist = 1.0 / tan((kFovY / 2.0) * PI / 180.0) + 0.8f;

	for (int loop = 0; loop < 5; loop++)
	{

		if (loop == 0) //top
		{

			glViewport(RES_W / 4, RES_H / 2 + 50, RES_W / 2, RES_H / 2);
		}

		if (loop == 1) //left
		{
			glViewport(RES_W / 2 + 100, RES_H / 4, RES_W / 2, RES_H / 2);

		}

		if (loop == 2) //bottom
		{
			glViewport(RES_W / 4, 0 - 50, RES_W / 2, RES_H / 2);

		}

		if (loop == 3) //right
		{
			glViewport(0 - 100, RES_H / 4, RES_W / 2, RES_H / 2);
			//gluLookAt(1, 0, 0, 0, 0, 0, 0, 1, 0);
		}

		if (loop == 0) //top
		{

			glPushMatrix();
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
			gluLookAt(0, -2, nearDist + 1.2f, 0, 0, 0, 0, 1, 0);
			drawGrid(-20, 1, 0, 0);
			glPopMatrix();


			glPushMatrix();
			if (!lockXAxis)
				glRotatef(cube1rot.x, 0, 1, 0);
			if (!lockYAxis)
				glRotatef(cube1rot.y, 1, 0, 0);
			if (!lockZAxis)
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
			if (!lockXAxis)
				glRotatef(cube1rot.x, 0, 1, 0);
			if (!lockYAxis)
				glRotatef(cube1rot.y, 1, 0, 0);
			if (!lockZAxis)
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

		if (loop == 1) //left
		{

			glPushMatrix();
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
			gluLookAt(0, -2, nearDist + 1.2f, 0, 0, 0, 0, 1, 0);
			glRotatef(90, 1, 0, 0);
			drawGrid(20, 1, 0, 0);
			glPopMatrix();


			glPushMatrix();
			if (!lockXAxis)
				glRotatef(cube1rot.x, 0, 1, 0);
			if (!lockYAxis)
				glRotatef(cube1rot.y, 1, 0, 0);
			if (!lockZAxis)
				glRotatef(cube1rot.z, 0, 0, 1);

			hlMakeCurrent(ghHLRC1);
			drawCursor(voxelengine::Vector3(1, 1, 1));
			/*hlMakeCurrent(ghHLRC2);
			drawCursor(voxelengine::Vector3(1, 1, 1));*/
			glPopMatrix();

			glPushMatrix();

			if (!lockXAxis)
				glRotatef(cube1rot.x, 1, 0, 0);
			if (!lockYAxis)
				glRotatef(cube1rot.y, 0, 1, 0);
			if (!lockZAxis)
				glRotatef(cube1rot.z, 0, 0, 1);

			glPushAttrib(GL_CURRENT_BIT | GL_ENABLE_BIT | GL_LIGHTING_BIT);
			glEnable(GL_COLOR_MATERIAL);
			glRotatef(-90, 0, 1, 0);
			glCallList(gCubeDisplayList);
			glPopAttrib();
			glPopMatrix();
		}

		if (loop == 2) //bottom
		{
			glPushMatrix();
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
			gluLookAt(0, -2, nearDist + 1.2f, 0, 0, 0, 0, 1, 0);
			drawGrid(70, 1, 0, 0);
			glPopMatrix();

			glPushMatrix();
			if (!lockXAxis)
				glRotatef(cube1rot.x, 0, 1, 0);
			if (!lockYAxis)
				glRotatef(cube1rot.y, 1, 0, 0);
			if (!lockZAxis)
				glRotatef(cube1rot.z, 0, 0, 1);

			hlMakeCurrent(ghHLRC1);
			drawCursor(voxelengine::Vector3(1, 1, 1));
			/*hlMakeCurrent(ghHLRC2);
			drawCursor(voxelengine::Vector3(1, 1, 1));*/

			glPopMatrix();

			glPushMatrix();

			if (!lockXAxis)
				glRotatef(cube1rot.x, 0, 1, 0);
			if (!lockYAxis)
				glRotatef(cube1rot.y, 1, 0, 0);
			if (!lockZAxis)
				glRotatef(cube1rot.z, 0, 0, 1);

			glPushAttrib(GL_CURRENT_BIT | GL_ENABLE_BIT | GL_LIGHTING_BIT);
			glEnable(GL_COLOR_MATERIAL);
			glRotatef(-180, 0, 1, 0);
			glCallList(gCubeDisplayList);
			glPopAttrib();

			glPopMatrix();
		}

		if (loop == 3) //right
		{
			glPushMatrix();
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
			gluLookAt(0, -2, nearDist + 1.2f, 0, 0, 0, 0, 1, 0);
			drawGrid(-120,0,1,0);
			glPopMatrix();

			glPushMatrix();
			if (!lockXAxis)
				glRotatef(cube1rot.x, 0, 1, 0);
			if (!lockYAxis)
				glRotatef(cube1rot.y, 1, 0, 0);
			if (!lockZAxis)
				glRotatef(cube1rot.z, 0, 0, 1);

			hlMakeCurrent(ghHLRC1);
			drawCursor(voxelengine::Vector3(1, 1, 1));
			/*hlMakeCurrent(ghHLRC2);
			drawCursor(voxelengine::Vector3(1, 1, 1));*/

			glPopMatrix();

			glPushMatrix();

			if (!lockXAxis)
				glRotatef(-cube1rot.x, 1, 0, 0);
			if (!lockYAxis)
				glRotatef(cube1rot.y, 0, 1, 0);
			if (!lockZAxis)
				glRotatef(cube1rot.z, 0, 0, 1);

			glPushAttrib(GL_CURRENT_BIT | GL_ENABLE_BIT | GL_LIGHTING_BIT);
			glEnable(GL_COLOR_MATERIAL);
			glRotatef(90, 0, 1, 0);
			//glRotatef(90, 0, 0, 1);
			glCallList(gCubeDisplayList);
			glPopAttrib();

			glPopMatrix();

		} 
	}

}

/*//////////////////////
PhantomOMNIScene_holo::free()

Purpose: frees data.
*///////////////////////
void PhantomOMNIScene_holo::free()
{
	freeHL();
}