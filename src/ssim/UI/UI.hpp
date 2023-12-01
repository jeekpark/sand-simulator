/**
 * @file UI.hpp
 * @author Jeekun Park (jeekunp@naver.com)
 * @brief 
 * @version 0.1
 * @date 2023-11-29
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once
#include "ssim/common.hpp"

namespace Ssim
{
  class UI
  {
  public:
    UI(const std::size_t& entropy);
    ~UI(void);
    const sf::Text& getEntropyText(void);
    const sf::RectangleShape& getSandIcon(void) const;
    const sf::RectangleShape& getWaterIcon(void) const;
    const sf::RectangleShape& getEraserIcon(void) const;
    const sf::CircleShape& getCursor(void) const;
    const sf::Text& getFramePerSecondText(void);

    void setCursorColor(sf::Color color);
    void setCursorPosition(int x, int y);

  private:
    const std::size_t& mEntropy;
    sf::Font mMainFont;
    sf::Text mEntropyText;
    sf::RectangleShape mSandIcon;
    sf::RectangleShape mWaterIcon;
    sf::RectangleShape mEraserIcon;
    sf::CircleShape mCursor;
    float mFrameCount;
    sf::Text mFramePerSecondText;
    sf::Clock mClork;

  };
}