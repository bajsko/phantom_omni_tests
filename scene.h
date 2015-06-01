#pragma once

#include "openglrenderer.h"

#define RES_W 1024
#define RES_H 768

class Scene
{
protected:
	OpenGLRenderer *m_renderer;
public:
	Scene(OpenGLRenderer *renderer);
	~Scene();

	virtual void Update(float dt) = 0;
	virtual void Render() = 0;
	virtual void resize(int w, int h) = 0;
	virtual void free() = 0;
};

