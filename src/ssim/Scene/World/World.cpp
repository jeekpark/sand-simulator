/**
 * @file World.cpp
 * @author Jeekun Park (jeekunp@naver.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-01
 * 
 * @copyright Copyright (c) 2023
 * 
 */



#include "ssim/Scene/World/World.hpp"

namespace Ssim
{
  World::World(const sf::Vector2u& size)
  : mWorldSize(size)
  , mEntropy(0)
  {
    mWorldImage.create(size.x, size.y, sf::Color::Black);
  }

  World::~World(void)
  {}

  void  World::updateWorld(void)
  {
    mEntropy = 0;
    for (unsigned int y = mWorldSize.y - 2; y != std::numeric_limits<unsigned int>::max(); --y)
    {
      for (unsigned int x = 0; x < mWorldSize.x; ++x)
      {
        if (mWorldImage.getPixel(x, y) == sf::Color::Yellow)
        {
          if (mWorldImage.getPixel(x, y + 1) == sf::Color::Black)
          {
            mWorldImage.setPixel(x, y, sf::Color::Black);
            mWorldImage.setPixel(x, y + 1, sf::Color::Yellow);
            ++mEntropy;
            continue;
          }

          if ((mWorldImage.getPixel(x + 1, y + 1) == sf::Color::Black)
              && (mWorldImage.getPixel(x - 1, y + 1) == sf::Color::Yellow))
          {
            mWorldImage.setPixel(x, y, sf::Color::Black);
            mWorldImage.setPixel(x + 1, y + 1, sf::Color::Yellow);
            ++mEntropy;
            continue;
          }

          if ((mWorldImage.getPixel(x - 1, y + 1) == sf::Color::Black)
              && (mWorldImage.getPixel(x + 1, y + 1) == sf::Color::Yellow))
          {
            mWorldImage.setPixel(x, y, sf::Color::Black);
            mWorldImage.setPixel(x - 1, y + 1, sf::Color::Yellow);
            ++mEntropy;
            continue;
          }

          if ((mWorldImage.getPixel(x - 1, y + 1) == sf::Color::Black)
              && (mWorldImage.getPixel(x + 1, y + 1) == sf::Color::Black))
          {
            if (rand() % 2 == 0)
            {
              mWorldImage.setPixel(x, y, sf::Color::Black);
              mWorldImage.setPixel(x - 1, y + 1, sf::Color::Yellow);
              ++mEntropy;
              continue;
            }
            else
            {
              mWorldImage.setPixel(x, y, sf::Color::Black);
              mWorldImage.setPixel(x + 1, y + 1, sf::Color::Yellow);
              ++mEntropy;
              continue;
            }
          }
        }
      }
    }
  }

  std::size_t World::getEntropy(void) const
  {
    return mEntropy;
  }

  const sf::Image& World::getWorldImage(void) const
  {
    return mWorldImage;
  }

  void World::addParticle(unsigned int x, unsigned int y, const sf::Color& color)
  {
    if ((0 <= x && x < mWorldSize.x) && (0 <= y && y < mWorldSize.y))
	  {
	  	mWorldImage.setPixel(x, y, color);
	  }
  }
}
