#pragma once

const std::vector<const char*> deviceExtensions = {
	VK_KHR_SWAPCHAIN_EXTENSION_NAME
};

// Indices (locations) of Queue Families (if they exists at all)
struct QueueFamilyIndices 
{
	int graphicsFamily = -1;			// Location of Graphics Queue Family
	int presentationFamily = -1;		// Location of Presentation Queue Family

	// Check if queue families are valid
	bool isValid()
	{
		return graphicsFamily >= 0 && presentationFamily >= 0;
	}
};

struct SwapchainDetails
{
	VkSurfaceCapabilitiesKHR surfaceCapabilities;	 // Surface properties, e.g. image size/extent
	std::vector<VkSurfaceFormatKHR> formats;		 // List of image formats this surface supports
	std::vector<VkPresentModeKHR> presentationModes; // How images should be presented to screen: FIFO, Immediate, etc..
};

struct SwapchainImage {
	VkImage image;
	VkImageView imageView;
};