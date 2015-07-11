#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>

#include "gameObject.hpp"
#include "playerBullet.hpp"

class Player : public GameObject
{
public:
	struct playerShip
	{
		int deg_0 = 0;
		int deg_15 = 1;
		int deg_30 = 2;
		int deg_45 = 3;
		int deg_60 = 4;
		int deg_75 = 5;
		int deg_90 = 6;
		int deg_90_animation = 7;
	} playerShipStruct;

	struct playerShipStolen
	{
		int deg_0 = 0;
		int deg_15 = 1;
		int deg_30 = 2;
		int deg_45 = 3;
		int deg_60 = 4;
		int deg_75 = 5;
		int deg_90 = 6;
		int deg_90_animation = 7;
	} playerShipStolenStruct;

	struct playerShipExplosion
	{
		int phase1 = 0;
		int phase2 = 1;
		int phase3 = 2;
		int phase4 = 3;
	} playerShipExplosionStruct;

	struct playerBullet
	{
		int vertical = 0;
		int horizontal = 1;
		int diagonal = 2;
	} playerBulletStruct;

	// Rectangle for taking texture off of main texture
	sf::IntRect playerTextureRect;

	// Player 1 controls : ARROW KEYS
	bool isPlayerMovingUp = false;
	bool isPlayerMovingDown = false;
	bool isPlayerMovingLeft = false;
	bool isPlayerMovingRight = false;
	bool isPlayerFiring = false;

	int currentBullet = 0;
	PlayerBullet playerBullets[50];

	static const int PLAYER_SPEED = 400;
	static const int BULLET_SPEED = 750;

	sf::Clock shotTimer;

	Player();
	Player(sf::Vector2f position, GalagaGame *game);

	void update(sf::Time t);
	void fire();
};

#endif // PLAYER_HPP