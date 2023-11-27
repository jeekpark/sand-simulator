/**
 * @file SandWand.cpp
 * @author Jeekun Park (jeekunp@naver.com)
 * @brief 
 * @version 0.1
 * @date 2023-11-27
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "./SandWand.hpp"
#include "SFML/Graphics/Color.hpp"
#include "SFML/Graphics/Image.hpp"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#include <random>

CSandWand::CSandWand(void)
: mRadius(20)
, mDensity(5)
{}

CSandWand::CSandWand(const CSandWand& copy)
: mRadius(copy.mRadius)
, mDensity(copy.mDensity)
{}

CSandWand::~CSandWand(void)
{}

CSandWand& CSandWand::operator=(const CSandWand &copy)
{
  if (this != &copy)
  {
    mRadius = copy.mRadius;
    mDensity = copy.mDensity;
  }
  return *this;
}

void CSandWand::use(sf::Image& image, unsigned int x, unsigned int y)
{
  const sf::Vector2u size = image.getSize();

  std::vector<sf::Vector2i> pixels;
  for (unsigned int i = x - mRadius; i <= x + mRadius; ++i)
  {
    for (unsigned int j = y -mRadius; j <= y + mRadius; ++j)
    {
      if (std::pow(i - x, 2) + std::pow(j - y, 2) <= std::pow(mRadius, 2))
      {
        if ((0 <= i && i < size.x) && (0 <= j && j < size.y))
          pixels.push_back(sf::Vector2i(i, j));
      }
    }
  }
  std::random_device rd;
  std::mt19937 g(rd());
  std::shuffle(pixels.begin(), pixels.end(), g);
  int numPixelsToChange = pixels.size() * (static_cast<double>(mDensity) / 100.0);
  for (int i = 0; i < numPixelsToChange; ++i)
  {
    image.setPixel(pixels[i].x, pixels[i].y, sf::Color::Yellow);
  }


}