#include <SFML/Graphics.hpp>
#include <string>


class Pong
{
public:
	sf::RenderWindow gameWindow;
	sf::RectangleShape p1Paddle, p2Paddle;
	sf::CircleShape ball;


	bool p1MovingUp, p1MovingDown, p2MovingUp, p2MovingDown;

	float paddleSpeed = 1000;

	sf::Vector2f ballMovement;
	float ballSpeed = 250;



	sf::Font font;

	int p1Score = 0, p2Score = 0;
	sf::Text p1ScoreText, p2ScoreText;

	Pong() : gameWindow(sf::VideoMode(600, 480), "Pong")
	{
		ball.setFillColor(sf::Color::Cyan);
		ball.setPosition(100.0, 100.0);
		ball.setRadius(10.f);

		p1Paddle.setFillColor(sf::Color::Green);
		p1Paddle.setPosition(10.0, 100.0);
		p1Paddle.setSize(sf::Vector2f(10.0, 100.0));

		p2Paddle.setFillColor(sf::Color::Red);
		p2Paddle.setPosition(580.0, 100.0);
		p2Paddle.setSize(sf::Vector2f(10.0, 100.0));

		p1MovingUp = false;
		p1MovingDown = false;
		p2MovingUp = false;
		p2MovingDown = false;

		ballMovement = sf::Vector2f(ballSpeed, ballSpeed);
		font.loadFromFile("arial.ttf");

		p1ScoreText.setPosition(150, 10);
		p1ScoreText.setFont(font);
		p1ScoreText.setString(std::to_string(p1Score));
		p1ScoreText.setColor(sf::Color::Red);
		p1ScoreText.setCharacterSize(24);

		p2ScoreText.setPosition(450, 10);
		p2ScoreText.setFont(font);
		p2ScoreText.setString(std::to_string(p2Score));
		p2ScoreText.setColor(sf::Color::Red);
		p2ScoreText.setCharacterSize(24);
	}

	void run()
	{
		sf::Clock clock;
		sf::Time timeSinceLastUpdate = sf::Time::Zero;



		while (gameWindow.isOpen())
		{
			processEvents();
			timeSinceLastUpdate = clock.restart();
			update(timeSinceLastUpdate);

			//Drawing goes here
			render();
		}
	}

	void processEvents()
	{
		sf::Event event;
		while (gameWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				gameWindow.close();
			}
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::W)
				{
					p1MovingUp = true;
				}
				if (event.key.code == sf::Keyboard::S)
				{
					p1MovingDown = true;
				}
				if (event.key.code == sf::Keyboard::Up)
				{
					p2MovingUp = true;
				}
				if (event.key.code == sf::Keyboard::Down)
				{
					p2MovingDown = true;
				}
			}
			if (event.type == sf::Event::KeyReleased)
			{
				if (event.key.code == sf::Keyboard::W)
				{
					p1MovingUp = false;
				}
				if (event.key.code == sf::Keyboard::S)
				{
					p1MovingDown = false;
				}
				if (event.key.code == sf::Keyboard::Up)
				{
					p2MovingUp = false;
				}
				if (event.key.code == sf::Keyboard::Down)
				{
					p2MovingDown = false;
				}
			}
		}
	}
	void update(sf::Time timeChange)
	{
		sf::Vector2f p1Movement(0, 0);
		sf::Vector2f p2Movement(0, 0);


		if (p1MovingUp)
			p1Movement.y -= paddleSpeed;
		if (p1MovingDown)
			p1Movement.y += paddleSpeed;
		if (p2MovingUp)
			p2Movement.y -= paddleSpeed;
		if (p2MovingDown)
			p2Movement.y += paddleSpeed;

		p1Paddle.move(p1Movement * timeChange.asSeconds());
		p2Paddle.move(p2Movement * timeChange.asSeconds());


		// Check collision
		if (ball.getPosition().y < 0 || ball.getPosition().y > 480){
			ballMovement.y *= -1;
		}
		if (ball.getGlobalBounds().intersects(p1Paddle.getGlobalBounds()) || ball.getGlobalBounds().intersects(p2Paddle.getGlobalBounds())){
			ballMovement.x *= -1;
		}



		// Scoring
		if (ball.getPosition().x > 600){
			// P1 scores
			ball.setPosition(300, 240);
			p1Score++;
			p1ScoreText.setString(std::to_string(p1Score));
		}
		else if (ball.getPosition().x < 0){
			// P2 scores
			ball.setPosition(300, 240);
			p2Score++;
			p2ScoreText.setString(std::to_string(p2Score));
		}

		ball.move(ballMovement * timeChange.asSeconds());


	}

	void render(){
		sf::Vector2f vec1(1, 0), vec2(0, 0);
		gameWindow.clear();
		gameWindow.draw(p1Paddle);
		gameWindow.draw(p2Paddle);

		gameWindow.draw(p1ScoreText);

		gameWindow.draw(p2ScoreText);

		gameWindow.draw(ball);
		gameWindow.display();
	}

};

int main(){
	Pong pong;

	pong.run();
}


