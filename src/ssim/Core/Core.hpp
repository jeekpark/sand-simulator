/**
 * @file Core.hpp
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
#include "ssim/Core/Event/EventManager.hpp"

namespace Ssim
{
  /**
   * @brief Core class of game
   * 
   */
  class Core
  {
  public:
    /**
     * @brief Construct a new Core object
     * 
     */
    Core(void);

    /**
     * @brief Destroy the Core object
     * 
     */
    ~Core(void);

    /**
     * @brief Runnig loop
     * 
     */
    void run(void);

    /**
     * @brief Closes app
     * 
     */
    void close(void);

  private:
    void onGameUpdate(void);
  private:
    bool mIsRunning = true;
    bool mIsPaused = false;
    sf::RenderWindow mWindow;
    std::string mWindowTitle;
    EventManager mEventManager;

  };
}