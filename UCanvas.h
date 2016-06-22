#ifndef UCANVAS_H
#define UCANVAS_H
#include <SFML\Graphics.hpp>
#include <iostream>
#include <vector>

#include "UButton.h"
#include "UCheckBox.h"
#include "UProgressBar.h"
#include "UPanel.h"
#include "USlider.h"
#include "UImage.h"
#include "UText.h"
#include "UTextBox.h"

class UCanvas
{
public:
	UCanvas();

	void update(sf::RenderWindow& window, float zoomLevel);
	void draw(sf::RenderWindow& window, float zoomLevel);
	// UI ELEMENTS
	// MOST BASIC FIRST


	//Button
	UButton& createButton(int id);
	UButton* getButton(int id);

	//Text
	UText& createText(int id);
	UText* getText(int id);

private:
	sf::Vector2f canvasSize;

	std::vector<UButton> buttons;
	//std::vector<UCheckBox> checkBoxes;
	//UProgressBar progressBars[1000];
	//UPanel panels[1000];
	//USlider sliders[1000];
	//UImage images[1000];
	std::vector<UText> texts;
};
#endif
