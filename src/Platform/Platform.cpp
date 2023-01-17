#include "Platform/Platform.hpp"

#if defined(_WIN32)
	#include "Platform/Win32/WindowsPlatform.hpp"
#endif

/*****************************************************************************/
void Platform::initialize(GLFWwindow* inWindow)
{
#if defined(_WIN32)
	util::WindowsPlatform platform;
	platform.initialize(inWindow);
#else
	UNUSED(inWindow);
#endif
}