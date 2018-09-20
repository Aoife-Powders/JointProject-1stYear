// EvilSq function definitions here

#include "EvilSq.h"

//sets up the evil sqs
void EvilSq::evilSqSetUp()
{
	evilSq.setPosition(row * 50, col * 50);
	evilSq.setFillColor(sf::Color::Red);
	evilSq.setSize(size);
}
