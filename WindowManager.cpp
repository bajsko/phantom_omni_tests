#include "WindowManager.h"


/*////////////////////////////////////////////////////////////////////////////
WindowManager::WindowManager(std::string title, int width, int height)

Purpose: Constructor. Initializes an SF window and also
			initializes the OGL renderer & PhantomOMNIScene.

Parameters: std::string title: Title of window
			int width: Width of window (and rendering context)
			int height: Height of window (and rendering context)

//////////////////////////////////////////////////////////////////////////////
*/
WindowManager::WindowManager(std::string title, int width, int height)
{

	int run = 0; //0 = holo, 1 = 1 cube 1 haptic, 2 = 1 cube 2 haptic

	printf("Engine->Creating window...\n");
	printf("Engine->Setting Constants...\n");
	this->m_title = title;
	this->m_width = width;
	this->m_height = height;
	printf("DONE\n");

	printf("Engine->Initializing RenderWindow\n");
	m_window = new sf::RenderWindow(sf::VideoMode(width, height), title);
	printf("DONE\n");

	printf("Engine->Initializing OGL Renderer\n");
	m_renderer = new OpenGLRenderer(width, height);
	m_renderer->InitRenderer();
	printf("DONE\n");
	//m_renderer->EnableOrtho(); //dont enable anything for now, let phantomomniscene do it.

	printf("Engine->Creating PhantomOMNIScenes...\n");

	if (run == 0)
		phantom_holo = new PhantomOMNIScene_holo(m_renderer);
	else if (run == 1)
		phantom_1_h_1_cube = new PhantomOMNIScene_1_h_1_cube(m_renderer);
	else if(run == 2)
		phantom_2_h_1_cube = new PhantomOMNIScene_2_h_1_cube(m_renderer);

	printf("DONE\n");

	printf("SceneManager->Setting Scene to correct PHANTOMOMNISCENE (%d)\n", run);
	if (run == 0)
		SetScene(phantom_holo);
	else if (run == 1)
		SetScene(phantom_1_h_1_cube);
	else if (run == 2)
		SetScene(phantom_2_h_1_cube);
	printf("DONE\n");

	m_running = true;
}

/*/////////////////////////////////////////////////////////
WindowManager::Resize()

Purpose: Resizes window & rendering context
			to new size.

//////////////////////////////////////////////////////////
*/
void WindowManager::Resize()
{
	m_width = m_window->getSize().x;
	m_height = m_window->getSize().y;
	m_renderer->SetViewport(m_width, m_height);
	m_scene->resize(m_width, m_height);

	printf("Resized!!\n");
}

/*///////////////////////////////////////////////
WindowManager::SetScene(Scene* scene)

Purpose: Sets current scene to render

Parameters: Scene* scene: Scene to set as current.

*//////////////////////////////////////////////////
void WindowManager::SetScene(Scene* scene)
{
	this->m_scene = scene;
}

/*//////////////////////////////////////////////
WindowManager::UpdateScene(float dt)

Purpose: Updates currnt scene AND
			mouse position.

Parameters: float dt: time elapsed since last update (in seconds)

*///////////////////////////////////////////////
void WindowManager::UpdateScene(float dt)
{


	lastMouseX = mouseX;
	lastMouseY = mouseY;

	m_scene->Update(dt);

	Vector2i mouse = Mouse::getPosition(*this->m_window);
	mouseX = mouse.x;
	mouseY = mouse.y;
}

/*/////////////////////////////////////////////////////
WindowManager::PollEvents()

Purpose: Polls all kind of SF events.

/////////////////////////////////////////////////////*/
void WindowManager::PollEvents()
{
	sf::Event event;
	while (m_window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
			m_running = false;
		if (event.type == sf::Event::Resized)
			Resize();
		if (event.type == sf::Event::KeyPressed)
		{
			
			if (m_scene == phantom_holo)
			{
				if (event.key.code == Keyboard::A)
					phantom_holo->toggleAxis();
				if (event.key.code == Keyboard::G)
					phantom_holo->toggleGrid();
			}
		}
		
		if (event.type == sf::Event::KeyReleased)
			keys[event.key.code] = false;
	}
}

/*///////////////////////////////////////////
WindowManager::RenderScene()

Purpose: renders m_scene and swaps buffers.

*////////////////////////////////////////////
void WindowManager::RenderScene()
{
	m_scene->Render();
	m_window->display();
}

/*///////////////////////////////////////
WindowManager::Clean()

Purpose: Frees all allocated data from m_scene
			and m_renderer

*////////////////////////////////////////
void WindowManager::Clean()
{
	printf("Engine->Cleaning up...\n");
	m_scene->free();
	m_renderer->Dispose();

	delete m_scene;
	delete m_renderer;

	m_window->close();

	printf("DONE\n");
}

//Are we open?
bool WindowManager::isOpen()
{
	return m_window->isOpen();
}

//Are we running?
bool WindowManager::Running()
{
	return m_running;
}

WindowManager::~WindowManager()
{

}
