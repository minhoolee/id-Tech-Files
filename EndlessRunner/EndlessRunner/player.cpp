//Expand for player.cpp file.
#include "player.h"

// Implement functions / constructors etc. here

player::player() : player::player(sf::Vector2f(100, 540), "Textures/walk_cycle.png", "Textures/jump_cycle.png") {
}

player::player(sf::Vector2f position, std::string texFileLoc, std::string jumpFileLoc){

	playerTexture.loadFromFile(texFileLoc);
	jumpingTexture.loadFromFile(jumpFileLoc);

	//Series of rects for walking animation
	walkRect[0] = sf::IntRect(0, 0, 64, 64);
	walkRect[1] = sf::IntRect(64, 0, 64, 64);
	walkRect[2] = sf::IntRect(128, 0, 64, 64);
	walkRect[3] = sf::IntRect(192, 0, 64, 64);
	walkRect[4] = sf::IntRect(0, 64, 64, 64);
	walkRect[5] = sf::IntRect(64, 64, 64, 64);
	walkRect[6] = sf::IntRect(128, 64, 64, 64);

	//Series of rects for jumping animation
	jumpRect[0] = sf::IntRect(0, 0, 64, 64);
	jumpRect[1] = sf::IntRect(64, 0, 64, 64);
	jumpRect[2] = sf::IntRect(128, 0, 64, 64);
	jumpRect[3] = sf::IntRect(0, 64, 64, 64);
	jumpRect[4] = sf::IntRect(64, 64, 64, 64);
	jumpRect[5] = sf::IntRect(128, 64, 64, 64);

	//Initialize and place player sprite
	playerSprite.setTexture(playerTexture);
	playerSprite.setTextureRect(walkRect[0]);
	playerSprite.setOrigin(15, 16);
	playerSprite.setScale(1.5, 1.5);
	playerSprite.setPosition(position.x, position.y);

	jumping = false;
	jumpState = 0;
	count = 0;
}

//Function to cycle through animations based on whether the player is jumping or walking.
int player::animatePlayer()
{
	if (!jumping)
	{
		if (count < 5)
		{
			count++;
		}
		else{
			count = 0;
		}
	}
	else{
		if (jumpState == 1)
		{
			if (count < 2)
			{
				count++;
			}
		}
		else if (jumpState == 2)
		{
			if (count < 4)
			{
				count++;
			}
		}
	}
	return count;
}

//Function that makes the player jump, and displays the correct texture on the player sprite.
void player::update()
{
	if (jumping)
	{
		playerSprite.setTextureRect(jumpRect[count]);
		if (jumpState == 1)
		{
			playerSprite.setTexture(jumpingTexture);
			count = 0;
			jumpState = 2;
		}
		if (jumpState == 2)
		{
			if (playerSprite.getPosition().y > 340)
			{
				playerSprite.move(0, -10);
			}
			else{
				jumpState = 3;
			}
		}
		else if (jumpState == 3)
		{
			if (playerSprite.getPosition().y < 540)
			{
				playerSprite.move(0, 10);
			}
			else{
				playerSprite.setTexture(playerTexture);
				jumpState = 0;
				jumping = false;
			}
		}
	}
	else{
		playerSprite.setTextureRect(walkRect[count]);
	}
}

