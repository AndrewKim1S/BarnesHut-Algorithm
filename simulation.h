#include <iostream>
#include "object.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>


class simulation {

		public:
				simulation();
				~simulation();
				void render();
				void run();
				void pollEvents();
				void update();
				bool isRunning();

		private:
				sf::RenderWindow* window;
				sf::Event event;

};
