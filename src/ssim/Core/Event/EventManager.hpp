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
#include "ssim/Player/Player.hpp"
#include "ssim/Scene/World/World.hpp"

namespace Ssim
{
  class EventManager
  {
  public:
    EventManager(sf::RenderWindow& window);
    ~EventManager(void);
    
    void handleEventQueue(const UI& pUI, Player& player);
    bool getIsPressing(void) const;
  private:
    sf::RenderWindow& mWindow;
    sf::Event mEvent;
    bool mIsPressing;
  };
}