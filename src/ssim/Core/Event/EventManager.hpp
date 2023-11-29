/**
 * @file EventManager.hpp
 * @author Jeekun Park (jeekunp@naver.com)
 * @brief 
 * @version 0.1
 * @date 2023-11-30
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once

#include "ssim/common.hpp"

namespace Ssim
{
  class EventManager
  {
  public:
    EventManager(sf::Window& window);
    ~EventManager(void);
    
    bool isPollEvent(void);
    bool isClosedEvent(void);
    bool isMouseButtonEvent(void);
  private:
    sf::Window& mWindow;
    sf::Event mEvent;
  };
}