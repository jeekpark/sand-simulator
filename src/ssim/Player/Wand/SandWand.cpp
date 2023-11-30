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

#include "ssim/Player/Wand/SandWand.hpp"

namespace Ssim
{
  SandWand::SandWand(void)
  : mRadius(20)
  , mDensity(5)
  {}  

  SandWand::SandWand(const SandWand& copy)
  : mRadius(copy.mRadius)
  , mDensity(copy.mDensity)
  {}  

  SandWand::~SandWand(void)
  {}  

  SandWand& SandWand::operator=(const SandWand &copy)
  {
    if (this != &copy)
    {
      mRadius = copy.mRadius;
      mDensity = copy.mDensity;
    }
    return *this;
  } 

  void SandWand::use(int x, int y, World& world)
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
}
