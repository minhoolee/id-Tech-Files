#include <SFML\Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "Events");
	sf::CircleShape shape(20.f);
	shape.setFillColor(sf::Color::Green);

	bool isMovingUp = false;
	bool isMovingDown = false;
	bool isMovingLeft = false;
	bool isMovingRight = false;

	sf::Clock clock;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::W)
				{
					isMovingUp = true;
				}
				if (event.key.code == sf::Keyboard::S)
				{
					isMovingDown = true;
				}
				if (event.key.code == sf::Keyboard::A)
				{
					isMovingLeft = true;
				}
				if (event.key.code == sf::Keyboard::D)
				{
					isMovingRight = true;
				}
			}
			if (event.type == sf::Event::KeyReleased)
			{
				if (event.key.code == sf::Keyboard::W)
				{
					isMovingUp = false;
				}
				if (event.key.code == sf::Keyboard::S)
				{
					isMovingDown = false;
				}
				if (event.key.code == sf::Keyboard::A)
				{
					isMovingLeft = false;
				}
				if (event.key.code == sf::Keyboard::D)
				{
					isMovingRight = false;
				}
			}
		}

		sf::Vector2f movement(0, 0);
		if (isMovingUp)
			movement.y -= 100;
		if (isMovingDown)
			movement.y += 100;
		if (isMovingLeft)
			movement.x -= 100;
		if (isMovingRight)
			movement.x += 100;

		sf::Time changeInTime = clock.restart();
	
		shape.move(movement * changeInTime.asSeconds());
		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}