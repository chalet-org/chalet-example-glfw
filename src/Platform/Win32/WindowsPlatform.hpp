#pragma once

#include <array>

namespace util
{
struct WindowsPlatform
{
	WindowsPlatform();

	void initialize(GLFWwindow* inHandle);

private:
	float getScreenScalingFactor();

	PBYTE getIconDirectory(const int inResourceId);
	HICON getIconFromIconDirectory(PBYTE inIconDirectory, const uint32_t inSize);

	float m_screenScalingFactor = 0.0f;
};
}
