#pragma once
#include<iostream>
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>

class Coin
{
public:
	Coin();

	void coinMove();

	//coin
	sf::RectangleShape m_coinBody;
	int coinWidth;
	int coinHeight;
	sf::Vector2f size{ coinWidth, coinHeight };
	sf::Vector2f coinPosition;
	float coinX;
	float coinY;
};

