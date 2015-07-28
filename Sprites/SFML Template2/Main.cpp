#include <SFML\Graphics.hpp>
#include <iostream>
using namespace std;

int main()
{
	const int window_x = 1000;
	const int window_y = 1000;
	sf::RenderWindow window(sf::VideoMode(window_x, window_y), "Sprites!");

	// Text to console
	cout << "Outputting to the Console" << endl;

	// Text to SFML window
	sf::Text myText;
	sf::Font myFont;

	myFont.loadFromFile("C:/Windows/Fonts/Arial.ttf");
	
	myText.setFont(myFont);
	myText.setString("Outputting to SFML Window");
	myText.setColor(sf::Color::Red);
	myText.setCharacterSize(24);
	myText.setStyle(sf::Text::Bold);

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		myText.move((float)0.05, 0);
		if (myText.getPosition().x > window_x)
			myText.setPosition(-200, 0);

		window.clear();
		window.draw(myText);
		window.display();
	}

	return 0;
}