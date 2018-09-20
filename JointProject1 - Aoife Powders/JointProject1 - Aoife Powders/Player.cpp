#include "Player.h"

//gives values to variables
Player::Player() :
	playerWidth{100}
	,playerHeight{20}
	,playerPosition{ 450,550 }
	,playerX{ playerPosition.x }
	,playerY{ playerPosition.y }
	,playerSpeed(5.0f)
{
	//creates player
	m_playerBody.setFillColor(sf::Color::White);
	m_playerBody.setPosition(playerPosition);
	m_playerBody.setSize(size);
}

//moves player up
void Player::playerMovementUp()
{
	playerY = playerY - playerSpeed;
	m_playerBody.setPosition(playerX, playerY);
}

//moves player down
void Player::playerMovementDown()
{
	playerY = playerY + playerSpeed;
	m_playerBody.setPosition(playerX, playerY);
}

//moves player right
void Player::playerMovementRight()
{
	playerX = playerX + playerSpeed;
	m_playerBody.setPosition(playerX, playerY);
}

//moes player left
void Player::playerMovementLeft()
{
	playerX = playerX - playerSpeed;
	m_playerBody.setPosition(playerX, playerY);
}

//if player moves outside the screen it wraps around to the other side
void Player::playerBoundaryRight()
{
	if (playerX >= 1000)
	{
		playerX = 10;
		m_playerBody.setPosition(playerX, playerY);
	}
}

void Player::playerBoundaryLeft()
{
	if (playerX <= 0)
	{
		playerX = 1000;
		m_playerBody.setPosition(playerX, playerY);
	}
}

void Player::playerBoundaryUp()
{
	if (playerY <= 0)
	{
		playerY = 600;
		m_playerBody.setPosition(playerX, playerY);
	}
}

void Player::playerBoundaryDown()
{
	if (playerY >= 600)
	{
		playerY = 10;
		m_playerBody.setPosition(playerX, playerY);
	}
}

//resets player when a collision takes place
void Player::playerEnemyCollision()
{
	playerX = 450;
	playerY = 550;

	m_playerBody.setPosition(playerX, playerY);
}



