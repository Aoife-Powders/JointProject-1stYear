#pragma once
#ifndef GAME
#define GAME

#include <iostream>
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include "Player.h"
#include "Enemy.h"
#include "bullet.h"
#include "EnemyLine.h"
#include "Coin.h"

class Game
{
public:
	Game();

	void run();
	void loadContent();

	sf::Font m_font;
	sf::Text m_message;

private:
	//classes
	Player m_player;
	Enemy m_enemy;
	Bullet m_bullet;
	EnemyLine m_enemyLine;
	Coin m_coin;

	//functions
	void update();
	void processEvents();
	void render();


	// sfml window
	sf::RenderWindow m_window;
	// lives text
	sf::Text lives;
	//score text
	sf::Text score;
	//ens score text
	sf::Text endScore;
	//game over text
	sf::Text gameOver;
	//game finished true or false
	bool gameFinished;
	// set up font
	sf::Font bebasNeue;
	// counts how many lives the player has left
	int livesCounter;
	//counts score
	int scoreCounter;
};
#endif

