#include "Game.h"
//Joint Project 1
//Aoife Powders
//C00218374

//date:12/02/16
//Time Taken: 20 hrs
//known issues: The enemies in the array move together not 
//independantly so when one is shot it breaks the movement

//default constructor
//set up render window and other members
Game::Game() : m_window(sf::VideoMode(1000, 600), "Joint Project 1")
{
	livesCounter = 3;
	scoreCounter = 0;
}

//runs the game, includes the game loop
void Game::run()
{
	
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time timePerFrame = sf::seconds(1.0f / 60.0f);
	
	//sets up lives text
	lives.setFont(m_font);
	lives.setColor(sf::Color::Yellow);
	lives.setPosition(0, 0);
	lives.setCharacterSize(30);
	lives.setString("Lives : " + std::to_string(livesCounter));
	//sets up score text
	score.setFont(m_font);
	score.setColor(sf::Color::Yellow);
	score.setPosition(500, 0);
	score.setCharacterSize(30);
	score.setString("Score : " + std::to_string(scoreCounter));
	//sets up game over text
	gameOver.setFont(m_font);
	gameOver.setColor(sf::Color::Yellow);
	gameOver.setPosition(190, 100);
	gameOver.setCharacterSize(200);
	gameOver.setString("Game Over" );
	//sets up end score text
	endScore.setFont(m_font);
	endScore.setColor(sf::Color::Yellow);
	endScore.setPosition(300, 300);
	endScore.setCharacterSize(50);
	endScore.setString("Score  " + std::to_string(scoreCounter));

	//sets up enemy array
	m_enemyLine.enemysArray();
	
	while (m_window.isOpen())
	{
		processEvents();
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			//keyboard input to move player
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				m_player.playerMovementRight(); 
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				m_player.playerMovementLeft();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				m_player.playerMovementDown();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				m_player.playerMovementUp();
			}

			//sets bullet to true when space bar is pressed
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && m_bullet.bulletAlive == false)
			{
				m_bullet.bulletAlive = true;
				m_bullet.bulletX = m_player.m_playerBody.getPosition().x;
				m_bullet.bulletY = m_player.playerY;
			}

			//moves bullet
			m_bullet.bulletMove();
			m_bullet.bulletReset();
	
			//moves enemy
			m_enemy.enemyMove(m_player.playerX, m_player.playerY);

			//moves enemy array
			m_enemyLine.enemysMove();
			
			timeSinceLastUpdate -= timePerFrame;
			processEvents();
			update();
			render();
		}
		
	}

}
//function loads font file
void Game::loadContent()
{
	if (!m_font.loadFromFile("ASSETS/FONTS/bebasNeue.otf"))
	{
		std::cout << "error loading font file";
	}
}

//functiion updates game 
void Game::update()
{
	//player boundary fucntions
	m_player.playerBoundaryRight();
	m_player.playerBoundaryDown();
	m_player.playerBoundaryLeft();
	m_player.playerBoundaryUp();

	//enemy boundary functions
	m_enemy.enemyBoundaryDown();
	m_enemy.enemyBoundaryLeft();
	m_enemy.enemyBoundaryRight();
	m_enemy.enemyBoundaryUp();

	//player and enemy collision
	if (m_enemy.m_enemyBody.getGlobalBounds().intersects(m_player.m_playerBody.getGlobalBounds()))
	{
		m_enemy.enemyCollision();
		m_player.playerEnemyCollision();
		//decrements lives when hit
		livesCounter--;
		lives.setString("Lives : " + std::to_string(livesCounter));
	}
	//enemy bullet collision
	if (m_bullet.m_bulletBody.getGlobalBounds().intersects(m_enemy.m_enemyBody.getGlobalBounds()))
	{
		m_enemy.enemyCollision();
		//increments score when hit
		scoreCounter ++;
		score.setString("Score : " + std::to_string(scoreCounter));
		endScore.setString("Score  " + std::to_string(scoreCounter));
		m_enemy.enemyChangeColor();
		//enemy speeds up every time its hit
		m_enemy.enemySpeed = m_enemy.enemySpeed + 0.5;
	}

	//enemy array and player collisions
	if (m_player.m_playerBody.getGlobalBounds().intersects(m_enemyLine.enemys[0].getGlobalBounds()))
	{
		m_enemyLine.enemys[0].setPosition(20, 50);
		livesCounter--;
		lives.setString("Lives : " + std::to_string(livesCounter));
	}

	if (m_player.m_playerBody.getGlobalBounds().intersects(m_enemyLine.enemys[1].getGlobalBounds()))
	{
		m_enemyLine.enemys[1].setPosition(20, 150);
		livesCounter--;
		lives.setString("Lives : " + std::to_string(livesCounter));
	}

	if (m_player.m_playerBody.getGlobalBounds().intersects(m_enemyLine.enemys[2].getGlobalBounds()))
	{
		m_enemyLine.enemys[2].setPosition(20, 250);
		livesCounter--;
		lives.setString("Lives : " + std::to_string(livesCounter));
	}

	//enemy array and bullet collisions
	if (m_bullet.m_bulletBody.getGlobalBounds().intersects(m_enemyLine.enemys[0].getGlobalBounds()))
	{
		m_enemyLine.enemys[0].setPosition(20, 50);
		scoreCounter++;
		score.setString("Score : " + std::to_string(scoreCounter));
		endScore.setString("Score  " + std::to_string(scoreCounter));
	}

	if (m_bullet.m_bulletBody.getGlobalBounds().intersects(m_enemyLine.enemys[1].getGlobalBounds()))
	{
		m_enemyLine.enemys[1].setPosition(20, 150);
		scoreCounter++;
		score.setString("Score : " + std::to_string(scoreCounter));
		endScore.setString("Score  " + std::to_string(scoreCounter));
	}

	if (m_bullet.m_bulletBody.getGlobalBounds().intersects(m_enemyLine.enemys[2].getGlobalBounds()))
	{
		m_enemyLine.enemys[2].setPosition(20, 250);
		scoreCounter++;
		score.setString("Score : " + std::to_string(scoreCounter));
		endScore.setString("Score  " + std::to_string(scoreCounter));
	}

	if (m_player.m_playerBody.getGlobalBounds().intersects(m_coin.m_coinBody.getGlobalBounds()))
	{
		//moves coin
		m_coin.coinMove();
		scoreCounter++;
		score.setString("Score : " + std::to_string(scoreCounter));
		endScore.setString("Score  " + std::to_string(scoreCounter));
	}
}

//closes window when x is pressed
void Game::processEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			m_window.close();
		}
	}
}

//draw screen for game
void Game::render()
{
	//clears screen and draws all shapes
	m_window.clear(sf::Color::Black);
	m_window.draw(m_player.m_playerBody);
	m_window.draw(m_enemy.m_enemyBody);
	m_window.draw(lives);
	m_window.draw(score);
	m_window.draw(m_coin.m_coinBody);

	//deaw bullet only if the bullet is alive
	if (m_bullet.bulletAlive == true)
	{
		m_window.draw(m_bullet.m_bulletBody);
	}

	//draw enemy array
	for (int i = 0; i < 3; i++)
	{
		m_window.draw(m_enemyLine.enemys[i]);
	}
	
	//if you have zero lives the game is over and the end score and game over screen is drawn
	if (livesCounter == 0)
	{
		m_window.clear(sf::Color::Black);
		m_window.draw(gameOver);
		m_window.draw(endScore);
		m_enemy.enemySpeed = 1.0f;
	}

	//after a few seconds the game will restart so this if statement 
	//resets the lives and score to there original values
	//and resets the array of enemies
	if (livesCounter == -1)
	{
		livesCounter = 3;
		lives.setString("Lives : " + std::to_string(livesCounter));
		scoreCounter = 0;
		score.setString("Score : " + std::to_string(scoreCounter));
		endScore.setString("Score  " + std::to_string(scoreCounter));
		m_enemyLine.enemysArray();
	}

	m_window.display();
}

