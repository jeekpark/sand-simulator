/**
 * @file WaterWand.hpp
 * @author Jeekun Park (jeekunp@naver.com)
 * @brief 
 * @version 0.1
 * @date 2023-11-28
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once
#ifndef WATERWAND_HPP
#define WATERWAND_HPP

#include "./IMagicWand.hpp"
#include "./World.hpp"
class CWaterWand : public IMagicWand
{
public:
                CWaterWand(void);
                CWaterWand(const CWaterWand& copy);
  virtual       ~CWaterWand(void);
  CWaterWand&   operator=(const CWaterWand& copy);
  virtual void  use(int x, int y, CWorld& world);
private:
  int  mRadius;
  int  mDensity;
};

#endif