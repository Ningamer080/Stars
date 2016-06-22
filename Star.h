#ifndef STAR_H
#define STAR_H

#include <string>
#include <SFML\Graphics.hpp>
class Star
{
public:
	Star();
	enum starClass {
		typeM, typeK, typeG, typeF, typeA, typeB, typeO, Blackhole
	};
	starClass Class;

	void createSystem();
	void setName(std::string name_);
	void setPosition(sf::Vector2f position_);
	void setColor(sf::Color color);
	void setRayBlinkingSize(float value);
	void setRayBlinkingSpeed(float value);
	void getANewName();

	std::string getName();
	sf::Color getColor();
	sf::Vector2f getPosition();

	void update(sf::RenderWindow& window);
	void draw(sf::RenderWindow& window);
private:

	float StarRayBlinkSize;
	float StarRayBlinkSpeed;

	std::string name;
	sf::Font font;
	sf::Text nameText;
	sf::Vector2f pos;
	sf::CircleShape shape1;
	sf::CircleShape shape2;
	sf::CircleShape shape3;
};

#endif