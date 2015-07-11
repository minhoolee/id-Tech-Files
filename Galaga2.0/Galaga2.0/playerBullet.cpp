#include "playerBullet.hpp"
#include "galagaGame.hpp"

PlayerBullet::PlayerBullet() : GameObject() 
{
	playerBulletTextureRect = sf::IntRect(12, 50, 25, 25);
	sprite.setTexture(mainTexture);
	sprite.setTextureRect(playerBulletTextureRect);
	sprite.setOrigin(12.5, 12.5);
}

void PlayerBullet::update(sf::Time timeElapsed)
{
	sprite.move(velocity * timeElapsed.asSeconds());

	if (sprite.getPosition().y < 0)
	{
		enabled = false;
	}
	
	for (Enemy &e : game->enemies)
	{
		if (isColliding(&e))
		{
			enabled = false;
			e.enabled = false;
			game->player1Score++;
			game->p1ScoreText.setString("Score: " + std::to_string(game->player1Score));
		}
	}
}
