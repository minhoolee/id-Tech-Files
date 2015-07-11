#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "gameObject.hpp"
#include "enemyBullet.hpp"

class Enemy : public GameObject
{
public:
	sf::Clock fireTimer;
	sf::Clock moveTimer;

	// Rectangle for taking texture off of main texture
	sf::IntRect enemyTextureRect;

	// Game properties
	static const int ENEMY_SPEED = 200;
	static const int BULLET_SPEED = 750;

	int currentEnemyBullet = 0;
	EnemyBullet enemyBullets[50];

	float nextShotTime;

	bool isEnemyMovingDown = false;
	bool isEnemyMovingRight = true;

	Enemy();
	Enemy(sf::Vector2f position, GalagaGame *game);

	void update(sf::Time t);
	void fire();
};

#endif //ENEMY_HPP