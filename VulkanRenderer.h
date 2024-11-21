#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <stdexcept>
#include <vector>

#include "Utilities.h"

class VulkanRenderer
{
public:
	VulkanRenderer();
	~VulkanRenderer();

	int Init(GLFWwindow* newWindow);
	void Cleanup();

private:
	GLFWwindow* window;

	// Vulkan Components
	VkInstance instance;
	struct {
		VkPhysicalDevice physicalDevice;
		VkDevice logicalDevice;
	} mainDevice;

	VkQueue graphicsQueue;

	// Vulkan Functions
	void createInstance();
	void createLogicalDevice();

	bool checkInstanceExtensionSupport(std::vector<const char*>* checkExtensions);
	bool checkDeviceSuitable(VkPhysicalDevice device);

	void getPhysicalDevice();
	QueueFamilyIndices getQueueFamilies(VkPhysicalDevice device);
};

