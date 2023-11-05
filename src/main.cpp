
#include <glm/glm.hpp>

#include "Platform/Platform.hpp"

namespace app
{
GLFWwindow* window = nullptr;
bool running = true;

int initialize()
{
    // Initialize the library
    if (!glfwInit())
        return -1;

    // Create a windowed mode window and its OpenGL context
    window = glfwCreateWindow(640, 480, "Hello World", nullptr, nullptr);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    Platform::initialize(window);

    // Make the window's context current
    glfwMakeContextCurrent(window);

	// Set the background color (Cornflower Blue - 100,149,237)
	glClearColor(100.0f / 255.0f, 149.0f / 255.0f, 237.0f / 255.0f, 1.0f);
    return 0;
}

void dispose()
{
    glfwTerminate();
}

bool isRunning()
{
    return !glfwWindowShouldClose(window);
}

void mainLoop()
{
	if (!isRunning())
    {
        dispose();
#if defined(APP_EMSCRIPTEN)
        emscripten_cancel_main_loop();
#else
        ::exit(0);
#endif
    }

    // Render here
    glClear(GL_COLOR_BUFFER_BIT);

    // Swap front and back buffers
    glfwSwapBuffers(window);

    // Poll for and process events
    glfwPollEvents();
}
}

int main(const int argc, const char* argv[])
{
	std::cout << "Hello world!\n\n";
	std::cout << "Args:\n";

	for (int i = 0; i < argc; ++i)
	{
		std::cout << "  " << argv[i] << '\n';
	}

    if (app::initialize() > 0)
        return 1;

#if defined(APP_EMSCRIPTEN)
    emscripten_set_main_loop(app::mainLoop, 0, 1);
#else
    while (1) {
		app::mainLoop();
	}
#endif
}
