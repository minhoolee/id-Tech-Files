#include "player.hpp"
#include "galagaGame.hpp"

Player::Player() : GameObject() {}

Player::Player(sf::Vector2f position, GalagaGame *game) : GameObject(position, game)
{
	enabled = true;
	mainTexture.loadFromFile("Textures/mainTexture.png");
	sprite.setTextureRect(playerTextureRect);
	sprite.setOrigin(12.5, 12.5);
}

void Player::update(sf::Time timeElapsed)
{
	sf::Vector2f playerMovement(0, 0);

	if (this->isPlayerMovingUp)
		playerMovement.y -= PLAYER_SPEED;
	if (this->isPlayerMovingDown)
		playerMovement.y += PLAYER_SPEED;
	if (this->isPlayerMovingLeft)
		playerMovement.x -= PLAYER_SPEED;
	if (this->isPlayerMovingRight)
		playerMovement.x += PLAYER_SPEED;
	if ((this->isPlayerFiring) && (this->shotTimer.getElapsedTime().asSeconds() > 0.25))
	{
		fire();
		this->shotTimer.restart();
	}
	this->sprite.move(playerMovement * timeElapsed.asSeconds());

	// Enable bullets
	for (PlayerBullet &b : this->playerBullets)
	{
		if (b.enabled){
			b.update(timeElapsed);
		}
	}
		
	// Series of rectangles for rotation animation
	playerTextureRect = sf::IntRect(12, 50, 25, 25);

	this->sprite.setTexture(mainTexture);
	this->sprite.setTextureRect(playerTextureRect);
	this->sprite.setScale(3, 3);

	if (game->MULTI_PLAYER)
		game->player2.sprite.setColor(sf::Color::Blue);

	this->sprite.setRotation(90); // Image starts pointed left, so rotate it 90 degrees clockwise
	// std::cout << "rotation (" << rotationMode << "): " << rotationMode * 15 << std::endl;
	//this->sprite.setRotation(rotationMode * 15);
}

void Player::fire()
{
	this->playerBullets[this->currentBullet].sprite.setPosition(this->sprite.getPosition());
	this->playerBullets[this->currentBullet].enabled = true;
	this->playerBullets[this->currentBullet].velocity = sf::Vector2f(0, BULLET_SPEED);

	// If bullet not set, set a couple values on it
	if (this->playerBullets[this->currentBullet].game == NULL)
	{
		this->playerBullets[this->currentBullet].game = game;
		this->playerBullets[this->currentBullet].sprite.setTextureRect(this->playerBullets[0].playerBulletTextureRect); // 0th index because all bullet textures are same
	}

	this->currentBullet++;

	if (this->currentBullet == 50)
	{
		this->currentBullet = 0;
	}
}