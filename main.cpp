#include "WindowManager.h"
int main(int argc, char* argv[])
{
	printf("VoxelEngine | PhantomOMNI Edition v 0.1\n");
	WindowManager *windowManager = new WindowManager("VoxelEngine", RES_W, RES_H);

	sf::Clock deltaClock;
	while (windowManager->Running())
	{
		sf::Time delta = deltaClock.restart();
		float deltaTime = delta.asSeconds();

		windowManager->PollEvents();
		windowManager->UpdateScene(deltaTime);
		windowManager->RenderScene();
	}

	printf("\nSHUTTING DOWN VoxelEngine | PhantomOMNI Edition v 0.1\n");
	windowManager->Clean();

	delete windowManager;

	printf("\n\n\nPress enter to exit\n");
	getchar();
	return 0;
}