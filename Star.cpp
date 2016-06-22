#include "Star.h"
#include "StarNamesGenerators.h"

Star::Star()
{
	shape1.setFillColor(sf::Color(255, 255, 255, 255));
	shape1.setRadius(rand() % 15 + 10);
	shape1.setOrigin(shape1.getRadius(), shape1.getRadius());

	shape2.setFillColor(sf::Color(255, 255, 255, 50));
	shape2.setRadius(rand() % 30 + 30);
	shape2.setOrigin(shape2.getRadius(), shape2.getRadius());
	
	shape3.setFillColor(sf::Color(255, 255, 255, 50));
	shape3.setRadius(rand() % 35 + 50);
	shape3.setOrigin(shape3.getRadius(), shape3.getRadius());

	font.loadFromFile("Baumans-Regular.ttf");

	StarNamesGenerators gen;
	name = gen.RandomName();
	std::cout << name << std::endl;

	nameText.setString(name);
	nameText.setFont(font);
	nameText.setCharacterSize(30);
	nameText.setScale(sf::Vector2f(0.4, 0.4));
	nameText.setColor(sf::Color(0, 0, 0, 255));
}

void Star::createSystem() {

}

void Star::setName(std::string name_) {
	name = name_;
}

void Star::setPosition(sf::Vector2f position_) {
	pos = position_;
	shape1.setPosition(pos);
	shape2.setPosition(pos);
	shape3.setPosition(pos);
	nameText.setPosition(sf::Vector2f(pos.x, pos.y - 100));
}

void Star::update(sf::RenderWindow& window) {
	
}

void Star::draw(sf::RenderWindow& window) {
	window.draw(shape1);
	window.draw(shape2);
	window.draw(shape3);
	window.draw(nameText);
}

sf::Vector2f Star::getPosition() {
	return pos;
}

void Star::getANewName() {
	StarNamesGenerators gen;
	name = gen.RandomName();
	std::cout << name << std::endl;
}