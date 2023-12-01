/**
 * @file WaterWand.cpp
 * @author Jeekun Park (jeekunp@naver.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-01
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "ssim/Player/Wand/WaterWand.hpp"

namespace Ssim
{
  WaterWand::WaterWand(void)
  : mRadius(20)
  {}

  WaterWand::~WaterWand(void)
  {}

  void WaterWand::use(int x, int y, World& world)
  {
    for (int i = x - mRadius; i <= x + mRadius; ++i)
      for (int j = y - mRadius; j <= y + mRadius; ++j)
        if (std::pow(i - x, 2) + std::pow(j - y, 2) <= std::pow(mRadius, 2))
          if (rand() % 10 == 0)
            if (world.getWorldImage().getPixel(i, j) == sf::Color::Black)
              world.addParticle(i, j, sf::Color::Cyan);
  }
}