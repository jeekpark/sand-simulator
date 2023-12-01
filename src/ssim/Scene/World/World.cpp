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
      updateWorldByLine(y);
      /* for (unsigned int x = 0; x < mWorldSize.x; ++x)
      {
        if (mWorldImage.getPixel(x, y) == sf::Color::Yellow)
          simulateSand(x, y);
        else if (mWorldImage.getPixel(x, y) == sf::Color::Cyan)
          simulateWater(x, y);
      } */
    }
  }

  const std::size_t& World::getEntropy(void) const
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


  void World::updateWorldByLine(int y)
  {
    for (int x = 0; x < static_cast<int>(mWorldSize.x); ++x)
    {
      if (mWorldImage.getPixel(x, y) == sf::Color::Yellow && mWorldImage.getPixel(x, y + 1) == sf::Color::Black)
      {
        mWorldImage.setPixel(x, y, sf::Color::Black);
        mWorldImage.setPixel(x, y + 1, sf::Color::Yellow);
      }
      else if (mWorldImage.getPixel(x, y) == sf::Color::Yellow && mWorldImage.getPixel(x, y + 1) == sf::Color::Cyan)
      {
        ;
      }
      else if (mWorldImage.getPixel(x, y) == sf::Color::Cyan && mWorldImage.getPixel(x, y + 1) == sf::Color::Black)
      {
        mWorldImage.setPixel(x, y, sf::Color::Black);
        mWorldImage.setPixel(x, y + 1, sf::Color::Cyan);
      }
      else if (x != 0 && mWorldImage.getPixel(x, y) == sf::Color::Cyan && mWorldImage.getPixel(x, y + 1) != sf::Color::Black
               && mWorldImage.getPixel(x - 1, y) == sf::Color::Black && mWorldImage.getPixel(x + 1, y) != sf::Color::Black)
      {
        mWorldImage.setPixel(x, y, sf::Color::Black);
        mWorldImage.setPixel(x - 1, y, sf::Color::Cyan);
      }
      else if (x < static_cast<int>(mWorldSize.x) - 1 && mWorldImage.getPixel(x, y) == sf::Color::Cyan && mWorldImage.getPixel(x, y + 1) != sf::Color::Black
               && mWorldImage.getPixel(x - 1, y) != sf::Color::Black && mWorldImage.getPixel(x + 1, y) == sf::Color::Black)
      {
        mWorldImage.setPixel(x, y, sf::Color::Black);
        mWorldImage.setPixel(x + 1, y, sf::Color::Cyan);
        ++x;
      }
      else if (x != 0 && x < static_cast<int>(mWorldSize.x) - 1 && mWorldImage.getPixel(x, y) == sf::Color::Cyan && mWorldImage.getPixel(x, y + 1) != sf::Color::Black
               && mWorldImage.getPixel(x - 1, y) == sf::Color::Black && mWorldImage.getPixel(x + 1, y) == sf::Color::Black)
      {
        int randomValue = rand() % 3;
        if (randomValue == 0)
        {
          mWorldImage.setPixel(x, y, sf::Color::Black);
          mWorldImage.setPixel(x - 1, y, sf::Color::Cyan);
        }
        else if (randomValue == 1)
        {
          mWorldImage.setPixel(x, y, sf::Color::Black);
          mWorldImage.setPixel(x + 1, y, sf::Color::Cyan);
          x++;
        }
        else ;
      }
    }
  }


}
