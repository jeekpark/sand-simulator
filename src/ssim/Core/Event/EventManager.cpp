/**
 * @file EventManager.cpp
 * @author Jeekun Park (jeekunp@naver.com)
 * @brief 
 * @version 0.1
 * @date 2023-11-30
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once

#include "ssim/Core/Event/EventManager.hpp"

namespace Ssim
{
  EventManager::EventManager(sf::RenderWindow& window)
  : mWindow(window)
  , mEvent()
  {}

  EventManager::~EventManager(void)
  {}

  void EventManager::handleEventQueue(void)
  {
    while (mWindow.pollEvent(mEvent))
    {
      if (mEvent.type == sf::Event::Closed)
        mWindow.close();
      if (mEvent.type == sf::Event::MouseButtonPressed)
      {
        if (mEvent.mouseButton.button == sf::Mouse::Left)
        {
          
        }
      }
    }
  }
}