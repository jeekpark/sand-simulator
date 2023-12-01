/**
 * @file Scene.cpp
 * @author Jeekun Park (jeekunp@naver.com)
 * @brief 
 * @version 0.1
 * @date 2023-11-29
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "ssim/Scene/Scene.hpp"

namespace Ssim
{
  Scene::Scene(sf::RenderWindow& window)
  : mWindow(window)
  {}

  Scene::~Scene(void)
  {}

  void Scene::render(UI& pUI)
  {
    mWindow.draw(pUI.getSandIcon());
    mWindow.draw(pUI.getWaterIcon());
    mWindow.draw(pUI.getEraserIcon());

    mWindow.draw(pUI.getEntropyText());
    mWindow.draw(pUI.getFramePerSecondText());

    mWindow.draw(pUI.getCursor());
  }

  void Scene::render(World& world)
  {
    sf::Texture texture;
    sf::Sprite sprite;

    texture.loadFromImage(world.getWorldImage());
    sprite.setTexture(texture);
    mWindow.draw(sprite);
  }
}

