/**
 * @file EraserWand.cpp
 * @author Jeekun Park (jeekunp@naver.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-01
 * 
 * @copyright Copyright (c) 2023
 * 
 */



#include "ssim/Player/Wand/EraserWand.hpp"


namespace Ssim
{
  EraserWand::EraserWand(void)
  : mRadius(20)
  {}

  EraserWand::~EraserWand(void)
  {}

  void EraserWand::use(int x, int y, World &world)
  {
    for (int i = x - mRadius; i <= x + mRadius; ++i)
      for (int j = y - mRadius; j <= y + mRadius; ++j)
        if (std::pow(i - x, 2) + std::pow(j - y, 2) <= std::pow(mRadius, 2))
          world.addParticle(i, j, sf::Color::Black);
  }
}