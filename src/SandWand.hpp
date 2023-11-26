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

#include "./IMagicWand.hpp"

class CSandWand : public IMagicWand
{
public:
                CSandWand(void);
                CSandWand(const CSandWand& copy);
  virtual       ~CSandWand(void);
  CSandWand&    operator=(const CSandWand& copy);
  virtual void  use(sf::Image& image, unsigned int x, unsigned int y);
private:
  unsigned int  mRadius;
  unsigned int  mDensity;
};

#endif