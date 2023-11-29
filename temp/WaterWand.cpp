/**
 * @file WaterWand.cpp
 * @author Jeekun Park (jeekunp@naver.com)
 * @brief 
 * @version 0.1
 * @date 2023-11-28
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "./WaterWand.hpp"

#include "SFML/Graphics/Color.hpp"
#include "SFML/Graphics/Image.hpp"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#include <random>

CWaterWand::CWaterWand(void)
: mRadius(20)
, mDensity(5)
{}

CWaterWand::CWaterWand(const CWaterWand& copy)
: mRadius(copy.mRadius)
, mDensity(copy.mDensity)
{}

CWaterWand::~CWaterWand(void)
{}

CWaterWand& CWaterWand::operator=(const CWaterWand &copy)
{
  if (this != &copy)
  {
    mRadius = copy.mRadius;
    mDensity = copy.mDensity;
  }
  return *this;
}

void CWaterWand::use(int x, int y, CWorld& world)
{
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<> dis(0, 1);
  for (int i = x - mRadius; i <= x + mRadius; ++i)
    for (int j = y - mRadius; j <= y + mRadius; ++j)
      if (std::pow(i - x, 2) + std::pow(j - y, 2) <= std::pow(mRadius, 2)
          && dis(gen) < static_cast<float>(mDensity) / 100.f)
        world.addParticle(i, j, sf::Color::Cyan);
}