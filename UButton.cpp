#include "UButton.h"
#include <iostream>

UButton::UButton()
{
	size = sf::Vector2f(120.0f, 28.0f);

	outlinethickness = 2;

	mainShape.setSize(size);
	mainShape.setPosition(sf::Vector2f(0.0f, 0.0f));
	mainShape.setFillColor(sf::Color(60, 60, 60));

	outlineShape.setSize(size);
	outlineShape.setPosition(sf::Vector2f(0.0f, 0.0f));
	outlineShape.setFillColor(sf::Color(182, 101, 40));

	wasMouseClicked = false;
	isDisabled = false;
	isOver = false;
	output = false;

	mainColor = sf::Color(70, 70, 70);
	mainDisabledColor = sf::Color(78, 78, 78);
	outlineColor = sf::Color(79, 127, 199);
	outlineOverColor = sf::Color(99, 147, 219);
	outlinePressedColor = sf::Color(119, 167, 239);
	text.setColor(sf::Color(255, 255, 255));

	if (!fnt.loadFromFile("cuyabra.otf")) {
		std::cout << "Failed to load font !" << std::endl;
	}

	text.setFont(fnt);
	text.setCharacterSize(15);
	text.setColor(sf::Color(25, 25, 25, 255));
	label = "Button" + std::to_string(ID);
	text.setScale(sf::Vector2f(3, 3));
	text.setString(label);
}

void UButton::update(sf::RenderWindow& window, float zoomLevel) {
	localPos = sf::Vector2i(50, 50);
	mainShape.setPosition(sf::Vector2f(globalPos.x + outlinethickness * zoomLevel, globalPos.y + outlinethickness * zoomLevel));
	outlineShape.setPosition(globalPos);
	text.setPosition(sf::Vector2f(globalPos.x + ((outlinethickness + 3) * zoomLevel), globalPos.x + ((outlinethickness + 3) * zoomLevel)));


	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		if (wasMouseClicked == false) {
			firstClickPos = sf::Mouse::getPosition(window);
		}
		wasMouseClicked = true;
	}
	else {
		wasMouseClicked = false;
	}

	if (isDisabled) {
		mainShape.setFillColor(mainDisabledColor);
	}
	else{
		mainShape.setFillColor(mainColor);
	}

	if (sf::Mouse::getPosition(window).x > localPos.x && 
		sf::Mouse::getPosition(window).y > localPos.y &&
		sf::Mouse::getPosition(window).x < localPos.x + (int) mainShape.getSize().x &&
		sf::Mouse::getPosition(window).y < localPos.y + (int) mainShape.getSize().y &&
		isDisabled == false) {

		outlineShape.setFillColor(outlineOverColor);
		isOver = true;
	}
	else {
		isOver = false;
		outlineShape.setFillColor(outlineColor);
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && firstClickPos.x > localPos.x && 
		firstClickPos.y > localPos.y &&
		firstClickPos.x < localPos.x + (int) mainShape.getSize().x &&
		firstClickPos.y < localPos.y + (int) mainShape.getSize().y &&  
		isDisabled == false &&
		isOver == true) {

		output = true;
		outlineShape.setFillColor(outlinePressedColor);
	}
	else {
		output = false;
	}
}

void UButton::draw(sf::RenderWindow& window, float zoomLevel) {

	sf::Vector2f vecBckup1 = mainShape.getSize();
	outlineShape.setSize(sf::Vector2f(outlineShape.getSize().x * zoomLevel, outlineShape.getSize().y * zoomLevel));
	window.draw(outlineShape);
	outlineShape.setSize(vecBckup1);

	sf::Vector2f vecBckup2 = mainShape.getSize();
	mainShape.setSize(sf::Vector2f((mainShape.getSize().x - outlinethickness * 2) * zoomLevel, (mainShape.getSize().y - outlinethickness * 2) * zoomLevel));
	window.draw(mainShape);
	mainShape.setSize(vecBckup2);

	window.draw(text);

}

void UButton::setPosition(sf::Vector2i pos_) {
	localPos = pos_;
}

void UButton::setSize(sf::Vector2f size_) {
	size = size_;
}

sf::Vector2f UButton::getSize() {
	return size;
}

sf::Vector2i UButton::getPosition() {
	return localPos;
}

sf::Vector2f UButton::getGlobalPosition() {
	return globalPos;
}

void UButton::disable(bool value) {
	isDisabled = value;
}

bool UButton::getDisabled() {
	return isDisabled;
}

void UButton::setOutlineThickness(int value) {
	outlinethickness = value;
}

void UButton::setMainColor(sf::Color color) {
	mainColor = color;
}

void UButton::setMainDisabledColor(sf::Color color) {
	mainDisabledColor = color;
}

void UButton::setOutlineColor(sf::Color color) {
	outlineColor = color;
}

void UButton::setOutlineOverColor(sf::Color color) {
	outlineOverColor = color;
}

void UButton::setOutlinePressedColor(sf::Color color) {
	outlinePressedColor = color;
}

void UButton::setFont(std::string str) {
	if(!fnt.loadFromFile(str)) {
		return;
	}
	text.setFont(fnt);
}

void UButton::setTextColor(sf::Color color) {
	text.setColor(color);
}

bool UButton::onMouseOver() {
	return isOver;
}

bool UButton::onOutput() {
	return output;
}