/**
 * @file UI.cpp
 * @author Jeekun Park (jeekunp@naver.com)
 * @brief 
 * @version 0.1
 * @date 2023-11-29
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "ssim/UI/UI.hpp"

namespace Ssim
{
  UI::UI(const std::size_t& entropy)
  : mEntropy(entropy)
  {
    mMainFont.loadFromFile(GLOBAL_FONT_PATH);
    mEntropyText.setFont(mMainFont);
    mEntropyText.setCharacterSize(20);
    mEntropyText.setFillColor(sf::Color::White);
    mEntropyText.setPosition(10, 10);
    std::stringstream ss;
    ss << mEntropy;
    mEntropyText.setString(ss.str());
    mSandIcon = sf::RectangleShape(sf::Vector2f(100, 100));
    mSandIcon.setPosition(WINDOW_X - 150, 50);
    mSandIcon.setFillColor(sf::Color::Yellow);
    mSandIcon.setOutlineColor(sf::Color::White);
    mWaterIcon = sf::RectangleShape(sf::Vector2f(100, 100));
    mWaterIcon.setPosition(WINDOW_X - 260, 50);
    mWaterIcon.setFillColor(sf::Color::Cyan);
    mWaterIcon.setOutlineColor(sf::Color::White);
    mSandIcon = sf::RectangleShape(sf::Vector2f(100, 100));
    mSandIcon.setPosition(WINDOW_X - 370, 50);
    mSandIcon.setFillColor(sf::Color::Black);
    mSandIcon.setOutlineColor(sf::Color::White);
  }

  UI::~UI(void)
  {

  }

  const sf::Text& UI::getEntropyText(void) const
  { return mEntropyText; }

  const sf::RectangleShape& UI::getSandIcon(void) const
  { return mSandIcon; }

  const sf::RectangleShape& UI::getWaterIcon(void) const
  { return mWaterIcon; }

  const sf::RectangleShape& UI::getEraserIcon(void) const
  { return mEraserIcon; }
}