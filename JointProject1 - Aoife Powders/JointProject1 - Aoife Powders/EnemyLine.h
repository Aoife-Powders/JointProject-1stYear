#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
class EnemyLine
{


public:
	EnemyLine();

	//array declaration
	static const int MAX_ENEMYS = 3;
	sf::RectangleShape enemys[MAX_ENEMYS];

	//class functions
	void enemysArray();

	void enemysMove();
	void enemysOneLeft();
	void enemysTwoLeft();
	void enemysThreeLeft();
	void enemysOneRight();
	void enemysTwoRight();
	void enemysThreeRight();
	
	//enemy
	sf::RectangleShape m_enemyLineBody;
	int enemyWidth;
	int enemyHeight;
	sf::Vector2f size{ enemyWidth, enemyHeight };
	float speed;
};

