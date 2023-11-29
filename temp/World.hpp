/**
 * @file World.hpp
 * @author Jeekun Park (jeekunp@naver.com)
 * @brief 
 * @version 0.1
 * @date 2023-11-27
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once
#ifndef WORLD_HPP
#define WORLD_HPP

#include "SFML/Graphics/Image.hpp"

class CWorld
{
public:
                    CWorld(const sf::Vector2u& size);
                    CWorld(const CWorld& copy);
                    ~CWorld(void);
  CWorld&           operator=(const CWorld& copy);

  void              simulateWorld(void);
  std::size_t       getEntropy(void) const;
  void              addParticle(unsigned int x, unsigned int y, const sf::Color& color);
  const sf::Image&  getWorldImage(void) const;
private:
  sf::Image         mWorldImage;
  sf::Vector2u      mWorldSize;
  std::size_t       mEntropy;
  
  void              simulateSand(void);
  void              simulateWater(void);
};

#endif