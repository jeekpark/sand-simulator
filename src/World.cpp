/**
 * @file World.cpp
 * @author Jeekun Park (jeekunp@naver.com)
 * @brief 
 * @version 0.1
 * @date 2023-11-27
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "./World.hpp"
#include "SFML/Graphics/Color.hpp"
#include "SFML/System/Vector2.hpp"
#include <cstdlib>
#include <iostream>
#include <limits>
#include <random>
#include <sys/_types/_size_t.h>

CWorld::CWorld(const sf::Vector2u& size)
: mWorldSize(size)
, mEntropy(0)
{
	mWorldImage.create(size.x, size.y, sf::Color::Black);
}

CWorld::CWorld(const CWorld& copy)
: mWorldImage(copy.mWorldImage)
, mWorldSize(copy.mWorldSize)
, mEntropy(copy.mEntropy)
{}

CWorld::~CWorld(void)
{}

CWorld& CWorld::operator=(const CWorld& copy)
{
	if (this != &copy)
	{
		mWorldImage = copy.mWorldImage;
		mWorldSize = copy.mWorldSize;
		mEntropy = copy.mEntropy;
	}
	return *this;
}

void CWorld::simulateWorld(void)
{
	std::random_device rd;
  std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(0, 2);
	mEntropy = 0;
	for (unsigned int y = mWorldSize.y - 2; y != std::numeric_limits<unsigned int>::max(); --y)
	{
		for (unsigned int x = 0; x < mWorldSize.x; ++x)
		{
			if (mWorldImage.getPixel(x, y) == sf::Color::Yellow)
			{
				if (mWorldImage.getPixel(x, y + 1) == sf::Color::Black)
				{
					mWorldImage.setPixel(x, y, sf::Color::Black);
					mWorldImage.setPixel(x, y + 1, sf::Color::Yellow);
					if (mEntropy != std::numeric_limits<std::size_t>::max()) ++mEntropy;
					continue;
				}

				if ((mWorldImage.getPixel(x - 1, y + 1) == sf::Color::Black)
										&& (mWorldImage.getPixel(x + 1, y + 1) == sf::Color::Black))
				{
					if (dist(mt) == 0)
					{
						mWorldImage.setPixel(x, y, sf::Color::Black);
						mWorldImage.setPixel(x - 1, y + 1, sf::Color::Yellow);
						if (mEntropy != std::numeric_limits<std::size_t>::max()) ++mEntropy;
					}
					else
					{
						mWorldImage.setPixel(x, y, sf::Color::Black);
						mWorldImage.setPixel(x + 1, y + 1, sf::Color::Yellow);
						if (mEntropy != std::numeric_limits<std::size_t>::max()) ++mEntropy;
					}
					continue;
				}

				if (mWorldImage.getPixel(x - 1, y + 1) == sf::Color::Black)
				{
					mWorldImage.setPixel(x, y, sf::Color::Black);
					mWorldImage.setPixel(x - 1, y + 1, sf::Color::Yellow);
					if (mEntropy != std::numeric_limits<std::size_t>::max()) ++mEntropy;
				}
				if (mWorldImage.getPixel(x + 1, y + 1) == sf::Color::Black)
				{
					mWorldImage.setPixel(x, y, sf::Color::Black);
					mWorldImage.setPixel(x + 1, y + 1, sf::Color::Yellow);
					if (mEntropy != std::numeric_limits<std::size_t>::max()) ++mEntropy;
				}
			}
		}
	}
}

std::size_t CWorld::getEntropy(void) const
{
	return mEntropy;
}

void CWorld::addParticle(unsigned int x, unsigned int y, const sf::Color& color)
{
	if ((0 <= x && x < mWorldSize.x) && (0 <= y && y < mWorldSize.y))
	{
		mWorldImage.setPixel(x, y, color);
	}
}

const sf::Image& CWorld::getWorldImage(void) const
{
	return mWorldImage;
}




void CWorld::simulate