//Expand for the obstacle header.
#include <SFML\Graphics.hpp>

class obstacle{
public:
	sf::Texture obstacleTexture;
	sf::Sprite obstacleSprite;

	float yPos;

	obstacle();
	obstacle(sf::Vector2f position, float scaleX, float scaleY, sf::Texture* obstacleTexture);

	//Create a prototype for updating 
	//movement, repositioning, and 
	//randomizing y position.
	void update();
	void reposition();
	int randomizeYPos();
};