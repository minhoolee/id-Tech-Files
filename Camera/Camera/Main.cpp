#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "Camera");

	sf::Texture backText;
	backText.loadFromFile("C:Assets/Platformer Game/stars_background.png");

	sf::Sprite backSprite;
	backSprite.setTexture(backText);

	sf::View camera(sf::FloatRect(50, 50, 150, 150));
	camera.setSize(300, 300); 
	camera.setCenter(150, 150);

	bool isMovingLeft = false;
	bool isMovingRight = false;
	bool isMovingDown = false;
	bool isMovingUp = false;

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			else if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Up)
				{
					isMovingUp = true;
				}
				if (event.key.code == sf::Keyboard::Down)
				{
					isMovingDown = true;
				}
				if (event.key.code == sf::Keyboard::Left)
				{
					isMovingLeft = true;
				}
				if (event.key.code == sf::Keyboard::Right)
				{
					isMovingRight = true;
				}
			}
			if (event.type == sf::Event::KeyReleased)
			{
				if (event.key.code == sf::Keyboard::Up)
				{
					isMovingUp = false;
				}
				if (event.key.code == sf::Keyboard::Down)
				{
					isMovingDown = false;
				}
				if (event.key.code == sf::Keyboard::Left)
				{
					isMovingLeft = false;
				}
				if (event.key.code == sf::Keyboard::Right)
				{
					isMovingRight = false;
				}
			}
		}

		sf::Vector2f viewMove(0, 0);
		if (isMovingUp)
			viewMove.y -= 0.1f;
		if (isMovingDown)
			viewMove.y += 0.1f;
		if (isMovingLeft)
			viewMove.x -= 0.1f;
		if (isMovingRight)
			viewMove.x += 0.1f;

		camera.move(viewMove);
		window.setView(camera);

		window.clear();
		window.draw(backSprite);
		window.display();
	}

	return 0;
}