#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <stdexcept>
#include <vector>
#include <iostream>

#include "VulkanRenderer.h"

GLFWwindow* window;
VulkanRenderer vulkanRenderer;

void initWindow(std::string wName = "Test Window", const int width = 800, const int height = 600)
{
	glfwInit();

	// GLFW defaults to OpenGL, here we set it to "no API"
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

	window = glfwCreateWindow(width, height, wName.c_str(), nullptr, nullptr);
}

int main()
{
	initWindow();

	// Create VulkanRenderer instance
	if (vulkanRenderer.Init(window) == EXIT_FAILURE)
	{
		return EXIT_FAILURE;
	} 

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();

	}

	vulkanRenderer.Cleanup();

	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}