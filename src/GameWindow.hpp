/**
 * @file GameWindow.hpp
 * @author Jeekun Park (jeekunp@naver.com)
 * @brief 
 * @version 0.1
 * @date 2023-11-25
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once
#ifndef GAME_WINDOW_HPP

#include <SFML/Graphics.hpp>

class CGameWindow
{
public:
  static CGameWindow& getInstance(void);
                      CGameWindow(const CGameWindow&) = delete;
                      
private:
  
};

#endif