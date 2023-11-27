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


#include <cstdlib>
#include <ctime>
#include <iostream>

#include "SFML/Graphics/Color.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/System/Vector2.hpp"
#include "SFML/Window/Mouse.hpp"
#include "SFML/Window/VideoMode.hpp"
#include "SFML/Window/WindowBase.hpp"
#include "SFML/Window/Event.hpp"

#include "./World.hpp"
#include "./SandWand.hpp"

int main(const int, const char**)
{
  std::srand(std::time(0));
	sf::RenderWindow window(sf::VideoMode(800, 600), "sand-simulator");
	window.setFramerateLimit(60);

	CSandWand wand;
	CWorld world(window.getSize());

	sf::Texture texture;
	sf::Sprite sprite;
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
			wand.use(pos.x, pos.y, world);
		}
		
		world.simulateWorld();

		texture.loadFromImage(world.getWorldImage());
		sprite.setTexture(texture);
    window.clear();
    window.draw(sprite);
    window.display();
	}
}