#pragma once
#include <iostream>
#include <string>
class StarNamesGenerators
{
public:
	StarNamesGenerators();
	std::string RandomName();
private:
	std::string generatedNames[800];
	std::string firstLineChars = "ABCDEFGH";
	std::string secondLineChars = "1234567890";
};

