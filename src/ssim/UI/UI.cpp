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
    float XOffSet = 10.0f;
    float YOffSet = 10.0f;
    mMainFont.loadFromFile(GLOBAL_FONT_PATH);
    mEntropyText.setFont(mMainFont);
    mEntropyText.setCharacterSize(20);
    mEntropyText.setFillColor(sf::Color::White);
    mEntropyText.setPosition(XOffSet, YOffSet);
    std::stringstream ss;
    ss << mEntropy;
    mEntropyText.setString(ss.str());

    mSandIcon = sf::RectangleShape(sf::Vector2f(100, 100));
    mSandIcon.setPosition(WINDOW_X - 100 - XOffSet, YOffSet);
    mSandIcon.setFillColor(sf::Color::Yellow);
    mSandIcon.setOutlineColor(sf::Color::White);
    mSandIcon.setOutlineThickness(1.0f);

    mWaterIcon = sf::RectangleShape(sf::Vector2f(100, 100));
    mWaterIcon.setPosition(WINDOW_X - 200 - XOffSet * 2, YOffSet);
    mWaterIcon.setFillColor(sf::Color::Cyan);
    mWaterIcon.setOutlineColor(sf::Color::White);
    mWaterIcon.setOutlineThickness(1.0f);

    mEraserIcon = sf::RectangleShape(sf::Vector2f(100, 100));
    mEraserIcon.setPosition(WINDOW_X - 300 - XOffSet * 3, YOffSet);
    mEraserIcon.setFillColor(sf::Color::Black);
    mEraserIcon.setOutlineColor(sf::Color::White);
    mEraserIcon.setOutlineThickness(1.0f);

    mCursor.setRadius(20);
    mCursor.setOutlineThickness(1.0f);
    mCursor.setOutlineColor(sf::Color::Yellow);
    mCursor.setFillColor(sf::Color::Transparent);
    mCursor.setPosition(100, 100);
  }

  UI::~UI(void)
  {

  }

  const sf::Text& UI::getEntropyText(void)
  {
    std::stringstream ss;
    ss << "Entropy: " << mEntropy;
    mEntropyText.setString(ss.str());
    return mEntropyText;
  }

  const sf::RectangleShape& UI::getSandIcon(void) const
  { return mSandIcon; }

  const sf::RectangleShape& UI::getWaterIcon(void) const
  { return mWaterIcon; }

  const sf::RectangleShape& UI::getEraserIcon(void) const
  { return mEraserIcon; }

  const sf::CircleShape& UI::getCursor(void) const
  { return mCursor; }

  void UI::setCursorColor(sf::Color color)
  {
    mCursor.setOutlineColor(color);
  }

  void UI::setCursorPosition(int x, int y)
  {
    mCursor.setPosition(x - 20, y - 20);
  }
}