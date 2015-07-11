#include "galagaGame.hpp"

GalagaGame::GalagaGame() : window(sf::VideoMode(GAME_WIDTH, GAME_HEIGHT), "Galaga 2.0")
{
	window.setFramerateLimit(60);

	// TODO: TAKE OFF BACKGROUND? DEFAULT = BLACK
	// Background
	backgroundTexture.loadFromFile("Textures/white_background.png");
	backgroundSprite.setTexture(backgroundTexture);
	backgroundSprite.setScale(10000, 10000);

	// Main texture to pull others off of
	mainTexture.loadFromFile("Textures/enemy_spaceship_levels.png");

	player1 = Player(sf::Vector2f((GAME_WIDTH / 2), (GAME_HEIGHT / 2)), this);
	player2 = Player(sf::Vector2f((GAME_WIDTH / 2), (GAME_HEIGHT / 2)), this);
	window.clear();

	// Font
	font.loadFromFile("Fonts/galaga_fonts.ttf");

	p1ScoreText.setPosition(50, 30);
	p1ScoreText.setFont(font);
	p1ScoreText.setColor(sf::Color::White);
	p1ScoreText.setCharacterSize(24);

	helpText.setPosition(500, 200);
	helpText.setFont(font);
	helpText.setColor(sf::Color::White);
	helpText.setString("Press 'M' for Multiplayer Mode!");
	helpText.setCharacterSize(24);
}

void GalagaGame::run()
{
	srand( (unsigned int) time(NULL) );

	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	spawnEnemies(10);
	p1ScoreText.setString(std::to_string(player1Score));
	
	if (MULTI_PLAYER)
		p2ScoreText.setString(std::to_string(player2Score));

	while (window.isOpen())
	{
		processEvents();
		timeSinceLastUpdate = clock.restart();
		update(timeSinceLastUpdate);

		//Drawing goes here
		render();
	}
}

void GalagaGame::update(sf::Time time)
{
	if (player1.enabled)
	{
		if (rotationMode > 24)
		{
			player1.sprite.setRotation(0);
			rotationMode = 0;
		}
		player1.update(time);
		rotationMode++;
		//std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}

	int enemiesLeft = 0;
	for (Enemy &e : enemies)
	{
		if (e.enabled){
			e.update(time);
			enemiesLeft++;
		}
	}

	if (enemiesLeft == 0)
	{
		spawnEnemies(10);
	}

	if (MULTI_PLAYER)
	{
		if (player2.enabled)
			player2.update(time);


	}

}

void GalagaGame::processEvents()
{
	sf::Event event;

	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			window.close();
		}

		// Control player one
		if (event.type == sf::Event::KeyPressed)
		{
			// 'M' for multiplayer modes
			if (event.key.code == sf::Keyboard::M)
			{
				SINGLE_PLAYER = 0;
				MULTI_PLAYER = 1;
			}
			if (event.key.code == sf::Keyboard::Q)
			{
				window.close();
			}

			if (event.key.code == sf::Keyboard::Up)
			{
				player1.isPlayerMovingUp = true;
			}
			if (event.key.code == sf::Keyboard::Down)
			{
				player1.isPlayerMovingDown = true;
			}
			if (event.key.code == sf::Keyboard::Left)
			{
				player1.isPlayerMovingLeft = true;
			}
			if (event.key.code == sf::Keyboard::Right)
			{
				player1.isPlayerMovingRight = true;
			}
			if (event.key.code == sf::Keyboard::Space){
				player1.isPlayerFiring = true;
			}
		}
		if (event.type == sf::Event::KeyReleased)
		{
			if (event.key.code == sf::Keyboard::Up)
			{
				player1.isPlayerMovingUp = false;
			}
			if (event.key.code == sf::Keyboard::Down)
			{
				player1.isPlayerMovingDown = false;
			}
			if (event.key.code == sf::Keyboard::Left)
			{
				player1.isPlayerMovingLeft = false;
			}
			if (event.key.code == sf::Keyboard::Right)
			{
				player1.isPlayerMovingRight = false;
			}
			if (event.key.code == sf::Keyboard::Space)
			{
				player1.isPlayerFiring = false;
			}
		}

		// Control player one and player two
		if (MULTI_PLAYER)
		{
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::W)
				{
					player2.isPlayerMovingUp = true;
				}
				if (event.key.code == sf::Keyboard::S)
				{
					player2.isPlayerMovingDown = true;
				}
				if (event.key.code == sf::Keyboard::A)
				{
					player2.isPlayerMovingLeft = true;
				}
				if (event.key.code == sf::Keyboard::D)
				{
					player2.isPlayerMovingRight = true;
				}
				if (event.key.code == sf::Keyboard::LAlt){
					player2.isPlayerFiring = true;
				}
			}
			if (event.type == sf::Event::KeyReleased)
			{
				if (event.key.code == sf::Keyboard::W)
				{
					player2.isPlayerMovingUp = false;
				}
				if (event.key.code == sf::Keyboard::S)
				{
					player2.isPlayerMovingDown = false;
				}
				if (event.key.code == sf::Keyboard::A)
				{
					player2.isPlayerMovingLeft = false;
				}
				if (event.key.code == sf::Keyboard::D)
				{
					player2.isPlayerMovingRight = false;
				}
				if (event.key.code == sf::Keyboard::LAlt)
				{
					player2.isPlayerFiring = false;
				}
			}
		}
	}
}

void GalagaGame::render()
{
	window.clear();
	window.draw(backgroundSprite);

	if (player1.enabled)
		window.draw(player1.sprite);

	for (PlayerBullet bullet : player1.playerBullets)
	{
		if (bullet.enabled)
		{
			window.draw(bullet.sprite);
		}
	}

	// NOTE: MIGHT NEED TO CHANGE THIS 0TH INDEX STUFF
	for (EnemyBullet bullet : enemies[0].enemyBullets)
	{
		if (bullet.enabled)
		{
			window.draw(bullet.sprite);
		}
	}

	for (Enemy e : enemies)
	{
		if (e.enabled)
		{
			window.draw(e.sprite);
		}
	}

	if (MULTI_PLAYER)
	{
		if (player2.enabled)
			window.draw(player2.sprite);

		for (PlayerBullet bullet : player2.playerBullets)
		{
			if (bullet.enabled)
			{
				window.draw(bullet.sprite);
			}
		}
	}

	window.draw(p1ScoreText);
	window.draw(helpText);

	if (MULTI_PLAYER)
		window.draw(p2ScoreText);

	window.display();
}

void GalagaGame::spawnEnemies(int count)
{
	if (count > 10)
		count = 10;
	for (int i = 0; i < count; i++)
	{
		if (i < 5)
		{
			enemies[i] = Enemy(sf::Vector2f(i * 100, 50), this);
		}
		else
		{
			enemies[i] = Enemy(sf::Vector2f(GAME_WIDTH - ((i - 5) * 100), 150), this);
			enemies[i].isEnemyMovingRight = false;
		}
		enemies[i].enabled = true;
		enemies[i].nextShotTime = rand() % 6;
	}
}
