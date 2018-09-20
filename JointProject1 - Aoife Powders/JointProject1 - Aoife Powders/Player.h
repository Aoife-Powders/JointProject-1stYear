#pragma once

#include <iostream>
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include "Enemy.h"


class Player
{
public:
	Player();

	//functions
	void playerMovementUp();
	void playerMovementDown();
	void playerMovementRight();
	void playerMovementLeft();

	void playerBoundaryRight();
	void playerBoundaryLeft();
	void playerBoundaryUp();
	void playerBoundaryDown();

	void playerEnemyCollision();


	//player
	sf::RectangleShape m_playerBody;
	sf::Vector2f playerPosition;
	int playerWidth;
	int playerHeight;
	sf::Vector2f size{ playerWidth, playerHeight };
	float playerX;
	float playerY;
	float playerSpeed;
};

