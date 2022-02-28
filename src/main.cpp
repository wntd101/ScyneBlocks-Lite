#include <main.h>
#include <gfx/window.h>
#include <world/block.h>
#include <world/camera.h>


Block block;
Camera cam;

void start()
{
	cam.init(100.0f, (float)1920.0f / (float)1080.0f);
	block.init();
}

void update()
{
	block.update(cam);
}

int main()
{
	int windowCreated = startWindow(1920, 1080, "ScyneBlocks");

	return windowCreated;
}
