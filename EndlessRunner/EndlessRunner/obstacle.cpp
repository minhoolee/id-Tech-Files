#include "obstacle.h"

obstacle::obstacle(){
}

obstacle::obstacle(sf::Vector2f position, float scaleX, float scaleY, sf::Texture* obstacleTexture)
{
	obstacleSprite.setTexture(*obstacleTexture);
	obstacleSprite.setScale(scaleX, scaleY);
	obstacleSprite.setPosition(position.x, position.y);

	srand(time(NULL));
}

void obstacle::update()
{
	obstacleSprite.move(-5, 0);
	if (obstacleSprite.getPosition().x < 0)
	{
		obstacleSprite.setPosition(1052, obstacleSprite.getPosition().y);
	}
}
//Could you fill the reposition and
//the reandomizeYPos functions?
void obstacle::reposition()
{
	obstacleSprite.setPosition(sf::Vector2f(1052, randomizeYPos()));
}

int obstacle::randomizeYPos()
{
	int randomY;
	int thePosition = 0;
	randomY = rand() % 3;
	if (randomY == 0)
	{
		thePosition = 550;
	}
	else if (randomY == 1)
	{
		thePosition = 450;
	}
	else if (randomY == 2)
	{
		thePosition = 350;
	}
	return thePosition;
}