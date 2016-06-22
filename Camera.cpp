#include "Camera.h"
#include <iostream>

//Constructor
Camera::Camera()
{
	deltatime = 1;
}

//Update function. used to update the camera.
void Camera::update(sf::RenderWindow& window) {

	//TODO :	Fix deltatime bug.
	//			Drag function.

	//View vars.
	view = window.getView();
	view.setSize((sf::Vector2f) window.getSize());

	//Deltatime.
	fps = 1.0f / tickTimer.restart().asSeconds();
	deltatime = (deltatime * 0.9f) + (0.1f * (1.0f / (fps / deltatarget)));
	
	//We dont want to move camera, while the game is in background.
	if (hasFocus) {

		//Speed Boost.
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
			spd = bstspeed;
		}
		else {
			spd = defspeed;
		}

		//Zooming.
		zoomlevel += zoomvelocity * deltatime;
		zoomvelocity -= zoomvelocity * 0.1 * deltatime;
		if (zoomlevel < 0.4f) {
			zoomlevel = 0.4f;
			zoomvelocity = 0;
			view.zoom(0.4f);
		}
		else if (zoomlevel > 3.0f) {
			zoomlevel = 3.0f;
			zoomvelocity = 0;
			view.zoom(3.0f);
		}
		else {
			view.zoom(zoomlevel);
		}

		if (tickTimer1.getElapsedTime().asSeconds() > 0.5) {
			//LEFT
			if (sf::Mouse::getPosition(window).x < rectLenght || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
				velocity += sf::Vector2f(-spd * zoomlevel * deltatime / 10, 0.0f);
			}
			//RIGHT
			if (sf::Mouse::getPosition(window).x > window.getSize().x - rectLenght || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
				velocity += sf::Vector2f(spd * zoomlevel * deltatime / 10, 0.0f);
			}
			//UP
			if (sf::Mouse::getPosition(window).y < rectLenght || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
				velocity += sf::Vector2f(0, -spd * zoomlevel * deltatime / 10);
			}
			//DOWN
			if (sf::Mouse::getPosition(window).y > window.getSize().y - rectLenght || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
				velocity += sf::Vector2f(0, spd * zoomlevel * deltatime / 10);
			}
		}
	}

	//Velocity Drag.
	velocity -= sf::Vector2f(velocity.x * 0.1 * deltatime, velocity.y * 0.1 * deltatime);
	
	//Returning back view vars.
	view.move(velocity);
	window.setView(view);
}

//Used for zooming. Positive value to zoom in, Negative value to zoom out.
void Camera::zoom(float value) {
	zoomvelocity += value;
}

//Used to lock the movement.
void Camera::setFocus(bool isFocused) {
	hasFocus = isFocused;
}

//Used to lock for 0.5 second.
void Camera::lock() {
	tickTimer1.restart();
}

//Used to get zoom level
float Camera::getZoom() {
	return zoomlevel;
}