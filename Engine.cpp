#include "Engine.h"
#include <iostream>
#include "UI.h"

//Constructor
Engine::Engine() : window(sf::VideoMode(800, 600), "Stars", sf::Style::Default) { }

void Engine::start() {
	//Frame rate limits
	window.setFramerateLimit(60);

	//Create main UI
	UI ui;

	//Calling onStart function (used to initialize things)
	onStart(window);
	ui.InitUI();

	//srand(time(NULL));

	//MAIN LOOP
	while (window.isOpen())
	{
		//Window events
		while (window.pollEvent(evnt))
		{
			//Window close button functionality
			if (evnt.type == sf::Event::Closed) {
				window.close();
			}

			//Mouse scrolling
			if (evnt.type == sf::Event::MouseWheelScrolled) {
				if (evnt.mouseWheelScroll.delta < 0.0f) {
					cam.zoom(0.05f);
				}
				else if (evnt.mouseWheelScroll.delta > 0.0f) {
					cam.zoom(-0.05f);
				}
			}

			//Focusing window
			if (evnt.type == sf::Event::LostFocus) {
				hasFocus = false;
				cam.setFocus(false);
				std::cout << hasFocus << std::endl;
			}
			if (evnt.type == sf::Event::GainedFocus) {
				hasFocus = true;
				cam.setFocus(true);
				std::cout << hasFocus << std::endl;
			}
		}

		//Closing fullscreen windows
		if (defualtStyle == false && sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			window.close();
		}

		//Window style changing
		if (hasFocus) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::F11)) {
				if (defualtStyle == true) {
					defualtStyle = false;

					//Save view position, otherwise it resets to normal position
					sf::View view = window.getView();
					sf::Vector2f lastPos = view.getCenter();

					//Goto fullscreen mode
					window.create(sf::VideoMode::getDesktopMode(), "Stars", sf::Style::Fullscreen);

					//Load last position
					view.setCenter(lastPos);
					window.setView(view);

					//set framerate limit
					window.setFramerateLimit(60);

					//lock camera for few seconds to avoid deltatime bugs
					cam.lock();
				}
				else{
					defualtStyle = true;

					//Save view position, otherwise it resets to normal position
					sf::View view = window.getView();
					sf::Vector2f lastPos = view.getCenter();

					//Goto fullscreen mode
					window.create(sf::VideoMode(800, 600), "Stars", sf::Style::Default);

					//Load last position
					view.setCenter(lastPos);
					window.setView(view);

					//set framerate limit
					window.setFramerateLimit(60);

					//lock camera for few seconds to avoid deltatime bugs
					cam.lock();
				}
			}
		}

		//Clear window
		window.clear(sf::Color(202, 32, 38));

		//Update camera every new frame
		cam.update(window);

		//Update things every new frame
		update(window);

		//Update UI
		ui.getCanvas().update(window, cam.getZoom());
		ui.getCanvas().draw(window, cam.getZoom());

		//Display things
		window.display();
	}
	//Save things before the program is closed
	OnEnd(window);
}

//OnStart function, used to initialize things
void Engine::onStart(sf::RenderWindow& window) {
	for (int x = 0; x < 20; x++) {
		stars[x].setPosition(sf::Vector2f(rand() % 3001,rand() % 3001));
		std::cout << stars[x].getPosition().x << " : " << stars[x].getPosition().y << std::endl;
	}
}

//update function, used to update things every new frame
void Engine::update(sf::RenderWindow& window) {
	for (int x = 0; x < 20; x++) {
		stars[x].draw(window);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
		if (!wasRpressed) {
			system("Cls");
			for (int x = 0; x < 20; x++) {
				stars[x].setPosition(sf::Vector2f(rand() % 3001, rand() % 3001));
				std::cout << stars[x].getPosition().x << " : " << stars[x].getPosition().y << std::endl;
			}
			for (int x = 0; x < 20; x++) {
				stars[x].getANewName();
			}
		}
		wasRpressed = true;
	}
	else {
		wasRpressed = false;
	}
}

//OnEnd function, used to save things before game is closed
void Engine::OnEnd(sf::RenderWindow& window) {

}