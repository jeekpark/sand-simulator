/**
 * @file Core.cpp
 * @author Jeekun Park (jeekunp@naver.com)
 * @brief 
 * @version 0.1
 * @date 2023-11-29
 * 
 * @copyright Copyright (c) 2023
 * 
 */


#include "ssim/Core/Core.hpp"

namespace Ssim
{
  Core::Core(void)
  : mIsRunning(true)
  , mWindow()
  , mWindowTitle("sand-simulator")
  , mWorld(sf::Vector2u(WINDOW_X, WINDOW_Y))
  , mPlayer()
  , mUI(mWorld.getEntropy())
  , mEventManager(mWindow)
  , mScene(mWindow)
  {
    std::srand(static_cast<unsigned int>(std::time((time_t*)0)));
    mWindowTitle.append(SSIM_VERSION);
    mWindow.create(sf::VideoMode(WINDOW_X, WINDOW_Y), mWindowTitle);
    mWindow.setFramerateLimit(60);
  }

  Core::~Core(void)
  {
    mWindow.close();
    mIsRunning = false;
  }

  void Core::run(void)
  {
    while (mWindow.isOpen())
    {
      mEventManager.handleEventQueue(mUI, mPlayer);
      sf::Vector2i pos = sf::Mouse::getPosition(mWindow);
      if (mEventManager.getIsPressing())
      {
        mPlayer.useWand(pos.x, pos.y, mWorld);
      }
      mUI.setCursorPosition(pos.x, pos.y);
      mWorld.updateWorld();
      mWindow.clear();
      mScene.render(mWorld);
      mScene.render(mUI);
      mWindow.display();
    } 
  }

  void Core::close(void)
  {
    mWindow.close();
  }
}