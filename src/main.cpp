/**
 * @file main.cpp
 * @author Jeekun Park (jeekunp@naver.com)
 * @brief 
 * @version 0.1
 * @date 2023-11-25
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <iostream>
#include "SFML/Graphics/Color.hpp"
#include "SFML/Graphics/Image.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Window/Event.hpp"
#include "SFML/Window/Mouse.hpp"

#include "SandWand.hpp"
int main()
{
  CSandWand wand;
  std::srand(std::time(0));
  sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
  window.setFramerateLimit(60);
  sf::Image image;
  image.create(800,600, sf::Color::Black);
  image.setPixel(400, 300, sf::Color::Yellow);

  sf::Texture texture;
  sf::Sprite sprite;
  bool  leftState = false;
  while(window.isOpen())
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
      wand.use(image, pos.x, pos.y);
    }
    for (int x = 0; x < 800; ++x)
    {
      for (int y = 599; y >= 0; --y)
      {
        if (image.getPixel(x, y) == sf::Color::Yellow)
        {
          if (image.getPixel(x, y + 1) == sf::Color::Black)
          {
            image.setPixel(x, y, sf::Color::Black);
            image.setPixel(x, y + 1, sf::Color::Yellow);
          }
          else if (image.getPixel(x + 1, y + 1) == sf::Color::Black)
          {
            if (rand() % 2 == 0)
            {
              image.setPixel(x, y, sf::Color::Black);
              image.setPixel(x + 1, y + 1, sf::Color::Yellow);
            }
          }
          else if (image.getPixel(x - 1, y + 1) == sf::Color::Black)
          {
            if (rand() % 2  == 0)
            {
              image.setPixel(x, y, sf::Color::Black);
              image.setPixel(x - 1, y + 1, sf::Color::Yellow);
            }
          }
        }
      }
    }
    texture.loadFromImage(image);
    sprite.setTexture(texture);
    window.clear();
    window.draw(sprite);
    window.display();
  }
}