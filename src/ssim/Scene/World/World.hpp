/**
 * @file World.hpp
 * @author Jeekun Park (jeekunp@naver.com)
 * @brief 
 * @version 0.1
 * @date 2023-11-29
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once
#include "ssim/common.hpp"

namespace Ssim
{
  class World
  {
  public:
    World(const sf::Vector2u& size);
    ~World(void);
    void updateWorld(void);
    const std::size_t& getEntropy(void) const;
    const sf::Image& getWorldImage(void) const;
    void addParticle(unsigned int x, unsigned int y, const sf::Color& color);
  private:
    sf::Image mWorldImage;
    sf::Vector2u mWorldSize;
    std::size_t mEntropy;
  private:
    void updateWorldByLine(int y);

    void simulateGravityByLine(int y);
    void simulateSlideByLine(int y);
  };
}
