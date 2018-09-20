#include "Enemy.h"
#include "Player.h"

//gives values to variables
Enemy::Enemy() :
	enemyWidth{ 50 }
	,enemyHeight{ 50 }
	,enemyPosition{ 20,350 }
	,enemyX{ enemyPosition.x }
	,enemyY{ enemyPosition.y }
	,enemySpeed(1.0f)
{
	//creates enemy
	m_enemyBody.setFillColor(sf::Color::Cyan);
	m_enemyBody.setPosition(enemyPosition);
	m_enemyBody.setSize(size);
	//seed for random generator
	srand(0);
}

//brings all functions together to move enemy
void Enemy::enemyMove(float playerX, float playerY)
{
	if (enemyX > playerX)
	{
		enemyMovementLeft();
	}
	if (enemyX < playerX)
	{
		enemyMovementRight();
	}
	if (enemyY > playerY)
	{
		enemyMovementUp();
	}
	if (enemyY < playerY)
	{
		enemyMovementDown();
	}
}

//moves enemy left
void Enemy::enemyMovementLeft()
{
	enemyX = enemyX - enemySpeed;
	m_enemyBody.setPosition(enemyX, enemyY);
}

//moves enemy right
void Enemy::enemyMovementRight()
{
	enemyX = enemyX + enemySpeed;
	m_enemyBody.setPosition(enemyX, enemyY);
}

//moves enemy up
void Enemy::enemyMovementUp()
{
	enemyY = enemyY - enemySpeed;
	m_enemyBody.setPosition(enemyX, enemyY);
}

//moves enemy down
void Enemy::enemyMovementDown()
{
	enemyY = enemyY + enemySpeed;
	m_enemyBody.setPosition(enemyX, enemyY);
}

//if enemy moves outside the screen it wraps around to the other side
void Enemy::enemyBoundaryRight()
{
	if (enemyX >= 1000)
	{
		enemyX = 10;
		m_enemyBody.setPosition(enemyX, enemyY);
	}
}

void Enemy::enemyBoundaryLeft()
{
	if (enemyX <= 0)
	{
		enemyX = 1000;
		m_enemyBody.setPosition(enemyX, enemyY);
	}
}

void Enemy::enemyBoundaryUp()
{
	if (enemyY <= 0)
	{
		enemyY = 600;
		m_enemyBody.setPosition(enemyX, enemyY);
	}
}

void Enemy::enemyBoundaryDown()
{
	if (enemyY >= 600)
	{
		enemyY = 10;
		m_enemyBody.setPosition(enemyX, enemyY);
	}
}

//changes color of enemy9
void Enemy::enemyChangeColor()
{
	m_enemyBody.setFillColor(sf::Color(rand() % 255, rand() % 255, 255));
}

//resets enemy to a random location when a collision happens
void Enemy::enemyCollision()
{
		enemyX = (rand() % 1000);
		enemyY = (rand() % 600);

		m_enemyBody.setPosition(enemyX, enemyY);
}



