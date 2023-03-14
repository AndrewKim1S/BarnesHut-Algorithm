#include "object.h"


object::object() {}

object::object(sf::Vector2f pos) {
		position = pos;
		radius = 3;
		shape = sf::CircleShape();
		shape.setRadius(radius);
		shape.setPosition(pos.x - radius, pos.y - radius);
		shape.setFillColor(sf::Color(0, 204, 102));
		movement.x = rand() % static_cast<int>(6);
		movement.y = rand() % static_cast<int>(6);
		int negative = rand() % static_cast<int>(4);
		if(negative == 2) {
				movement.x = -movement.x;
		} else if(negative == 3) {
				movement.y = -movement.y;
		} else if(negative == 4) {
				movement.x = -movement.x;
				movement.y = -movement.y;
		}
}

object::~object() {}

void object::render(sf::RenderTarget* target) {
		target->draw(shape);
}

sf::CircleShape object::getShape() {
		return shape;
}

sf::Vector2f object::getPosition() {
		return position;
}

sf::Vector2f object::getMovement() {
		return movement;
}

void object::updatePosition() {
		//position.x = 10;
		//position.y = 10;
		
		if(position.x <= 0 || position.x >= xBoundary) {
				movement.x *= -1;
		}
		if(position.y <= 0 || position.y >= yBoundary) {
				movement.y *= -1;
		}

		position.x = position.x + movement.x;
		position.y = position.y + movement.y;
		
		shape.setPosition(position);
}
