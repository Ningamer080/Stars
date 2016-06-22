#include "UCanvas.h"


UCanvas::UCanvas() : canvasSize(1920, 1080) { }

void UCanvas::update(sf::RenderWindow& window, float zoomLevel) {
	for (int i = 0; i < buttons.size(); i++) {
		if (!buttons[i].freezed == false) {
			buttons[i].globalPos = window.mapPixelToCoords((sf::Vector2i) buttons[i].localPos);
			buttons[i].update(window, zoomLevel);
		}
	}
	for (int i = 0; i < texts.size(); i++) {
		if (!texts[i].freezed == false) {
			texts[i].update(window, zoomLevel);
		}
	}
}

void UCanvas::draw(sf::RenderWindow& window, float zoomLevel) {
	for (int i = 0; i < buttons.size(); i++) {
		if (!buttons[i].freezed == false) {
			buttons[i].draw(window, zoomLevel);
		}
	}
	for (int i = 0; i < texts.size(); i++) {
		if (!texts[i].freezed == false) {
			texts[i].draw(window);
		}
	}
}

UButton& UCanvas::createButton(int id) {
	UButton button;
	button.ID = id;
	buttons.push_back(button);
	return buttons[buttons.size() - 1];
}

UButton* UCanvas::getButton(int id) {
	for (int i = 0; i < buttons.size() - 1; i++) {
		if (buttons[i].ID == id) {
			return &buttons[i];
		}
	}
	return NULL;
}

UText& UCanvas::createText(int id) {
	UText text;
	text.ID = id;
	texts.push_back(text);
	return texts[texts.size() - 1];
}

UText* UCanvas::getText(int id) {
	for (int i = 0; i < texts.size() - 1; i++) {
		if (texts[i].ID == id) {
			return &texts[i];
		}
	}
	return NULL;
}