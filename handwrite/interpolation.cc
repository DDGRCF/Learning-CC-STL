#include <stdint.h>

#include <cassert>
#include <cmath>
#include <iostream>

struct Image {
  using DataType = uint8_t;
  DataType* data;
  uint32_t width;
  uint32_t height;
};

uint32_t getPixelValue(const Image& image, float x, float y) {
  if (x >= image.width || y >= image.height || x < 0 || y < 0) {
    return 0;
  }

  uint32_t x1 = static_cast<uint32_t>(std::floor(x));
  uint32_t y1 = static_cast<uint32_t>(std::floor(y));
  uint32_t x2 = (x1 == image.width - 1) ? x1 : x1 + 1;
  uint32_t y2 = (y1 == image.height - 1) ? y1 : y1 + 1;

  float dx = x - static_cast<float>(x1);
  float dy = y - static_cast<float>(y1);

  float p11 = static_cast<float>(image.data[y1 * image.width + x1]);
  float p12 = static_cast<float>(image.data[y1 * image.width + x2]);
  float p21 = static_cast<float>(image.data[y2 * image.width + x1]);
  float p22 = static_cast<float>(image.data[y2 * image.width + x2]);

  float p = (1 - dx) * (1 - dy) * p11 + dx * (1 - dy) * p12 +
            (1 - dx) * dy * p21 + dx * dy * p22;

  return static_cast<Image::DataType>(p);
}

void interpolation(Image& image, uint32_t width, uint32_t height) {
  assert(image.data && image.width > 0 && image.height > 0);
  Image::DataType* data = static_cast<Image::DataType*>(
      malloc(width * height * sizeof(Image::DataType)));
  assert(data);

  for (uint32_t i = 0; i < height; i++) {
    for (uint32_t j = 0; j < width; j++) {
      float _x = j * (static_cast<float>(image.width) / width);
      float _y = i * (static_cast<float>(image.height) / height);
      data[i * width + j] = getPixelValue(image, _x, _y);
    }
  }
  image.data = data;
  image.width = width;
  image.height = height;
}

int main() {
  Image image;
  image.width = 3;
  image.height = 3;
  image.data = static_cast<Image::DataType*>(
      malloc(image.width * image.height * sizeof(Image::DataType)));

  uint8_t k = 0;
  for (uint32_t i = 0; i < image.height; i++) {
    for (uint32_t j = 0; j < image.width; j++) {
      image.data[i * image.width + j] = k++;
      std::cout << static_cast<uint32_t>(image.data[i * image.width + j])
                << " ";
    }
    std::cout << std::endl;
  }

  uint32_t width = 9, height = 9;
  interpolation(image, width, height);

  for (uint32_t i = 0; i < image.height; i++) {
    for (uint32_t j = 0; j < image.width; j++) {
      std::cout << static_cast<uint32_t>(image.data[i * image.width + j])
                << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}
