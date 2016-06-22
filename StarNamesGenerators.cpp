#include "StarNamesGenerators.h"
#include <stdlib.h>
#include <time.h>

StarNamesGenerators::StarNamesGenerators()
{
}

std::string StarNamesGenerators::RandomName() {
	std::string name;
	for (int x = 0; x < 3; x++) {
		//std::srand(time(NULL));
		name += firstLineChars[std::rand() % 8];
	}
	name += '-';
	for (int x = 0; x < 3; x++) {
		//std::srand(time(NULL));
		name += secondLineChars[std::rand() % 10];
	}
	return name;
}
