#include "enemy.hpp"
#include "galagaGame.hpp"

Enemy::Enemy() : GameObject() {}

Enemy::Enemy(sf::Vector2f position, GalagaGame *game) : GameObject(position, game)
{
	sprite.setTexture(game->mainTexture);
	enemyTextureRect = sf::IntRect(15, 101, 18, 21);
	sprite.setTextureRect(enemyTextureRect);
	sprite.setScale(3, 3);
	sprite.setOrigin(32, 32);
	sprite.setRotation(90); // Image starts pointed left, so rotate it 90 degrees clockwise
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

	if (fireTimer.getElapsedTime().asSeconds() > 2)
	{
		fireTimer.restart();

		// When enemy fires, make it turn to the bottom and move off the screen
		sprite.rotate(180);
		while (sprite.getPosition().y < GAME_HEIGHT)
		{
			sprite.move(velocity * fireTimer.getElapsedTime().asSeconds());
			std::cout << sprite.getPosition().x << ", " << sprite.getPosition().y << std::endl;
		}

		fire();
	}

	sprite.move(velocity * timeElapsed.asSeconds());

	// Enable bullets
	for (EnemyBullet &b : enemyBullets)
	{
		if (b.enabled)
		{
			b.update(timeElapsed);
		}
	}
}

void Enemy::fire()
{
	for (int bullet_num = 0; bullet_num < 3; bullet_num++)
	{
		// NOTE: POSSIBLY NEED TO CHANGE THESE FIRST THIS->ENEMY BULLETS IF NEW ENEMY BULLETS ARE BEGIN CREATED EACH TIME
		enemyBullets[currentEnemyBullet].sprite.setPosition(sf::Vector2f((this->sprite.getPosition().x + 132), (this->sprite.getPosition().y)));
		enemyBullets[currentEnemyBullet].enabled = true;

		float enemy_x = rand() % (BULLET_SPEED / 6) + 1; // Bullets can fly in any direction of a certain range
		float enemy_y = sqrt(pow(BULLET_SPEED, 2) - pow(enemy_x, 2)); // Use pythagorean theorem to calculate the y distance the bullet must travel

		enemyBullets[currentEnemyBullet].velocity = sf::Vector2f(enemy_x, enemy_y);

		// If bullet not set, set a couple values on it
		if (enemyBullets[currentEnemyBullet].game == NULL)
		{
			enemyBullets[currentEnemyBullet].game = game;
			enemyBullets[currentEnemyBullet].sprite.setTexture(game->mainTexture); // 0th index because all bullet textures are same
		}

		currentEnemyBullet++;

		if (currentEnemyBullet == 50)
		{
			currentEnemyBullet = 0;
		}
	}
}
