#include "enemyBullet.hpp"

EnemyBullet::EnemyBullet() : GameObject()
{
	this->sprite.setTextureRect(enemyBulletTextureRect);
}

void EnemyBullet::update(sf::Time timeElapsed)
{
	sprite.move(velocity * timeElapsed.asSeconds());

	if (sprite.getPosition().y > GAME_HEIGHT)
	{
		enabled = false;
	}

	/*
	if (game->player.enabled && isColliding(&game->player))
	{
		enabled = false;
		game->player.enabled = false;
	}
	*/
}
