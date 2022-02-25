#include <main.h>
#include <gfx/window.h>
#include <world/block.h>
#include <world/camera.h>

namespace ScyneBlocks
{
	Block block;
	Camera cam;
}

void start()
{
	ScyneBlocks::cam.init(100.0f, (float)1920.0f / (float)1080.0f);
	ScyneBlocks::block.init();
}

void update()
{
	ScyneBlocks::block.update(ScyneBlocks::cam);
}

int main()
{
	int windowCreated = startWindow(1920, 1080, "ScyneBlocks");

	return windowCreated;
}
