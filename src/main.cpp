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
#include "../include/sand.hpp"
 int main()
 {
  sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
        window.close();
    }
    window.clear();
    window.display();
  }
 }