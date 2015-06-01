#include "openglrenderer.h"


/***********************************************/
/*				Constructors				  */
/*********************************************/

OpenGLRenderer::OpenGLRenderer(void)
{
}

OpenGLRenderer::OpenGLRenderer(int width, int height)
{
	videoMode.m_width = width;
	videoMode.m_height = height;
	videoMode.m_aspect = (float)width / (float)height;
}


OpenGLRenderer::~OpenGLRenderer(void)
{
}

/**************************************************/
/*				Non render related				 */
/************************************************/


/*///////////////////////////////////////////////////////////////////////////
OGLRenderer::InitRender()

Purpose: Initializes and sets up OpenGL for a 3D environment and
			also enables general  rendering functionality like
			textures, blend (alpha blend) and smooth shading.
			lighting is NOT enabled.
			after initating OGL it also calls OGLRenderer::SetViewport()

This function can be called at all times, but should only be used once.
*///////////////////////////////////////////////////////////////////////////
void OpenGLRenderer::InitRenderer()
{
	glShadeModel(GL_SMOOTH);
	glClearColor(0, 0, 0, 0);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	videoMode.m_depth = true;
	glDepthFunc(GL_LEQUAL);

	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	SetViewport(videoMode.m_width, videoMode.m_height);

}

/*//////////////////////////////////////////////////////////////////////////
OGLRenderer::OGLPerspective(float fovy, float aspect, float zNear, float zFar)

Purpose: Creates a perspective view based on specified parameters

Parameters: float fovy: field of view for the Y axis
			float aspect: screen aspect ratio (stored in videoMode)
			float zNear: near z clipping plane
			float zFar: far z clipping plane

All this method does is calls glFrustum with calculated parameters.
*///////////////////////////////////////////////////////////////////////////
void OpenGLRenderer::OGLPerspective(float fovy, float aspect, float zNear, float zFar)
{
	//half x/y clipping planes
	float fh;
	float fw;

	fh = tan((fovy / 360 * PI) * zNear);
	fw = fh * aspect;
	glFrustum(-fw, fw, -fh, fh, zNear, zFar);
}

/*////////////////////////////////////////////////////////////////////////
OGLRenderer::OGLOrtho(float left, float right, float bottom, float top, float znear, float zfar)

Purpose: Creates an orthographic projection based o specified parameters

Parameters: float left: left side
			float right: right side
			float bottom: bottom
			float top: top
			float zNear: near z clipping plane
			float zFar: far z clipping plane

Calls glOrtho with specified parameters.
*////////////////////////////////////////////////////////////////////////
void OpenGLRenderer::OGLOrtho(float left, float right, float bottom, float top, float znear, float zfar)
{
	glOrtho(left, right, bottom, top, znear, zfar);
}

/*///////////////////////////////////////////////////////////////////////
OGLRenderer::SetPerspective(float deg, float aspect, float znear, float zfar)

Purpose: Enables depth testing, loads projection matrix
			and then calls OGLRenderer::OGLPerspective() with specified parameters
			then loads back to the modelview matrix.

Parameters: float deg: field of view for the Y axis (in degrees)
			float aspect: screen aspect ratio (stored in videoMode)
			float zNear: near z clipping plane
			float zFar: far z clipping plane

Use this function over OGLPerspective() since this one assures manipulating correct matrix and sets correct depth testing.
*////////////////////////////////////////////////////////////////////////
void OpenGLRenderer::SetPerspective(float deg, float aspect, float zNear, float zFar)
{
	if (!videoMode.m_depth) {
		glEnable(GL_DEPTH_TEST);
		videoMode.m_depth = true;
	}

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	OGLPerspective(deg, aspect, zNear, zFar);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

/*/////////////////////////////////////////////////////////////////////////////
OGLRenderer::SetOrtho(float l, float r, float b, float t, float znear, float zfar)

Purpose: Disables depth testing, loads projection matrix
			and then calls OGLRenderer::OGLOrtho() with specified parameters
			then loads back to the modelview matrix

Parameters: float l: left side
			float r: right side
			float b: bottom
			float t: top
			float znear: near Z clipping plane
			float zfar: far Z clipping plane

Use this function over OGLOrtho() since this one assures manipulating correct matrix and sets correct depth testing.
*/////////////////////////////////////////////////////////////////////////////////
void OpenGLRenderer::SetOrtho(float l, float r, float b, float t, float znear, float zfar)
{
	if (videoMode.m_depth) {
		glDisable(GL_DEPTH_TEST);
		videoMode.m_depth = false;
	}

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	OGLOrtho(l, r, b, t, znear, zfar);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

/*/////////////////////////////////////////////////////////////////////////////////
OGLRenderer::SetMatrixMode(OGL_MatrixMode mode)

Purpose: Sets specified matrix AND loads identity
Parameters: What matrix to be loaded to OGL
*/////////////////////////////////////////////////////////////////////////////////
void OpenGLRenderer::SetMatrixMode(OGL_MatrixMode mode)
{
	if (mode == OGL_Projection)
	{
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
	}
	else if (mode == OGL_Modelview)
	{
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
	}
}

/****************************************************/

/***************************************************/
/*		Help functions before/during render 	  */
/*************************************************/

/*/////////////////////////////////////////////////////
OGLRenderer::PreRender()

Purpose: calls glClear(color buffer bit | depth buffer bit)
		and also calls OGLRenderer::SetMatrixMode(OGL_Modelview)

This method is intended to be called at firt render method.
*/////////////////////////////////////////////////////
void OpenGLRenderer::PreRender()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	SetMatrixMode(OGL_Modelview);
}

/*/////////////////////////////////////////////////////
OGLRenderer::PushMatrix()
Purpose: Just calls glPushMatrix()
*//////////////////////////////////////////////////////
void OpenGLRenderer::PushMatrix()
{
	glPushMatrix();
}

/*/////////////////////////////////////////////////////
OGLRenderer::PopMatrix()
Purpose: Just calls glPopMatrix()
*//////////////////////////////////////////////////////
void OpenGLRenderer::PopMatrix()
{
	glPopMatrix();
}

/*/////////////////////////////////////////////////////
OGLRenderer::TranslateWorldMatrix(float x, float y, float z)
Purpose: Just calls glTranslatef(x,y,z)
*//////////////////////////////////////////////////////
void OpenGLRenderer::TranslateWorldMatrix(float x, float y, float z)
{
	glTranslatef(x, y, z);
}

/*/////////////////////////////////////////////////////
OGLRenderer::RotateWorldMatrix(float x, float y, float z)
Purpose: Just calls glRotatef(x,y,z)
*//////////////////////////////////////////////////////
void OpenGLRenderer::RotateWorldMatrix(float deg, float x, float y, float z)
{
	glRotatef(deg, x, y, z);
}

/*///////////////////////////////////////////////
OGLRenderer::setViewport(int w, int h)

Purpose: Updates viewMode with width, height & aspect
			then calls glViewport() with specified parameters

Parameters: int w: width of viewport
			int h: height of viewport
*/
void OpenGLRenderer::SetViewport(int w, int h)
{
	videoMode.m_width = w;
	videoMode.m_height = h;
	videoMode.m_aspect = (float)videoMode.m_width / (float)videoMode.m_height;
	glViewport(0, 0, w, h);
}

/********************************************************/

/******************************************************/
/*					Render Functions				 */
/****************************************************/

/*////////////////////////////////////////////////////////////////
OGLRenderer::BeginImmediateMode(IM_MODE mode)

Purpose: Enables OGL immediate mode based on specified mode
Parameters: IM_MODE mode: What immediate mode to begin

Does exactly the same thing as glBegin()
*//////////////////////////////////////////////////////////////////
void OpenGLRenderer::BeginImmediateMode(IM_MODE mode)
{
	GLenum glMode;

	switch (mode) {
	case IM_QUADS:
		glMode = GL_QUADS;
		break;
	case IM_LINES:
		glMode = GL_LINES;
		break;
	case IM_TRIANGLES:
		glMode = GL_TRIANGLES;
		break;
	case IM_POINTS:
		glMode = GL_POINTS;
		break;
	}

	glBegin(glMode);
}

/*////////////////////////////////////////////////////////////////
OGLRenderer::EndImmediateMode()

Purpose: Ends immediate mode

Does exactly the same thing as glEnd()
*//////////////////////////////////////////////////////////////////
void OpenGLRenderer::EndImmediateMode()
{
	glEnd();
}

/*////////////////////////////////////////////////////////////////
OGLRenderer::EnableWireframe()

Purpose: All objects drawn after this call will be in wireframe mode.

Calls glPolygonMode(GL_FRONT_AND_BACK, GL_LINE)
*//////////////////////////////////////////////////////////////////
void OpenGLRenderer::EnableWireframe()
{
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}

/*////////////////////////////////////////////////////////////////
OGLRenderer::Disablewireframe()

Purpose: Disables wireframe, all objects drawn after this call
will NOT be wireframed

Calls glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
*//////////////////////////////////////////////////////////////////
void OpenGLRenderer::DisableWireframe()
{
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

/*////////////////////////////////////////////////////////////////
OGLRenderer::ImmediateVertex(float x, float y, float z)

Purpose: Draws a vertex at specified point (Vector 3 x,y,z)
Parameters: float x: x coord.
			float y: y coord.
			float z: z coord.
*//////////////////////////////////////////////////////////////////
void OpenGLRenderer::ImmediateVertex(float x, float y, float z)
{
	glVertex3f(x, y, z);
}

/*////////////////////////////////////////////////////////////////
OGLRenderer::ImmediateColor(float r, float g, float b)

Purpose: Colors next immediate vertices with specified color (Vector3, r,g,b)
Parameters: float r: r color
			float g: g color
			float b: b color

Colors range from 0 to 1
*//////////////////////////////////////////////////////////////////
void OpenGLRenderer::ImmediateColor(float r, float g, float b)
{
	glColor3f(r, g, b);
}

/*////////////////////////////////////////////////////////////////
OGLRenderer::ImmediateColorAlpha(float r, float g, float b, float a)

Purpose: Colors next immediate vertices with specified color (Vector4, r,g,b,a)
Parameters: float r: r color
			float g: g color
			float b: b color
			float a: alpha color

Colors range from 0 to 1
*//////////////////////////////////////////////////////////////////
void OpenGLRenderer::ImmediateColorAlpha(float r, float g, float b, float a)
{
	glColor4f(r, g, b, a);
}

/*////////////////////////////////////////////////////////////////
OGLRenderer::ImmediateNormal(float x, float y, float z)

Purpose: Creates a normal at specified point (Vector 3 x,y,z)
Parameters: float x: x coord.
			float y: y coord.
			float z: z coord.
*//////////////////////////////////////////////////////////////////
void OpenGLRenderer::ImmediateNormal(float x, float y, float z)
{
	glNormal3f(x, y, z);
}

/*////////////////////////////////////////////////
OpenGLRenderer::glImmediateCube(float size)

Purpose: draws an immediate cube (GL_QUADS)
with specified size.

Parameters: float size: Size of cube (one side)
Default color:
front: red
back: green
top: blue
bottom: pink
right: teal
left: white
*//////////////////////////////////////////////////
void OpenGLRenderer::glImmediateCube(float size)
{
	BeginImmediateMode(IM_QUADS);

	float halfSize = size * 0.5f;

	//front - red
	ImmediateColor(1, 0, 0);
	ImmediateNormal(0, 0, 1);
	ImmediateVertex(-halfSize, -halfSize, halfSize);
	ImmediateVertex(halfSize, -halfSize, halfSize);
	ImmediateVertex(halfSize, halfSize, halfSize);
	ImmediateVertex(-halfSize, halfSize, halfSize);

	//back - green
	ImmediateColor(0, 1, 0);
	ImmediateNormal(0, 0, -1);
	ImmediateVertex(-halfSize, -halfSize, -halfSize);
	ImmediateVertex(halfSize, -halfSize, -halfSize);
	ImmediateVertex(halfSize, halfSize, -halfSize);
	ImmediateVertex(-halfSize, halfSize, -halfSize);

	//top - blue
	ImmediateColor(0, 0, 1);
	ImmediateNormal(0, 1, 0);
	ImmediateVertex(-halfSize, halfSize, halfSize);
	ImmediateVertex(halfSize, halfSize, halfSize);
	ImmediateVertex(halfSize, halfSize, -halfSize);
	ImmediateVertex(-halfSize, halfSize, -halfSize);

	//bottom - pink
	ImmediateColor(1, 0, 1);
	ImmediateNormal(0, -1, 0);
	ImmediateVertex(-halfSize, -halfSize, halfSize);
	ImmediateVertex(halfSize, -halfSize, halfSize);
	ImmediateVertex(halfSize, -halfSize, -halfSize);
	ImmediateVertex(-halfSize, -halfSize, -halfSize);

	//right - teal
	ImmediateNormal(1, 0, 0);
	ImmediateColor(0, 1, 1);
	ImmediateVertex(halfSize, halfSize, halfSize);
	ImmediateVertex(halfSize, halfSize, -halfSize);
	ImmediateVertex(halfSize, -halfSize, -halfSize);
	ImmediateVertex(halfSize, -halfSize, halfSize);


	//left - white
	ImmediateColor(1, 1, 1);
	ImmediateNormal(-1, 0, 0);
	ImmediateVertex(-halfSize, halfSize, halfSize);
	ImmediateVertex(-halfSize, halfSize, -halfSize);
	ImmediateVertex(-halfSize, -halfSize, -halfSize);
	ImmediateVertex(-halfSize, -halfSize, halfSize);

	EndImmediateMode();
}

/*////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
PhantomOMNIScene::glImmediateCube(float size, voxelengine::Vector3 front, voxelengine::Vector3 back, voxelengine::Vector3 top, voxelengine::Vector3 bottom, voxelengine::Vector3 left, voxelengine::Vector3 right)

Purpose: Draws an immediate cube (GL_QUADS) with specified size and colors

Parameters: float size: size of ONE side of the cube
Vector3 front: front side color
Vector3 back: back side color
Vector3 top: top side color
Vector3 bottom: bottom side color
Vector3 left: left side color
Vector3 right: right side color

*/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void OpenGLRenderer::glImmediateCube(float size, voxelengine::Vector3 front, voxelengine::Vector3 back, voxelengine::Vector3 top, voxelengine::Vector3 bottom, voxelengine::Vector3 left, voxelengine::Vector3 right)
{
	BeginImmediateMode(IM_QUADS);

	float halfSize = size * 0.5f;

	//front - red
	ImmediateColor(front.x, front.y, front.z);
	ImmediateNormal(0, 0, 1);
	ImmediateVertex(-halfSize, -halfSize, halfSize);
	ImmediateVertex(halfSize, -halfSize, halfSize);
	ImmediateVertex(halfSize, halfSize, halfSize);
	ImmediateVertex(-halfSize, halfSize, halfSize);

	//back - green
	ImmediateColor(back.x, back.y, back.z);
	ImmediateNormal(0, 0, -1);
	ImmediateVertex(-halfSize, -halfSize, -halfSize);
	ImmediateVertex(halfSize, -halfSize, -halfSize);
	ImmediateVertex(halfSize, halfSize, -halfSize);
	ImmediateVertex(-halfSize, halfSize, -halfSize);

	//top - blue
	ImmediateColor(top.x, top.y, top.z);
	ImmediateNormal(0, 1, 0);
	ImmediateVertex(-halfSize, halfSize, halfSize);
	ImmediateVertex(halfSize, halfSize, halfSize);
	ImmediateVertex(halfSize, halfSize, -halfSize);
	ImmediateVertex(-halfSize, halfSize, -halfSize);

	//bottom - pink
	ImmediateColor(bottom.x, bottom.y, bottom.z);
	ImmediateNormal(0, -1, 0);
	ImmediateVertex(-halfSize, -halfSize, halfSize);
	ImmediateVertex(halfSize, -halfSize, halfSize);
	ImmediateVertex(halfSize, -halfSize, -halfSize);
	ImmediateVertex(-halfSize, -halfSize, -halfSize);

	//right - teal
	ImmediateNormal(right.x, right.y, right.z);
	ImmediateColor(0, 1, 1);
	ImmediateVertex(halfSize, halfSize, halfSize);
	ImmediateVertex(halfSize, halfSize, -halfSize);
	ImmediateVertex(halfSize, -halfSize, -halfSize);
	ImmediateVertex(halfSize, -halfSize, halfSize);


	//left - white
	ImmediateColor(left.x, left.y, left.z);
	ImmediateNormal(-1, 0, 0);
	ImmediateVertex(-halfSize, halfSize, halfSize);
	ImmediateVertex(-halfSize, halfSize, -halfSize);
	ImmediateVertex(-halfSize, -halfSize, -halfSize);
	ImmediateVertex(-halfSize, -halfSize, halfSize);

	EndImmediateMode();
}

/**********************************************************/


void OpenGLRenderer::Dispose()
{

}