/**
 * @file WaterWand.hpp
 * @author Jeekun Park (jeekunp@naver.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-01
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once

#include "ssim/common.hpp"

#include "ssim/Player/Wand/IWand.hpp"
#include "ssim/Scene/World/World.hpp"

namespace Ssim
{
  class WaterWand : public IWand
  {
  public:
    WaterWand(void);
    virtual ~WaterWand(void);
    virtual void use(int x, int y, World& world);
  private:
    int mRadius;
  };
}