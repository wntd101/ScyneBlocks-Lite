#include <gfx/window.h>
#include <world/mesh.h>

int init()
{
	if (!glfwInit())
	{
		std::cout << "Failed To Initialize GLFW" << std::endl;
		return -1;
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_MAXIMIZED, GLFW_TRUE);

	return 0;
}

int createWindow(int width, int height, const char* title)
{
	window = glfwCreateWindow(width, height, title, NULL, NULL);

	if (window == NULL)
	{
		std::cout << "Failed to Create The Window\n" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	return 0;
}

void loop(void(*func)(Mesh), Mesh block)
{
	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(135.0f / 255.0f, 206.0f / 255.0f, 235.0f / 255.0f, 1.0f);

		func(block);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
}

int startWindow(int width, int height, const char* title, void(*func)(Mesh), Mesh block)
{
	int success = init() | createWindow(width, height, title);
	loop(func, block);

	return success;
}