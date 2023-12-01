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
#include "ssim/Player/Wand/WaterWand.hpp"
#include "ssim/Player/Wand/EraserWand.hpp"
#include "ssim/Scene/World/World.hpp"

namespace Ssim
{
  class Player
  {
  public:
    Player(void);
    ~Player(void);

    enum WandType
    {
      SAND,
      ERASER,
      WATER
    };
    void useWand(int x, int y, World& world);
    void changeTo(WandType wandType);
  private:
    IWand* mCurrentWand;
    SandWand mSandWand;
    EraserWand mEraserWand;
    WaterWand mWaterWand;
  };
}