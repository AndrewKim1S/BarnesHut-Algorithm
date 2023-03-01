#include "simulation.h"


simulation::simulation() {
		window = new sf::RenderWindow(sf::VideoMode(1500, 900), "Barnes Hut Algorithm");
		window->setPosition(sf::Vector2i(200, 75));

		width = 1500;
		height = 900;

		generateObjects();

}

simulation::~simulation() {
		delete window;
}

void simulation::render() {
		window->clear(sf::Color(32, 32, 32));
		for(object o : objects) {
				window->draw(o.getShape());
		}
		window->display();
}

void simulation::run() {
		pollEvents();
		update();
		render();
}

void simulation::pollEvents() {
		while(window->pollEvent(event)) {
				switch(event.type) {
						case sf::Event::Closed:
								window->close();
								break;
						default:
								break;
				}
		}
}

void simulation::update() {

}

bool simulation::isRunning() {
		return window->isOpen();
}

void simulation::generateObjects() {
		for(int i = 0; i < numObjects; i++) {
				sf::Vector2f position;
				position.x = rand() % static_cast<int>(width);
				position.y = rand() % static_cast<int>(height);
				objects.emplace_back(object(position));
		}
}
