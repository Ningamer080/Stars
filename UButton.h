#pragma once
#include "UElement.h"
class UButton : public UElement
{
public:
	UButton();
	void update(sf::RenderWindow& window, float zoomLevel);
	void draw(sf::RenderWindow& window, float zoomLevel);

	void setPosition(sf::Vector2i pos_);
	void setSize(sf::Vector2f size_);

	sf::Vector2i getPosition();
	sf::Vector2f getGlobalPosition();
	sf::Vector2f getSize();

	void disable(bool value);
	bool getDisabled();

	void setOutlineThickness(int value);

	//Coloring
	void setMainColor(sf::Color color);
	void setMainDisabledColor(sf::Color color);
	void setOutlineColor(sf::Color color);
	void setOutlineOverColor(sf::Color color);
	void setOutlinePressedColor(sf::Color color);
	void setTextColor(sf::Color color);

	void setFont(std::string str);
	

	float outline = 2;

	std::string label;

	bool onOutput();
	bool onMouseOver();

private:

	sf::Color mainColor;
	sf::Color mainDisabledColor;
	sf::Color outlineColor;
	sf::Color outlineOverColor;
	sf::Color outlinePressedColor;

	sf::Vector2f size;
	sf::Vector2i firstClickPos;
	bool wasMouseClicked;
	bool isOver;
	bool output;
	bool isDisabled;
	int outlinethickness;

	sf::Font fnt;
	sf::Text text;

	sf::Text otherText;
	sf::RectangleShape mainShape;
	sf::RectangleShape outlineShape;
};

