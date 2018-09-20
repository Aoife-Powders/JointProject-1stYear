#include "Bullet.h"
#include "Player.h"
#include "Enemy.h"

//gives values to variables
Bullet::Bullet() :
	bulletWidth{ 10 }
	, bulletHeight{ 10 }
	, bulletX{ m_player.playerPosition.x }
	, bulletY{ m_player.playerPosition.y }
	, bulletSpeed(10.0f)
	, bulletAlive{false}
{
	//creates bullet
	m_bulletBody.setFillColor(sf::Color::Red);
	m_bulletBody.setPosition(bulletX + 45, bulletY);
	m_bulletBody.setSize(size);
}

//moves bullet
void Bullet::bulletMove()
{
	if (bulletAlive == true)
	{
		bulletY -= bulletSpeed;
		m_bulletBody.setPosition(bulletX + 45, bulletY);
	}
}

//resets bullet after it leaves the screen
void Bullet::bulletReset()
{
	if (bulletY < 0)
	{
		bulletAlive = false; 
		m_bulletBody.setPosition(bulletX + 45, m_player.playerY);
	}
}

