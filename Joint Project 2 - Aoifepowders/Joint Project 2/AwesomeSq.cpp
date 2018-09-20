// AwesomeSq function definitions here

#include "AwesomeSq.h"

//sets up awesome sq
void AwesomeSq::setUpAwesomeSq()
{
	awesomeSq.setPosition(playerCol * 50, playerRow * 50);
	awesomeSq.setSize(size);
}

//moves awesome sq up if the row is greater than 1
void AwesomeSq::awesomeSqMoveUp()
{
	if (playerRow > 1)
	{
		playerRow = playerRow - 1;
		awesomeSq.setPosition(playerCol * 50, playerRow * 50);
	}
}

//moves awesome sq down if row is less than 17
void AwesomeSq::awesomeSqMoveDown()
{
	if (playerRow < 17)
	{
		playerRow = playerRow + 1;
		awesomeSq.setPosition(playerCol * 50, playerRow * 50);
	}
}

//moves awesome sq right if the row is less than 19
void AwesomeSq::awesomeSqMoveRight()
{
	if (playerCol < 19)
	{
		playerCol = playerCol + 1;
		awesomeSq.setPosition(playerCol * 50, playerRow * 50);
	}
}

//moves awesome sq up if the col is greater than 0
void AwesomeSq::awesomeSqMoveLeft()
{
	if (playerCol > 0)
	{
		playerCol = playerCol - 1;
		awesomeSq.setPosition(playerCol * 50, playerRow * 50);
	}
}

