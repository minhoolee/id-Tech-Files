#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <time.h>

class Init_Sprites
{
public:
	// Backgrounds
	sf::Texture background_texture;
	sf::Sprite background[49];

	// Player
	sf::Sprite player;
	sf::Texture texture_left;
	sf::Texture texture_right;

	// Targets
	sf::Texture target_texture;
	sf::Sprite target[100];
	time_t max_x = 0; // Seeds for random number generator
	time_t max_y = 0;
	int target_x = 0;
	int target_y = 0;
	int target_rot = 0;

	Init_Sprites(sf::Texture	&bg_text,
				 sf::Sprite		&bg,
				 sf::Sprite		&p,
			 	 sf::Texture	&t_left,
			 	 sf::Texture	&t_right,
			  	 sf::Texture	&t_texture,
			 	 sf::Sprite		&t);

	void start_backgrounds();
	void start_player();
	void start_targets();

};

Init_Sprites::Init_Sprites( sf::Texture		&bg_text,
							sf::Sprite		&bg, 
							sf::Sprite		&p, 
							sf::Texture		&t_left, 
							sf::Texture		&t_right, 
							sf::Texture		&t_texture, 
							sf::Sprite		&t )
{
	// Backgrounds
	background_texture = bg_text;
	for (int i = 0; i < 49; i++)
	{
		sf::Sprite *p = &bg;
		background[i] = *(p + i);
	}

	// Player
	player = p;
	texture_left = t_left;
	texture_right = t_right;

	// Targets
	target_texture = t_texture;
	for (int i = 0; i < 100; i++)
	{
		sf::Sprite *p = &t;
		target[i] = *(p + i);
	}
}

void Init_Sprites::start_backgrounds()
{
	// Sprite for the background
	background_texture.loadFromFile("C:/Users/student/Desktop/Min Hoo L/Assets/Platformer Game/stars_background.png");

	int bg_index = 0;
	for (int outer = 0; outer < 7; outer++)
	{
		for (int inner = 0; inner < 7; inner++)
		{
			background[bg_index].setTexture(background_texture);
			background[bg_index].setPosition( (float) (inner * 1280), (float) (outer * 960) );
			background[bg_index].setScale(2.2f, 1.5f);
			bg_index++;
		}
	}
}

void Init_Sprites::start_player()
{
	// User controlled sprite with textures for left and right
	
	texture_left.loadFromFile("C:/Users/student/Desktop/Min Hoo L/Assets/Platformer Game/player_ship_left.png");
	texture_right.loadFromFile("C:/Users/student/Desktop/Min Hoo L/Assets/Platformer Game/player_ship_right.png");

	player.setTexture(texture_left);
	player.setOrigin(15, 16);
	player.setPosition(640 + (1280 * 4), 480 + (960 * 4));

}

void Init_Sprites::start_targets()
{
	// Sprite for the targets that the player will pick up
	target_texture.loadFromFile("C:/Users/student/Desktop/Min Hoo L/Assets/Platformer Game/small_asteroid.png");
	
	// time_t seed so that objects stay within bounds
	max_x = 1280 * 7;
	max_y = 960 * 7;

	// Seed random number generator
	srand( (unsigned int) time(NULL) );

	for (int target_num = 0; target_num < 100; target_num++)
	{
		target[target_num].setTexture(target_texture);
		target[target_num].setOrigin(32, 32);

		target_x = rand() % (max_x + 1);
		target_y = rand() % (max_y + 1);
		target_rot = rand() % (360 + 1);

		// Set the position of target sprite
		target[target_num].setPosition( (float) target_x, (float) target_y ); 

		// Rotate target sprite
		target[target_num].rotate( (float) target_rot); 
	}
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(1280, 960), "Camera");

	// Backgrounds
	sf::Texture background_texture;
	sf::Sprite background[49];

	// Player
	sf::Sprite player;
	sf::Texture texture_left;
	sf::Texture texture_right;

	// Targets
	sf::Texture target_texture;
	sf::Sprite target[100];

	Init_Sprites init ( background_texture, *background, player, texture_left, texture_right, target_texture, *target );
	init.start_backgrounds();
	init.start_player();
	init.start_targets();

	// Camera for viewing the screen
	sf::View camera(sf::FloatRect( (1280 * 4), (960 * 4), 1280, 960) );
	camera.setSize(1280, 960);

	// Booleans for moving sprite
	bool isMovingUp = false;
	bool isMovingDown = false;
	bool isMovingLeft = false;
	bool isMovingRight = false;

	while (window.isOpen())
	{
		sf::Event event;

		// Rotate each of the targets slowly
		for (int target_num = 0; target_num < 100; target_num++)
		{ 
			init.target[target_num].rotate(0.01f);
		}

		// TODO: When player meets target, target disappears and player earns points


		// Listen for events
		while (window.pollEvent(event))
		{
			// Close window on 'x'
			if (event.type == sf::Event::Closed)
				window.close();

			// No 'else-if's because multiple keys can be pressed for smoother movement
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Up)
					isMovingUp = true;
				if (event.key.code == sf::Keyboard::Down)
					isMovingDown = true;
				if (event.key.code == sf::Keyboard::Left)
					isMovingLeft = true;
				if (event.key.code == sf::Keyboard::Right)
					isMovingRight = true;
			}

			if (event.type == sf::Event::KeyReleased)
			{
				if (event.key.code == sf::Keyboard::Up)
					isMovingUp = false;
				if (event.key.code == sf::Keyboard::Down)
					isMovingDown = false;
				if (event.key.code == sf::Keyboard::Left)
					isMovingLeft = false;
				if (event.key.code == sf::Keyboard::Right)
					isMovingRight = false;
			}
		}

		// Move player sprite appropriately, change texture based on direction, and move camera as well
		sf::Vector2f moveView(0, 0);

		if (isMovingUp)
		{
			init.player.move(0.0f, -0.2f);
			moveView.y -= 0.2f;
		}
		if (isMovingDown)
		{
			init.player.move(0.0f, 0.2f);
			moveView.y += 0.2f;
		}
		if (isMovingLeft)
		{
			init.player.move(-0.2f, 0.0f);
			moveView.x -= 0.2f;
			init.player.setTexture(init.texture_left);
		}
		if (isMovingRight)
		{
			init.player.move(0.2f, 0.0f);
			moveView.x += 0.2f;
			init.player.setTexture(init.texture_right);
		}

		camera.move(moveView);
		window.setView(camera);

		window.clear();
		for (int i = 0; i < 49; i++)
		{
			window.draw(init.background[i]);
		}

		for (int target_num = 0; target_num < 100; target_num++)
		{
			window.draw( init.target[target_num] );
		}

		window.draw(init.player);
		window.display();
	}


	return 0;
}