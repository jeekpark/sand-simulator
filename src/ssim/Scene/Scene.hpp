/**
 * @file Scene.hpp
 * @author Jeekun Park (jeekunp@naver.com)
 * @brief 
 * @version 0.1
 * @date 2023-11-29
 * 
 * @copyright Copyright (c) 2023
 * 
 */


#include "ssim/common.hpp"

#include "ssim/UI/UI.hpp"
#include "ssim/Scene/World/World.hpp"

namespace Ssim
{
  class Scene
  {
  public:
    Scene(sf::RenderWindow& window);
    ~Scene();
    void render(UI& pUI);
    void render(World& world);
  private:
    sf::RenderWindow& mWindow;
  };
}