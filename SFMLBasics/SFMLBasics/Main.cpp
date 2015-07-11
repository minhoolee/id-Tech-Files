#include <SFML/graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(640, 480), "SFML works!");

	sf::CircleShape circle;
	circle.setFillColor(sf::Color::Cyan);
	circle.setRadius(100);
	circle.setPosition(200, 100);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(circle);
		window.display();
	}

	return 0;
}