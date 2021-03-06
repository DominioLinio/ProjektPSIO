#pragma once
#include <SFML/Graphics.hpp>
#include "animacja.h"
#include "Collider.h"
#include "Enemy.h"

//tworze klase Player w ktorej zamieszczam metody, parametry playera, wykorzystuje rowniez ta klase do stworzenia tla
class Player
{
public:
	Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight);
	~Player();
	//nadaje funkcje ktora bedzie odswiezac ekran, aby player przesuwajac sie, faktycznie sie przesuwal i nie pozostawial za soba pikseli
	void update(float deltaTime);
	void updateB(float deltaTime);
	void updateB2(float deltaTime);
	void updateB3(float deltaTime);
	void Draw(sf::RenderWindow& window);
	//dodaje funkcje ktora podczas kolizji poprawi koordy playera odsuwaj?c go od przeszkod
	void OnCollision(sf::Vector2f direction);
	const sf::FloatRect getBounds() const;
	//zwraca pozycje playera i collider
	sf::Vector2f GetPosition()
	{
		return body.getPosition();
	}
	Collider GetCollider()
	{
		return Collider(body);
	}
float speed;
sf::Vector2f velocity;
private:
	//nadaje zmienne wykorzystywane do roznych funkcji playera
	sf::RectangleShape body;
	Animation animation;
	unsigned int row;
	
	bool faceRight;

	
	bool canJump;
	float jumpHeight;
	float health;
	sf::FloatRect bound;

};


