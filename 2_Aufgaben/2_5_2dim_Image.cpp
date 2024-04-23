#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "include/stb_image_write.h"
#include <iostream>
#include <fstream>

// Function to write a two-dimensional grayscale image to PNG file
bool writeGrayscaleImage(const char* filename, unsigned char** image, int width, int height)
{
    // Open file for writing
    FILE* file = fopen(filename, "wb");
    if (!file)
    {
        return false;
    }

    // Create a new buffer to store the image data in PNG format
    unsigned char* png_data = new unsigned char[width * height];

    // Copy and flip the image data to match PNG format
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            png_data[(height - 1 - y) * width + x + 100] = image[y][x];
        }
    }

    // Write grayscale image to PNG file
    int result = stbi_write_png(filename, width, height, 1, png_data, 0);

    // Clean up memory
    delete[] png_data;
    fclose(file);

    return result != 0;
}

void loadBMPImage(const char* file_name, unsigned char**& image, int& width, int& height)
{
    // Open the BMP image file in binary mode
    std::ifstream file(file_name, std::ios::binary);

    if (!file)
    {
        std::cout << "Failed to open " << file_name << std::endl;
        return;
    }

    // Read the header of the BMP image file (54 bytes)
    char header[54];
    file.read(header, 54);

    // Extract the width and height of the image from the header
    width = *(int*)&header[18];
    height = *(int*)&header[22];

    // Calculate the number of padding bytes per row
    int padding = 0;
    while ((width + padding) % 4 != 0)
    {
        padding++;
    }

    // Calculate the total size of the image data in bytes
    int data_size = (width + padding) * height;

    // Allocate memory to store the image data
    unsigned char* data = new unsigned char[data_size];

    // Read the image data from the file into the data buffer
    file.read(reinterpret_cast<char*>(data), data_size);

    // Close the BMP image file
    file.close();

    // Create a 2D array to store the image data
    image = new unsigned char*[height];
    for (int y = 0; y < height; ++y)
    {
        image[y] = &data[(width + padding) * y];
    }
}

// Function to calculate the mean grayscale value of an image
double calculateMeanGrayscaleValue2d(unsigned char** image, int width, int height)
{
    double sum = 0.0;
    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            sum += image[y][x];
        }
    }
    return sum / (width * height);
}

int main()
{
    const char* file_name = "marie_darkened.bmp";
    unsigned char** image = nullptr;
    int width = 0;
    int height = 0;

    loadBMPImage(file_name, image, width, height);

    // Calculate the mean grayscale value of the image
    double mean = calculateMeanGrayscaleValue2d(image, width, height);
    std::cout << "Mean grayscale value: " << mean << std::endl;

    // Write the grayscale image to PNG file
    const char* filename = "output.png";
    writeGrayscaleImage(filename, image, width, height);

    // Clean up memory
    delete[] image;
    return 0;
}
