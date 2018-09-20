// Game class declaration
#pragma once

#include "AwesomeSq.h"    // include AwesomeSq header file
#include "EvilSq.h"		 // include EvilSq header file
#include "Coin.h"		// include Coin header file	


static const int MAX_ROWS = 20;
static const int MAX_COLUMNS = 20;
int worldSqMap[MAX_ROWS][MAX_COLUMNS] = {  { 2 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 }
										  ,{ 0 , 0 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1, 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 0 }
										  ,{ 0 , 0 , 1 , 0 , 0 , 1 , 0 , 0 , 0 , 0 , 0, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 }
										  ,{ 0 , 0 , 0 , 0 , 0 , 1 , 0 , 1 , 1 , 1 , 1, 1 , 0 , 1 , 1 , 1 , 1 , 1 , 1 , 0 }
										  ,{ 0 , 1 , 0 , 1 , 0 , 0 , 0 , 1 , 0 , 0 , 0, 1 , 0 , 0 , 0 , 0 , 0 , 0 , 1 , 0 }
										  ,{ 0 , 1 , 0 , 1 , 0 , 1 , 0 , 1 , 0 , 1 , 0, 1 , 0 , 1 , 1 , 1 , 1 , 1 , 1 , 0 }
										  ,{ 0 , 1 , 1 , 1 , 0 , 1 , 0 , 1 , 0 , 1 , 0, 1 , 0 , 1 , 0 , 0 , 0 , 0 , 0 , 0 }
										  ,{ 0 , 1 , 0 , 1 , 0 , 1 , 0 , 0 , 0 , 0 , 1, 1 , 0 , 1 , 0 , 1 , 1 , 1 , 1 , 0 }
										  ,{ 0 , 1 , 0 , 1 , 0 , 1 , 0 , 1 , 1 , 0 , 1, 1 , 0 , 1 , 1 , 1 , 0 , 0 , 1 , 0 }
										  ,{ 0 , 1 , 0 , 1 , 0 , 1 , 0 , 1 , 0 , 0 , 1, 1 , 0 , 0 , 0 , 0 , 0 , 0 , 1 , 0 }
										  ,{ 0 , 1 , 0 , 1 , 1 , 1 , 0 , 1 , 1 , 0 , 1, 1 , 1 , 0 , 1 , 1 , 1 , 0 , 1 , 0 }
										  ,{ 0 , 1 , 0 , 1 , 0 , 0 , 0 , 0 , 1 , 0 , 1, 0 , 1 , 0 , 1 , 0 , 0 , 0 , 1 , 0 }
										  ,{ 0 , 1 , 0 , 1 , 0 , 1 , 1 , 1 , 1 , 0 , 1, 0 , 1 , 0 , 1 , 0 , 1 , 1 , 1 , 0 }
										  ,{ 0 , 1 , 0 , 0 , 0 , 1 , 0 , 0 , 1 , 0 , 1, 0 , 1 , 0 , 1 , 0 , 0 , 1 , 0 , 0 }
										  ,{ 0 , 1 , 1 , 1 , 0 , 1 , 0 , 1 , 1 , 0 , 1, 0 , 1 , 0 , 1 , 1 , 1 , 1 , 1 , 0 }
										  ,{ 0 , 1 , 0 , 1 , 0 , 1 , 0 , 1 , 1 , 0 , 1, 0 , 1 , 0 , 0 , 0 , 0 , 0 , 1 , 0 }
										  ,{ 0 , 1 , 0 , 1 , 1 , 1 , 0 , 1 , 1 , 0 , 1, 0 , 1 , 1 , 1 , 1 , 1 , 0 , 1 , 0 } };
									
//setd up world blocks array
sf::RectangleShape worldSq[MAX_ROWS][MAX_COLUMNS];

//colors
sf::Color GREEN{ 149, 249, 149 };
sf::Color BLUE{ 129, 200, 255 };
sf::Color PINK{ 255,191,245,255 };


class Game
{
	//classes
	AwesomeSq awesomeSq;
	EvilSq evilSq;
	EvilSq evilSqArray[4];
	Coin coin;

public:
	sf::Font m_font;  // font for writing text
	sf::Text m_message;  // text to write on the screen
	sf::Text m_message2;
	sf::Text m_message3;
	sf::Text gameOver;
	sf::Text replay;
	sf::Text Help;

public:	  // declaration of member functions	
	void	LoadContent();
	void	run();
	void	startingPoint();


	//sets size of world blocks
	sf::Vector2f size = { 50,50 };
	int timer = 10; //sets up timer that counts down from ten
	int lives = 3;
	int coins = 0;



};

