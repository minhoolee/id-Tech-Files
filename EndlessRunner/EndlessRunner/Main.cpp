#include "player.h"
#include "obstacle.h"
#include <string>
#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(1024, 768), "Running!");
	sf::Texture background;
	sf::Sprite bgSprite;

	int playerScore = 0;

	sf::Font scoreFont;
	scoreFont.loadFromFile("C:/Windows/Fonts/Arial.ttf");

	sf::Text scoreText;
	scoreText.setPosition(20, 730);
	scoreText.setFont(scoreFont);
	scoreText.setColor(sf::Color::White);
	scoreText.setString("Score: " + std::to_string(playerScore));
	scoreText.setCharacterSize(24);

	int lifeNum = 5;
	sf::Text lifeText;
	lifeText.setPosition(130, 730);
	lifeText.setFont(scoreFont);
	lifeText.setColor(sf::Color::White);
	lifeText.setString("Lives: " + std::to_string(lifeNum));
	lifeText.setCharacterSize(24);

	sf::Text helpText;
	helpText.setPosition(100, 300);
	helpText.setFont(scoreFont);
	helpText.setColor(sf::Color::White);
	helpText.setString("Get gems to win points, avoid the bombs!");
	helpText.setCharacterSize(48);

	sf::Texture obstacleTexture;
	obstacleTexture.loadFromFile("Textures/gem.png");

	sf::Texture badObstacleTexture;
	badObstacleTexture.loadFromFile("Textures/bomb.png");

	obstacle obstacles[4];
	obstacle badObstacles[2];

	float initialXPos = 500;
	//Can you make obstacles in a for loop?
	for (int i = 0; i < 4; i++)
	{
		obstacle tempObstacle(sf::Vector2f(initialXPos, 540), 1.5, 1.5, &obstacleTexture);
		obstacles[i] = tempObstacle;
		initialXPos += 200;
	}
	initialXPos = 300;
	for (int i = 0; i < 2; i++)
	{
		obstacle tempObstacle(sf::Vector2f(initialXPos, 540), 0.2, 0.2, &badObstacleTexture);
		badObstacles[i] = tempObstacle;
		initialXPos += 400;
	}

	background.loadFromFile("Textures/city_background.png");
	bgSprite.setTexture(background);
	bgSprite.setOrigin(0, 0);
	window.setFramerateLimit(40);

	player thePlayer;

	sf::Clock animateClock;
	float animateTimer = 0.0f;

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Space)
				{
					if (!thePlayer.jumping)
					{
						thePlayer.jumpState = 1;
						thePlayer.jumping = true;
					}
				}
				if (event.key.code == sf::Keyboard::R)
				{
					helpText.setPosition(100, 300);
					helpText.setString("Get gems to win points, avoid the bombs!");
					thePlayer.playerSprite.setPosition(100, 540);
					playerScore = 0;
					lifeNum = 5;
				}
			}
		}

		animateTimer = animateClock.getElapsedTime().asSeconds();
		if (animateTimer > 0.1f)
		{
			thePlayer.animatePlayer();
			animateClock.restart();
		}

		thePlayer.update();

		window.clear();
		window.draw(bgSprite);
		for (int i = 0; i < 4; i++)
		{
			obstacles[i].update();
			window.draw(obstacles[i].obstacleSprite);

			if (thePlayer.playerSprite.getGlobalBounds().intersects(obstacles[i].obstacleSprite.getGlobalBounds()))
			{
				//Could you call the function?
				obstacles[i].reposition();
				playerScore++;
				scoreText.setString("Score: " + std::to_string(playerScore));
				helpText.setPosition(250, 300);
				helpText.setString("Nice! Keep getting gems!");
			}
			
		}
		for (int i = 0; i < 2; i++)
		{
			badObstacles[i].update();
			window.draw(badObstacles[i].obstacleSprite);

			std::cout << thePlayer.playerSprite.getGlobalBounds().intersects(badObstacles[i].obstacleSprite.getGlobalBounds()) << std::endl;
			if (thePlayer.playerSprite.getGlobalBounds().intersects(badObstacles[i].obstacleSprite.getGlobalBounds()))
			{
				//Could you call the function?
				badObstacles[i].reposition();
				lifeNum--;
				lifeText.setString("Lives: " + std::to_string(lifeNum));
				helpText.setPosition(200, 300);
				helpText.setString("Sorry, you hit a bomb. -1 Life.");
				if (lifeNum == 0)
				{
					thePlayer.playerSprite.setPosition(sf::Vector2f(-100, -100));
					helpText.setString("Game Over. Press 'r' to restart.");
				}
			}
		}
		
		window.draw(thePlayer.playerSprite);
		window.draw(scoreText);
		window.draw(lifeText);
		window.draw(helpText);
		window.display();
	}

	return 0;
}

