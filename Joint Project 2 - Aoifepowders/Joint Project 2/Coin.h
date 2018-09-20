#pragma once

#include "SFML\Graphics.hpp"

class Coin
{
public:
	void setUpCoin();
	void coinCollision();

	sf::RectangleShape coin;
	sf::Vector2f size = { 20,20 };
	int coinRow = 1;
	int coinCol = 1;
};

