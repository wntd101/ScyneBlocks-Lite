#include <main.h>
#include <gfx/window.h>
#include <world/chunk.h>
#include <util/input.h>
#include <world/player.h>

Chunk chunk;
Player player;


void start()
{
	player = Player(glm::vec3(0.0, 0.0, 0.0));
	chunk.init();
}

void update()
{
	chunk.update(player);
	player.update();
	endInputs();
}

int main()
{
	int windowCreated = startWindow(1920, 1080, "ScyneBlocks");

	return windowCreated;
}
