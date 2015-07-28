//Expand this for the player header file.
#include <SFML\Graphics.hpp>
#include <string>

class player{
public:
	sf::Texture playerTexture;
	sf::Texture jumpingTexture;
	sf::Sprite playerSprite;
	sf::IntRect walkRect[7];
	sf::IntRect jumpRect[6];

	bool jumping;
	int jumpState;
	int count;

	player();
	player(sf::Vector2f position, std::string texFileLoc, std::string jumpFileLoc);

	int animatePlayer();
	void update();
};
