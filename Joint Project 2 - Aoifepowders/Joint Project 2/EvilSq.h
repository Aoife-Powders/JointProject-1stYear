#pragma once
#include "SFML\Graphics.hpp"

class EvilSq
{
	
public:
	//functiond
	void evilSqSetUp();

	sf::RectangleShape evilSq;

	sf::Vector2f size = { 50, 50 };
	
	//sets up row and column for enemies to keep track of them in the world map
	int row = 10;
	int col = 10;

};
