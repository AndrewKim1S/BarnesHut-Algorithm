#include "object.h"


object::object() {}

object::object(sf::Vector2f pos) {
		position = pos;
		radius = 7;
		shape = sf::CircleShape();
		shape.setRadius(radius);
		shape.setPosition(pos.x - radius, pos.y - radius);
		shape.setFillColor(sf::Color::White);
}

object::~object() {}

sf::CircleShape object::getShape() {
		return shape;
}

sf::Vector2f object::getPosition() {
		return position;
}
