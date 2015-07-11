#ifndef ENEMY_BULLET_HPP
#define ENEMY_BULLET_HPP

#include "gameObject.hpp"

class EnemyBullet : public GameObject{
public:
	bool enabled = false;
	sf::Vector2f velocity;

	sf::IntRect enemyBulletTextureRect;

	EnemyBullet();

	void update(sf::Time t);
};

#endif // ENEMY_BULLET_HPP