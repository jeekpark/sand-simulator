/**
 * @file Player.cpp
 * @author Jeekun Park (jeekunp@naver.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-01
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "ssim/Player/Player.hpp"

namespace Ssim
{
  Player::Player(void)
  {
    mCurrentWand = &mSandWand;
  }

  Player::~Player(void)
  {}

  void Player::useWand(int x, int y, World &world)
  {
    mCurrentWand->use(x, y, world);
  }

  void Player::changeTo(WandType wandType)
  {
    switch (wandType)
    {
    case SAND:
      mCurrentWand = &mSandWand;
      break;
    case ERASER:
      mCurrentWand = &mEraserWand;
      break;
    case WATER:
      mCurrentWand = &mWaterWand;
    default:
      break;
    }
  }
}