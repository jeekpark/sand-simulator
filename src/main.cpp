/**
 * @file main.cpp
 * @author Jeekun Park (jeekunp@naver.com)
 * @brief 
 * @version 0.1
 * @date 2023-11-27
 * 
 * @copyright Copyright (c) 2023
 * 
 */


#include "ssim/Ssim.hpp"

int main(const int, const char**)
{
  Ssim::Core* game = new Ssim::Core();
  game->run();
  delete game;

  return 0;
}

/* #include <cstdlib>
#include <ctime>
#include <iostream>

#include "IMagicWand.hpp"
#include "SFML/Graphics/Color.hpp"
#include "SFML/Graphics/Font.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Text.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/System/Vector2.hpp"
#include "SFML/Window/Mouse.hpp"
#include "SFML/Window/VideoMode.hpp"
#include "SFML/Window/WindowBase.hpp"
#include "SFML/Window/Event.hpp"
#include <SFML/Graphics.hpp>
#include <sstream>

#include "./World.hpp"
#include "./SandWand.hpp"
#include "WaterWand.hpp"




int main(const int, const char**)
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "sand-simulator");
  sf::Texture texture;
	sf::Sprite sprite;
  sf::Font font;
  sf::Text textEntropy;

  window.setFramerateLimit(60);
  font.loadFromFile("./resources/Minecraft.ttf");
  textEntropy.setFont(font);
  textEntropy.setCharacterSize(20);
  textEntropy.setFillColor(sf::Color::White);
  textEntropy.setPosition(10, 10);

	CSandWand* sandWand = new CSandWand();
  CWaterWand* waterWand = new CWaterWand();
	CWorld world(window.getSize());

	IMagicWand* wand = sandWand;
  
  int cnt = 0;
	bool leftState = false;
	while (window.isOpen())
	{
		sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
        window.close();
      if (event.type == sf::Event::MouseButtonPressed)
      {
        if (event.mouseButton.button == sf::Mouse::Left)
        {
          leftState = true;
        }
        else if (event.mouseButton.button == sf::Mouse::Right)
        {
          if (cnt % 2 == 0) wand = waterWand;
          else wand = sandWand;
          ++cnt;
        }
      }
      if (event.type == sf::Event::MouseButtonReleased)
      {
        if (event.mouseButton.button == sf::Mouse::Left)
        {
          leftState = false;
        }
      }
    }
		if (leftState == true)
		{
			sf::Vector2i pos = sf::Mouse::getPosition(window);
			wand->use(pos.x, pos.y, world);
		}
		
		world.simulateWorld();
    std::stringstream ss;
    ss << world.getEntropy();
    textEntropy.setString(ss.str());
		texture.loadFromImage(world.getWorldImage());
		sprite.setTexture(texture);
    window.clear();
    window.draw(sprite);
    window.draw(textEntropy);
    window.display();
	}
  delete waterWand;
  delete sandWand;

  return 0;
} */