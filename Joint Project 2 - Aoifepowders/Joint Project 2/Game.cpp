// Name: Aoife Powders
// Login: C00218374
// Date: March 2017
// Time taken: 
//---------------------------------------------------------------------------
// Project description: Maze game
// ---------------------------------------------------------------------------
// Known Bugs:

//////////////////////////////////////////////////////////// 
// Headers for SFML projects
// include correct library file for release and debug versions
// include iostream for console window output
// include 
//////////////////////////////////////////////////////////// 

#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 
#pragma comment(lib,"opengl32.lib") 
#pragma comment(lib,"glu32.lib") 

#include "SFML/Graphics.hpp" 

#include <iostream>
#include <cstdlib>  // include support for randomizing
#include <ctime>   // supports ctime function

#include "Game.h"   // include Game header file


int main()
{
	Game aGame;
	aGame.LoadContent();
	aGame.run();

	return 0;
}


void Game::LoadContent()
// load the font file
{
	if (!m_font.loadFromFile("ASSETS/FONTS/BebasNeue.otf"))
	{
		std::cout << "error with font file file";
	}
}


void Game::run()
{
	//create Window
	sf::RenderWindow window(sf::VideoMode(1000, 900), "Joint Project 2");

	// set up the message string 
	m_message2.setFont(m_font);  // set the font for the text
	m_message2.setCharacterSize(24); // set the text size
	m_message2.setColor(sf::Color::White); // set the text colour
	m_message2.setPosition(10, 10);  // its position on the screen

	m_message3.setFont(m_font);
	m_message3.setCharacterSize(24);
	m_message3.setColor(sf::Color::White);
	m_message3.setPosition(700, 10);

	gameOver.setFont(m_font);
	gameOver.setColor(sf::Color::Yellow);
	gameOver.setPosition(190, 100);
	gameOver.setCharacterSize(100);

	replay.setFont(m_font);
	replay.setColor(sf::Color::Yellow);
	replay.setPosition(190, 200);
	replay.setCharacterSize(80);

	Help.setFont(m_font);
	Help.setColor(sf::Color::Yellow);
	Help.setPosition(200, 100);
	Help.setCharacterSize(40);
	

	//sets up world blocks
	for (int i = 0; i < MAX_ROWS; i++)
	{
		for (int j = 0; j < MAX_COLUMNS; j++)
		{
			worldSq[i][j].setFillColor(GREEN);
			worldSq[i][j].setSize(size);
			worldSq[i][j].setOutlineColor(sf::Color::White);
			worldSq[i][j].setPosition(i * 50, j * 50);
		}
	}

	awesomeSq.awesomeSq.setFillColor(PINK);

	srand(time(nullptr)); // set the seed once

	sf::Time timePerFrame = sf::seconds(1.0f / 60.0f);

	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	// the clock object keeps the time.
	sf::Clock clock;
	clock.restart();

	awesomeSq.setUpAwesomeSq();
	evilSq.evilSqSetUp();
	coin.setUpCoin();

	while (window.isOpen())
	{
		// check if the close window button is clicked on
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		//get the time since last update and restart the clock
		timeSinceLastUpdate += clock.restart();

		//update every 60th of a second
		//only when the time since last update is greater than 1/60 update the world.
		while (timeSinceLastUpdate > timePerFrame)
		{

			//timer to slow down player movement
			timer--;
			if (timer < 0)
			{
				timer = 0;
			}
			// get keyboard input to move the player
			if (timer == 0)
			{

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
				{
					timer = 10;
					if (worldSqMap[awesomeSq.playerRow][awesomeSq.playerCol - 1] == 0)
					{
						awesomeSq.awesomeSqMoveLeft();
					}
				
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				{
					timer = 10;
					if (worldSqMap[awesomeSq.playerRow][awesomeSq.playerCol + 1] == 0)
					{
						awesomeSq.awesomeSqMoveRight();
					}
					
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
				{
					timer = 10;
					if (worldSqMap[awesomeSq.playerRow + 1][awesomeSq.playerCol] == 0)
					{
						awesomeSq.awesomeSqMoveDown();
					}
				
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
				{
					timer = 10;
					if (worldSqMap[awesomeSq.playerRow - 1][awesomeSq.playerCol] == 0)
					{
						awesomeSq.awesomeSqMoveUp();
					}
					
				}

				//kick blocks keyboard input
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) && (worldSqMap[awesomeSq.playerRow][awesomeSq.playerCol + 1] == 1) && (worldSqMap[awesomeSq.playerRow][awesomeSq.playerCol + 2] == 0))	//checks if 2 keyboard buttons are pressed
				{																																																												//and if the cell to the right of the block is a world sq
					worldSqMap[awesomeSq.playerRow][awesomeSq.playerCol + 2] = 1;																																												//and if the cell 2 blacks to the right is empty
					worldSqMap[awesomeSq.playerRow][awesomeSq.playerCol + 1] = 0;																																												//then move he block out of that cell
				}																																																												//and draw it in the next cell						

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) && (worldSqMap[awesomeSq.playerRow][awesomeSq.playerCol - 1] == 1) && (worldSqMap[awesomeSq.playerRow][awesomeSq.playerCol - 2] == 0))
				{
					worldSqMap[awesomeSq.playerRow][awesomeSq.playerCol - 2] = 1;
					worldSqMap[awesomeSq.playerRow][awesomeSq.playerCol - 1] = 0;
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) && (worldSqMap[awesomeSq.playerRow + 1][awesomeSq.playerCol] == 1) && (worldSqMap[awesomeSq.playerRow + 2][awesomeSq.playerCol] == 0))
				{
					worldSqMap[awesomeSq.playerRow + 2][awesomeSq.playerCol] = 1;
					worldSqMap[awesomeSq.playerRow + 1][awesomeSq.playerCol] = 0;
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) && (worldSqMap[awesomeSq.playerRow - 1][awesomeSq.playerCol] == 1) && (worldSqMap[awesomeSq.playerRow - 2][awesomeSq.playerCol] == 0))
				{
					worldSqMap[awesomeSq.playerRow - 2][awesomeSq.playerCol] = 1;
					worldSqMap[awesomeSq.playerRow - 1][awesomeSq.playerCol] = 0;
				}

				if (coin.coin.getGlobalBounds().intersects(awesomeSq.awesomeSq.getGlobalBounds()))
				{
					coins++;
					coin.coinCollision();
				}

				for (int i = 0; i < MAX_ROWS; i++)
				{
					for (int j = 0; j < MAX_COLUMNS; j++)
					{
						if (coin.coin.getGlobalBounds().intersects(worldSq[i][j].getGlobalBounds()))
						{
							//coin.coinCollision();
						}
					}
				}
			}


			// Clear the screen and draw your game sprites
			window.clear(sf::Color::Black);

			Help.setString("    INSTRUCTIONS\n Press P to start game\n Use arrow keys to move\n Press space bar and arrow keys to move blocks\n Dont get hit by the enemies\n Collect 5 coins to win the game");
			window.draw(Help);

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
			{
				window.clear(BLUE);

				//draws map and player
				for (int i = 0; i < MAX_ROWS; i++)
				{
					for (int j = 0; j < MAX_COLUMNS; j++)
					{
						if (worldSqMap[i][j] == 1)
						{
							window.draw(worldSq[j][i]);
						}
						else if (worldSqMap[i][j] == 2)
						{
							window.draw(awesomeSq.awesomeSq);
						}
					}
				}

				//draws enemies
				for (int i = 0; i < 4; i++)
				{
					window.draw(evilSqArray[i].evilSq);
				}
				window.draw(coin.coin);

				m_message2.setString("Coins Collected: " + std::to_string(coins));
				window.draw(m_message2);
				m_message3.setString("Lives: " + std::to_string(lives));
				window.draw(m_message3);
				if (lives == 0)
				{
					window.clear(sf::Color::Black);
					gameOver.setString("Game Over You Lost");
					replay.setString("Replay? press S");
					window.draw(gameOver);
					window.draw(replay);
				}

				if (coins == 5)
				{
					window.clear(sf::Color::Black);
					gameOver.setString("Game Over You Won");
					replay.setString("Replay? press S");
					window.draw(gameOver);
					window.draw(replay);
				}
			}
				window.display();

			
			// reset the timeSinceLastUpdate to 0 
			timeSinceLastUpdate = sf::Time::Zero;
		}
		}
		
	}  // end while loop

	void Game::startingPoint()
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			for (int i = 0; i < MAX_ROWS; i++)
			{
				for (int j = 0; j < MAX_COLUMNS; j++)
				{
					worldSq[i][j].setFillColor(GREEN);
					worldSq[i][j].setSize(size);
					worldSq[i][j].setOutlineColor(sf::Color::White);
					worldSq[i][j].setPosition(i * 50, j * 50);
				}
			}

			awesomeSq.setUpAwesomeSq();
			evilSq.evilSqSetUp();
			coin.setUpCoin();
		}
	}

	
			
		
	
