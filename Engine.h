#pragma once
#include <SFML\Graphics.hpp>
#include "Star.h"
#include "Camera.h"
class Engine
{
public:
	Engine();
	void start();

private:
	Camera cam;

	sf::Event evnt;

	bool defualtStyle = true;
	bool hasFocus = true;

	sf::RenderWindow window;
	void onStart(sf::RenderWindow& window);
	void update(sf::RenderWindow& window);
	void OnEnd(sf::RenderWindow& window);

	Star stars[20];
	sf::ContextSettings settings;



	bool wasRpressed = false;
};

