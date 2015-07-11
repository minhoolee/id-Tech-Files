#ifndef GAME_OBJECT_HPP 
#define GAME_OBJECT_HPP

#include <SFML/Graphics.hpp>

class GalagaGame;

class GameObject
{
public:
	sf::Sprite sprite;
	GalagaGame *game;

	bool enabled = false;

	// Take textures from this texture
	sf::Texture mainTexture;

	// Game properties
	static const int GAME_WIDTH = 1600;
	static const int GAME_HEIGHT = 1000;

	GameObject();
	GameObject(sf::Vector2f position, GalagaGame *game);

	virtual void update(sf::Time t);
	bool isColliding(GameObject* game);
};

#endif // GAME_OBJECT_HPP