#pragma once

#include <iostream>
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include "Player.h"
#include <ctime>

class Enemy
{
public:
	Enemy();

	//sets up functions
	void enemyMove(float playerX, float playerY );
	void enemyMovementLeft();
	void enemyMovementRight();
	void enemyMovementUp();
	void enemyMovementDown();

	void enemyBoundaryRight();
	void enemyBoundaryLeft();
	void enemyBoundaryUp();
	void enemyBoundaryDown();

	void enemyChangeColor();

	void enemyCollision();

	//variable declarations
	sf::RectangleShape m_enemyBody;
	sf::Vector2f enemyPosition;
	int enemyWidth;
	int enemyHeight;
	sf::Vector2f size{ enemyWidth, enemyHeight };
	float enemyX;
	float enemyY;
	float enemySpeed;
};

