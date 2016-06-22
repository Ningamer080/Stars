#pragma once
#include <sfml/Graphics.hpp>
class Camera
{
public:
	Camera();

	//Update function. used to update the camera.
	//TODO :	Fix deltatime bug.
	//			Drag function.
	void update(sf::RenderWindow& window);

	//Used for zooming. Positive value to zoom in, Negative value to zoom out.
	void zoom(float value);

	//Used to get zoom level
	float getZoom();

	//Used to lock the movement.
	void setFocus(bool isFocused);

	//Used to lock for 0.5 second.
	void lock();

	//The lenght from the window's border, to move with mouse around the world.
	int rectLenght = 30;

private:

	// Basically, all the variables to make the camera work.
	bool hasFocus = true;

	sf::Vector2f velocity;
	float zoomvelocity;

	float zoomlevel = 2;
	float defspeed = 5.0f;
	float bstspeed = 12.0f;
	float spd = defspeed;

	sf::Clock tickTimer;
	float fps = 60;
	float deltatime;
	int deltatarget = 60;

	int maxCamSpeed;
	int camSpeed;

	sf::Clock tickTimer1;

	sf::View view;
	sf::Event evnt;
};

