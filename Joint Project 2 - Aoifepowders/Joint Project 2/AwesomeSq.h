#pragma once

#include "SFML\Graphics.hpp"

class AwesomeSq
{
	
public:
	//functions
	void setUpAwesomeSq();
	void awesomeSqMoveUp();
	void awesomeSqMoveDown();
	void awesomeSqMoveRight();
	void awesomeSqMoveLeft();

	//variables
	sf::RectangleShape awesomeSq;
	sf::Vector2f size = { 50,50 };
	int playerRow = 1;
	int playerCol = 1;
	

};