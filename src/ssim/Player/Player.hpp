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
  private:
    IWand* mCurrentWnad;
    SandWand mSandWand;
  };
}