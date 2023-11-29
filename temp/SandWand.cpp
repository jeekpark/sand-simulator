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

void CSandWand::use(int x, int y, CWorld& world)
{
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<> dis(0, 1);
  for (int i = x - mRadius; i <= x + mRadius; ++i)
    for (int j = y - mRadius; j <= y + mRadius; ++j)
      if (std::pow(i - x, 2) + std::pow(j - y, 2) <= std::pow(mRadius, 2)
          && dis(gen) < static_cast<float>(mDensity) / 100.f)
        world.addParticle(i, j, sf::Color::Yellow);
}