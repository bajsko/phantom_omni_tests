#pragma once
#include "openglrenderer.h"
#include "scene.h"
#include "phantomomniscene_holo.h"
#include "phantomomniscene_1_h_1_cube.h"
#include "phantomoniscene_2_h_1_cube.h"
#include <iostream>

class WindowManager
{
private:
	std::string m_title;
	int m_width;
	int m_height;
	sf::RenderWindow* m_window;
	bool m_running;
	OpenGLRenderer* m_renderer;
	Scene *m_scene;

	PhantomOMNIScene_holo *phantom_holo;
	PhantomOMNIScene_1_h_1_cube *phantom_1_h_1_cube;
	PhantomOMNIScene_2_h_1_cube *phantom_2_h_1_cube;
public:
	WindowManager(std::string title, int width, int height);
	~WindowManager();

	void Resize();

	void UpdateScene(float dt);
	void PollEvents();
	void RenderScene();

	void SetScene(Scene *scene);

	void Clean();

	bool isOpen();
	bool Running();

};

