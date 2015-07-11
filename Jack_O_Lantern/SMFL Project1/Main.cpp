#include <SFML/graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(400, 400), "SFML works!");

	// Face
	sf::CircleShape face;
	face.setRadius(200);
	face.setPosition(0, 0);
	face.setFillColor(sf::Color::Yellow);

	// Eyes
	sf::CircleShape lEye;
	lEye.setFillColor(sf::Color::Black);
	lEye.setPointCount(3);
	lEye.setRadius(50);
	lEye.setPosition(50, 50);

	sf::CircleShape rEye;
	rEye.setFillColor(sf::Color::Black);
	rEye.setPointCount(3);
	rEye.setRadius(50);
	rEye.setPosition(250, 50);

	// Eyes
	sf::ConvexShape mouth;
	mouth.setFillColor(sf::Color::Black);
	mouth.setPointCount(5);
	mouth.setPoint(0, sf::Vector2f(50, 300));
	mouth.setPoint(1, sf::Vector2f(350, 300));
	mouth.setPoint(2, sf::Vector2f(300, 350));
	mouth.setPoint(3, sf::Vector2f(200, 375));
	mouth.setPoint(4, sf::Vector2f(100, 350));
	
	// Teeth
	sf::RectangleShape teeth[4];
	for (int i = 0; i < 4; i++)
	{
		teeth[i].setFillColor(sf::Color::White);
		teeth[i].setSize(sf::Vector2f(25, 25));
	}
	teeth[0].setPosition(125, 300);
	teeth[1].setPosition(175, 300);
	teeth[2].setPosition(225, 300);
	teeth[3].setPosition(275, 300);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(face);
		window.draw(lEye);
		window.draw(rEye);
		for (int i = 0; i < 4; i++)
			window.draw(teeth[i]);
		window.display();
	}

	return 0;
}