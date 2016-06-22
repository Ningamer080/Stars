#ifndef UELEMENT_H
#define UELEMENT_H
#include <SFML\Graphics.hpp>
#include <iostream>
class UElement
{
public:
	enum LockPoint
	{
		TopLeft,
		TopRight,
		BottomRight,
		BottomLeft,
		Middle,
	};

	LockPoint lockPoint;

	UElement();
	int ID;
	sf::Vector2f globalPos;
	sf::Vector2i localPos;

	//Wont be drawn or updated when freezed
	bool freezed = false;
};
#endif