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
  : mEventManager(mWindow)
  {
    std::srand(static_cast<unsigned int>(std::time((time_t*)0)));
    mWindowTitle = "sand-simulator";
    mWindowTitle.append(SSIM_VERSION);
    mWindow.create(sf::VideoMode(WINDOW_X, WINDOW_Y), mWindowTitle);
    mIsRunning = true;
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
      mEventManager.handleEventQueue();

    }
  }
}