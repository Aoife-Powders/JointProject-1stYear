#include "Coin.h"



Coin::Coin() :
	coinWidth{ 20 }
	, coinHeight{ 20 }
	, coinPosition{ 60, 100 }
	, coinX{ coinPosition.x }
	, coinY{ coinPosition.y }
{
	//creates coin
	m_coinBody.setFillColor(sf::Color::Yellow);
	m_coinBody.setPosition(coinX + 45, coinY);
	m_coinBody.setSize(size);
}

void Coin::coinMove()
{
	coinX = (rand() % 1000);
	coinY = (rand() % 600);

	m_coinBody.setPosition(coinX, coinY);
}


