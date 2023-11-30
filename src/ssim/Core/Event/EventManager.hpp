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
#include "ssim/UI/UI.hpp"

namespace Ssim
{
  class EventManager
  {
  public:
    EventManager(sf::RenderWindow& window);
    ~EventManager(void);
    
    void handleEventQueue(void);
  private:
    sf::RenderWindow& mWindow;
    Ssim::UI& mUI;
    sf::Event mEvent;
    bool mIsPressing;

  };
}