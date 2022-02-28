#include <gfx/window.h>
#include <util/input.h>

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
	glfwSwapInterval(1);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	glfwSetKeyCallback(window, keyCallback);

	start();

	return 0;
}

void loop()
{
	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(135.0f / 255.0f, 206.0f / 255.0f, 235.0f / 255.0f, 1.0f);

		update();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
}

int startWindow(int width, int height, const char* title)
{
	int success = init() | createWindow(width, height, title);
	loop();

	return success;
}