#pragma once
#include "UElement.h"
class UText : public UElement
{
public:
	UText();
	void draw(sf::RenderWindow& window);
	void update(sf::RenderWindow& window, float zoomLevel);
	std::string label;
private:
	sf::Text text;
};

