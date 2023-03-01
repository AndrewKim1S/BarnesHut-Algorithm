#include "simulation.h"


simulation::simulation() {
		window = new sf::RenderWindow();
}

simulation::~simulation() {
		delete window;
}

void simulation::render() {
		
}

void simulation::run() {

}

void simulation::pollEvents() {

}

void simulation::update() {

}

bool simulation::isRunning() {
		return window->isOpen();
}
