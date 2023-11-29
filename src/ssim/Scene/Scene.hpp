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



namespace Ssim
{
  class Scene
  {
  public:
    Scene(sf::RenderWindow& window);
    ~Scene();
  private:
    sf::RenderWindow& mWindow;
    
    sf::Texture texture;
	  sf::Sprite sprite;
    sf::Font font;
    sf::Text textEntropy;
  };
}