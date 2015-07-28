//Expand for complete starter code.
// SFMLBasics.cpp : Defines the entry point for the console application.

//#include "stdafx.h"
#include <SFML\Graphics.hpp>
#include <SFML\Graphics\Rect.hpp>
#include <SFML\System\Clock.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "Sprites!");

	sf::Sprite mySprite;
	sf::Texture myTexture;
	sf::IntRect rect[7];
	rect[0] = sf::IntRect(0, 0, 64, 64);
	rect[1] = sf::IntRect(64, 0, 64, 64);
	rect[2] = sf::IntRect(128, 0, 64, 64);
	rect[3] = sf::IntRect(192, 0, 64, 64);
	rect[4] = sf::IntRect(0, 64, 64, 64);
	rect[5] = sf::IntRect(64, 64, 64, 64);
	rect[6] = sf::IntRect(128, 64, 64, 64);

	myTexture.loadFromFile("Textures/walk_cycle.png");

	int count = 0;

	mySprite.setTexture(myTexture);
	mySprite.setTextureRect(rect[count]);
	mySprite.setOrigin(15, 16);
	mySprite.setScale(1.5, 1.5);
	mySprite.setPosition(100, 100);

	float number = 0;

	sf::Clock clock;

	while (window.isOpen())
	{
		number = clock.getElapsedTime().asSeconds();
		if (number > .1)
		{
			if (count < 6){
				count++;
			}
			else{
				count = 0;
			}
			mySprite.setTextureRect(rect[count]);
			clock.restart();
		}

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(mySprite);
		window.display();
	}

	return 0;
}