#pragma once
#include <string>
#include "Star.h"
class Generators
{
public:
	Generators();
	std::string StarName(std::string galaxyName);
	std::string PlanetName(std::string galaxyName, std::string starName);
};

