#ifndef GALAGA_GAME_HPP
#define GALAGA_GAME_HPP

#include <SFML/Graphics.hpp>

#include <iostream> // all testing
#include <chrono>
#include <thread>

#include "gameObject.hpp"
#include "player.hpp"
#include "enemy.hpp"

class GalagaGame;

class GalagaGame
{
protected:
	// TODO: TAKE OUT THESE UNIONS
	// Unions for categorizing different spaceship angles and others
	union greenBug
	{
		int deg_0;
		int deg_15;
		int deg_30;
		int deg_45;
		int deg_60;
		int deg_75;
		int deg_90;
		int deg_90_animation;
	} greenBug;

	union greenBugHit
	{
		int deg_0;
		int deg_15;
		int deg_30;
		int deg_45;
		int deg_60;
		int deg_75;
		int deg_90;
		int deg_90_animation;
	} greenBugHit;

	union tractorBeam
	{
		int phase1;
		int phase2;
		int phase3;
	} tractorBeam;

	union redBug
	{
		int deg_0;
		int deg_15;
		int deg_30;
		int deg_45;
		int deg_60;
		int deg_75;
		int deg_90;
		int deg_90_animation;
	} redBug;

	union yellowBug
	{
		int deg_0;
		int deg_15;
		int deg_30;
		int deg_45;
		int deg_60;
		int deg_75;
		int deg_90;
		int deg_90_animation;
	} yellowBug;

	union enemyBullets
	{
		int vertical;
		int horizontal;
		int diagonal;
	} enemyBullets;

	union enemyExplosion
	{
		int phase1;
		int phase2;
		int phase3;
		int phase4;
		int phase5;
	} enemyExplosion;

	// TODO: LEVEL ICONS
	sf::RenderWindow window;

public:
	// Game window properties
	static const int GAME_WIDTH = 1600;
	static const int GAME_HEIGHT = 1000;
	int SINGLE_PLAYER = 1;
	int MULTI_PLAYER = 0;

	// Two settings, SINGLE_PLAYER and MULTI_PLAYER
	Player player1;
	Player player2;

	Enemy enemies[20];

	// Background texture
	sf::Sprite backgroundSprite;
	sf::Texture backgroundTexture;

	int rotationMode = 0; // testing rotation

	// Main texture to pull other textures off of
	sf::Texture mainTexture;

	sf::Font font;

	sf::Text p1ScoreText;
	sf::Text p2ScoreText;
	sf::Text helpText;

	unsigned long player1Score = 0;
	unsigned long player2Score = 0;

	GalagaGame();

	void run();
	void update(sf::Time time);
	void processEvents();
	void render();

	void spawnEnemies(int count);
};

#endif // GALAGA_GAME_HPP