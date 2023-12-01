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

#include "ssim/Core/Event/EventManager.hpp"

namespace Ssim
{
  EventManager::EventManager(sf::RenderWindow& window)
  : mWindow(window)
  , mEvent()
  , mIsPressing(false)
  {}

  EventManager::~EventManager(void)
  {}

  void EventManager::handleEventQueue(UI& pUI, Player& player)
  {
    while (mWindow.pollEvent(mEvent))
    {
      if (mEvent.type == sf::Event::Closed)
        mWindow.close();
      if (mEvent.type == sf::Event::MouseButtonPressed)
      {
        if (mEvent.mouseButton.button == sf::Mouse::Left)
        {
          sf::Vector2i mousePos = sf::Mouse::getPosition(mWindow);
          if (pUI.getSandIcon().getGlobalBounds().contains(mousePos.x, mousePos.y))
          {
            player.changeTo(Player::SAND);
            pUI.setCursorColor(sf::Color::Yellow);
          }
          else if (pUI.getEraserIcon().getGlobalBounds().contains(mousePos.x, mousePos.y))
          {
            player.changeTo(Player::ERASER);
            pUI.setCursorColor(sf::Color::White);
          }
          else if (pUI.getWaterIcon().getGlobalBounds().contains(mousePos.x, mousePos.y))
          {
            player.changeTo(Player::WATER);
            pUI.setCursorColor(sf::Color::Cyan);
          }
          else
          {
            mIsPressing = true;
          }
        }
      }
      else if (mEvent.type == sf::Event::MouseButtonReleased)
      {
        if (mEvent.mouseButton.button == sf::Mouse::Left)
        {
          mIsPressing = false;
        }
      }
    }
  }

  bool EventManager::getIsPressing(void) const
  {
    return mIsPressing;
  }
}