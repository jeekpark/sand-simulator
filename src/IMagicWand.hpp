/**
 * @file IMagitWand.hpp
 * @author Jeekun Park (jeekunp@naver.com)
 * @brief 
 * @version 0.1
 * @date 2023-11-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once
#ifndef IMAGICWAND_HPP
#define IMAGICWAND_HPP

class CWorld;

class IMagicWand
{
public:
  virtual       ~IMagicWand(void) {}
  virtual void  use(unsigned int x, unsigned int y, CWorld& world) = 0;
};


#endif