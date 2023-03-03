#include <vector>
#include "quadtree.h"
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#define numObjects 50

class simulation {

		public:
				simulation();
				~simulation();
				void render();
				void run();
				void pollEvents();
				void update();
				bool isRunning();
				void generateObjects();

		private:
				sf::RenderWindow* window;
				sf::Event event;

				int width;
				int height;

				std::vector<object> objects;
				quadtree root;
};
