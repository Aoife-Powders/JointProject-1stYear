#include "Coin.h"

void Coin::setUpCoin()
{
	coin.setFillColor(sf::Color::Yellow);
	coin.setPosition(coinCol * 525, coinRow * 325);
	coin.setSize(size);
}

void Coin::coinCollision()
{
	coinRow = (rand() % 20 + 2);
	coinCol = (rand() % 20 + 2);

	coin.setPosition(coinCol * 25, coinRow * 25);
}
