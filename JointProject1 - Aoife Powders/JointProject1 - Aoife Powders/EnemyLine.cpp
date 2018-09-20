#include "EnemyLine.h"

//gives values to variables
EnemyLine::EnemyLine() :
		enemyWidth{40}
	,enemyHeight{40}
	,speed{5.0f}
{
}

//sets up enemy array
void EnemyLine::enemysArray()
{
	enemys[0].setPosition(20, 50);
	enemys[0].setFillColor(sf::Color::Magenta);
	enemys[0].setSize(size);

	enemys[1].setPosition(20, 150);
	enemys[1].setFillColor(sf::Color::Magenta);
	enemys[1].setSize(size);

	enemys[2].setPosition(20, 250);
	enemys[2].setFillColor(sf::Color::Magenta);
	enemys[2].setSize(size);

}

//function moves enemys left
void EnemyLine::enemysOneLeft()
{
	int enemyLineX = enemys[0].getPosition().x;
	speed = speed * -1; 
	enemyLineX -= speed;
	enemys[0].setPosition(enemyLineX, enemys[0].getPosition().y);
	
}

void EnemyLine::enemysTwoLeft()
{
	int enemyLineX = enemys[1].getPosition().x;
	speed = speed * -1;
	enemyLineX -= speed;
	enemys[1].setPosition(enemyLineX, enemys[1].getPosition().y);
}

void EnemyLine::enemysThreeLeft()
{
	int enemyLineX = enemys[2].getPosition().x;
	speed = speed * -1;
	enemyLineX -= speed;
	enemys[2].setPosition(enemyLineX, enemys[2].getPosition().y);
}

//functions moves enemys right
void EnemyLine::enemysOneRight()
{
	int enemyLineX = enemys[0].getPosition().x;
	enemyLineX += speed;
	enemys[0].setPosition(enemyLineX, enemys[0].getPosition().y);
	
	if (enemys[0].getPosition().x >= 925 || enemys[0].getPosition().x <= 10)
	{
		speed = speed * -1;
	}
	
}


void EnemyLine::enemysTwoRight()
{
	int enemyLineX = enemys[1].getPosition().x;
	//speed = speed * -1;
	enemyLineX += speed;
	enemys[1].setPosition(enemyLineX, enemys[1].getPosition().y);
	if (enemys[1].getPosition().x >= 925 || enemys[1].getPosition().x <= 10)
	{
		speed = speed * -1;
	}
}

void EnemyLine::enemysThreeRight()
{
	int enemyLineX = enemys[2].getPosition().x;
	//speed = speed * -1;
	enemyLineX += speed;
	enemys[2].setPosition(enemyLineX, enemys[2].getPosition().y);
	if (enemys[2].getPosition().x >= 925 || enemys[2].getPosition().x <= 10)
	{
		speed = speed * -1;
	}
}

//brings all functions together to move the enemy
void EnemyLine::enemysMove()
{
	for (int i = 0; i <= MAX_ENEMYS; i++)
	{
		int enemyLineX = enemys[i].getPosition().x;

		if (enemyLineX <= 10)
		{
			enemysOneRight();
			enemysTwoRight();
			enemysThreeRight();
		}
		if (enemyLineX >= 950)
		{
			enemysOneLeft();
			enemysTwoLeft();
			enemysThreeLeft();
		}
	}
}

