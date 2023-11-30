/**
 * @file Player.hpp
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
#include "ssim/Player/Wand/SandWand.hpp"
#include "ssim/Scene/World/World.hpp"

namespace Ssim
{
  class Player
  {
  public:
    Player(void);
    ~Player(void);

    void useWand(int x, int y, World& world);
    void changeToSandWand(void);
  private:
    IWand* mCurrentWnad;
    SandWand mSandWand;
  };
}