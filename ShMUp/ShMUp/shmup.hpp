// shmup.hpp
#include<SFML/Graphics.hpp>

#define WIDTH 600
#define HEIGHT 800

#define PLAYER_SPEED 400

#define BULLET_SPEED 750

#define ENEMY_SPEED 100

// #defines, class declaration, function prototypes go here

class ShmupGame;

class GameObject{
public:
	sf::Sprite sprite;
	ShmupGame* game;

	bool enabled = false;

	GameObject();

	GameObject(sf::Vector2f position, ShmupGame* g);

	virtual void update(sf::Time t);
	bool isColliding(GameObject* g);
};

class Enemy : public GameObject{
public:
	void update(sf::Time t);

	sf::Clock fireTimer;
	sf::Clock moveTimer;

	float nextShotTime;

	bool movingDown = false;
	bool movingRight = true;

	Enemy();
	Enemy(sf::Vector2f position, ShmupGame* game);

	void fire();
};

class Player : public GameObject{
public:
	sf::Clock shotTimer;

	void update(sf::Time t);

	Player();
	Player(sf::Vector2f position, ShmupGame* game);

	void fire();
};

class PlayerBullet : public GameObject{
public:
	bool enabled = false;
	sf::Vector2f velocity;

	PlayerBullet();

	void update(sf::Time t);
};

class EnemyBullet : public GameObject{
public:
	bool enabled = false;
	sf::Vector2f velocity;

	EnemyBullet();

	void update(sf::Time t);
};

class ShmupGame{
public:
	// Declare class variables, you can initialize primitives but not things with constructors
	sf::RenderWindow window;

	sf::Texture bg;
	sf::Sprite bgSprite;

	// Player and Enemy Textures
	sf::Texture enemyTexture;
	sf::Texture playerTexture;
	sf::Texture playerBulletTexture;
	sf::Texture enemyBulletTexture;

	// Score Text
	sf::Font font;
	int p1Score = 0;
	sf::Text p1ScoreText;

	int currentBullet = 0;
	PlayerBullet playerBullets[50];

	int currentEnemyBullet = 0;
	EnemyBullet enemyBullets[50];

	Enemy enemies[10];

	Player player;

	bool p1MovingUp = false;
	bool p1MovingDown = false;
	bool p1MovingLeft = false;
	bool p1MovingRight = false;
	bool firing = false;

	ShmupGame();

	void run();
	void update(sf::Time t);
	void processEvents();
	void render();

	void spawnEnemies(int count);
};