#include "enemy.hpp"
#include "galagaGame.hpp"

Enemy::Enemy() : GameObject() {}

Enemy::Enemy(sf::Vector2f position, GalagaGame *game) : GameObject(position, game)
{
	sprite.setTextureRect(enemyTextureRect);
	sprite.setOrigin(12.5, 12.5);
}

void Enemy::update(sf::Time timeElapsed)
{
	sf::Vector2f velocity(0, 0);

	if (isEnemyMovingDown)
	{
		if (moveTimer.getElapsedTime().asSeconds() > 1)
		{
			isEnemyMovingDown = false;
			isEnemyMovingRight = !isEnemyMovingRight;
		}
		else
		{
			velocity.y = ENEMY_SPEED;
		}
	}
	else if (isEnemyMovingRight)
	{
		if (sprite.getPosition().x > GAME_WIDTH - 100)
		{
			isEnemyMovingDown = true;
			moveTimer.restart();
		}
		else
		{
			velocity.x = ENEMY_SPEED;
		}
	}
	else
	{
		if (sprite.getPosition().x < 100)
		{
			isEnemyMovingDown = true;
			moveTimer.restart();
		}
		else
		{
			velocity.x = -ENEMY_SPEED;
		}
	}

	if (fireTimer.getElapsedTime().asSeconds() > nextShotTime)
	{
		nextShotTime = (rand() % 100 + 1) / 10.f;
		fireTimer.restart();
		fire();
	}

	sprite.move(velocity * timeElapsed.asSeconds());

	// Enable bullets
	for (EnemyBullet &b : enemyBullets)
	{
		if (b.enabled){
			b.update(timeElapsed);
		}
	}

}

void Enemy::fire()
{
	// NOTE: POSSIBLY NEED TO CHANGE THESE FIRST THIS->ENEMY BULLETS IF NEW ENEMY BULLETS ARE BEGIN CREATED EACH TIME
	this->enemyBullets[this->currentEnemyBullet].sprite.setPosition(this->sprite.getPosition());
	this->enemyBullets[this->currentEnemyBullet].enabled = true;
	this->enemyBullets[this->currentEnemyBullet].velocity = sf::Vector2f(0, BULLET_SPEED);

	// If bullet not set, set a couple values on it
	if (this->enemyBullets[this->currentEnemyBullet].game == NULL)
	{
		this->enemyBullets[this->currentEnemyBullet].game = game;
		this->enemyBullets[this->currentEnemyBullet].sprite.setTextureRect(this->enemyBullets[0].enemyBulletTextureRect); // 0th index because all bullet textures are same
	}

	this->currentEnemyBullet++;

	if (this->currentEnemyBullet == 50)
	{
		this->currentEnemyBullet = 0;
	}
}
