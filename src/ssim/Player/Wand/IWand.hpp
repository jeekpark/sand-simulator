/**
 * @file IWand.hpp
 * @author Jeekun Park (jeekunp@naver.com)
 * @brief 
 * @version 0.1
 * @date 2023-11-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once

namespace Ssim
{
  class World;

  class IWand
  {
  public:
    virtual       ~IWand(void) {}
    virtual void  use(int x, int y, World& world) = 0;
  };
}
