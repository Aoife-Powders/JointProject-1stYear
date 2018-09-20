#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <ctime>
#include "Player.h"
#include "Enemy.h"

class Bullet
{
public:
	Bullet();

	//classes
	Player m_player;
	Enemy m_enemy;

	void bulletMove();
	void bulletReset();

	//bullet
	sf::RectangleShape m_bulletBody;
	int bulletWidth;
	int bulletHeight;
	sf::Vector2f size{ bulletWidth, bulletHeight };
	float bulletSpeed;
	float bulletX;
	float bulletY;
	bool bulletAlive;
};

