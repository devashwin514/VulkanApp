#pragma once

#include <fstream>

const std::vector<const char *> deviceExtensions = {
	VK_KHR_SWAPCHAIN_EXTENSION_NAME
};

// Indices (locations) of Queue Families (if they exist at all)
struct QueueFamilyIndices {
	int graphicsFamily = -1;		// Location of Graphics Queue Family
	int presentationFamily = -1;	// Location of Presentation Queue Family

	// Check if queue families are valid
	bool isValid() {
		if (graphicsFamily >= 0 && presentationFamily >= 0) {
			return true;
		}
	}
};

struct SwapChainDetails {
	VkSurfaceCapabilitiesKHR surfaceCapabilities;		// Surface properties, e.g. image size/extent
	std::vector<VkSurfaceFormatKHR> formats;			// Surface image formats, e.g. RGBA and size of each color
	std::vector<VkPresentModeKHR> presentationModes;	// How images should be presented to the screen
};

struct SwapchainImage {
	VkImage image;
	VkImageView imageView;
};

static std::vector<char> readFile(const std::string &filename) {
	// Open stream from given file
	// std::ios::binary tells stream to read binary file
	// std::ios::ate tells stream to start reading from EOF
	std::ifstream file(filename, std::ios::binary | std::ios::ate);

	// Check if file has opened successfully
	if (!file.is_open()) {
		throw std::runtime_error("Failed to open a file!");
	}

	// Get current read position and use to resize file buffer
	size_t fileSize = (size_t)file.tellg();
	std::vector<char> fileBuffer(fileSize);

	// Read position from start of the file
	file.seekg(0);

	// Read the file data into the buffer (stream "fileSize" in total
	file.read(fileBuffer.data(), fileSize);

	// Close stream
	file.close();

	return fileBuffer;
}