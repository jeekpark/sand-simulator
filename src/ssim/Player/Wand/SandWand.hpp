/**
 * @file SandWand.hpp
 * @author Jeekun Park (jeekunp@naver.com)
 * @brief 
 * @version 0.1
 * @date 2023-11-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once
#ifndef SAND_HPP
#define SAND_HPP

#include "ssim/common.hpp"
#include "ssim/Player/Wand/IWand.hpp"
#include "ssim/Scene/World/World.hpp"
namespace Ssim
{
  class SandWand : public IWand
  {
  public:
                  SandWand(void);
                  SandWand(const SandWand& copy);
    virtual       ~SandWand(void);
    SandWand&    operator=(const SandWand& copy);
    virtual void  use(int x, int y, World& world);
  private:
    int  mRadius;
    int  mDensity;
  };
}


#endif