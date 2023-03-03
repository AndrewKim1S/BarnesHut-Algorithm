#include "quadtree.h"


quadtree::quadtree() {
		rectangle.setPosition(0, 0);
		rectangle.setSize(sf::Vector2f(1500.f, 900.f));
		topLeft = NULL;
		topRight = NULL;
		botLeft = NULL;
		botRight = NULL;
		object obj = object();
		level = 0;
}

quadtree::quadtree(sf::RectangleShape rect, int l) {
		rectangle = rect;
		rectangle.setOutlineThickness(4);
		rectangle.setOutlineColor(sf::Color::White);
		topLeft = NULL;
		topRight = NULL;
		botLeft = NULL;
		botRight = NULL;
		object obj = object();
		level = l;
}

quadtree::~quadtree() {
		delete topLeft;
		delete topRight;
		delete botLeft;
		delete botRight;
}

void quadtree::insert(object& o) {

		// Check that object is within the quadtree node area
		if(o.getPosition().x <= rectangle.getPosition().x ||
				o.getPosition().x >= rectangle.getPosition().x + rectangle.getSize().x ||
				o.getPosition().y <= rectangle.getPosition().y ||
				o.getPosition().y >= rectangle.getPosition().y + rectangle.getSize().y) {
				return;
		}

		// Check that quadtree node can be split
		if(level >= MaxLevel) {
				obj = o;
				return;
		}

		float verticalMid = rectangle.getSize().x/2 + rectangle.getPosition().x;
		float horizontalMid = rectangle.getSize().y/2 + rectangle.getPosition().y;

		std::cout << "test" << std::endl;
		// object is left side
		if(verticalMid >= o.getPosition().x) {
				// object is top left
				if(horizontalMid >= o.getPosition().y) {
						if(topLeft == NULL) {
								sf::RectangleShape r = sf::RectangleShape();
								r.setSize(sf::Vector2f(rectangle.getSize().x/2, rectangle.getSize().y/2));
								r.setPosition(rectangle.getPosition());
								topLeft = new quadtree(r, level+1);
						}
						topLeft->insert(o);
				} 
				// object is bot left
				else {
						if(botLeft == NULL) {
								sf::RectangleShape r = sf::RectangleShape();
								r.setSize(sf::Vector2f(rectangle.getSize().x/2, rectangle.getSize().y/2));
								r.setPosition(rectangle.getPosition().x, rectangle.getPosition().y + 
										rectangle.getSize().y/2);
								botLeft = new quadtree(r, level+1);
						}
						botLeft->insert(o);
				}
		} 

		// object is right side
		else {
				// object is top right
				if(horizontalMid >= o.getPosition().y) {
						if(topRight == NULL) {
								sf::RectangleShape r = sf::RectangleShape();
								r.setSize(sf::Vector2f(rectangle.getSize().x/2, rectangle.getSize().y/2));
								r.setPosition(rectangle.getPosition().x +	rectangle.getSize().x/2, 
										rectangle.getPosition().y);
								topRight = new quadtree(r, level+1);
						}
						topRight->insert(o);
				}
				// object is bot right
				else {
						if(botRight == NULL) {
								sf::RectangleShape r = sf::RectangleShape();
								r.setSize(sf::Vector2f(rectangle.getSize().x/2, rectangle.getSize().y/2));
								r.setPosition(rectangle.getPosition().x + rectangle.getSize().x/2,
										rectangle.getPosition().y + rectangle.getSize().y/2);
								botRight = new quadtree(r, level+1);
						}
						botRight->insert(o);
				}
		}
}

/*
quadtree::quadtree() {}

quadtree::quadtree(int level, sf::RectangleShape rect) {
		this->level = level;
		rectangle = rect;
		topLeft = new quadtree();
		topRight = new quadtree();
		botLeft = new quadtree();
		botRight = new quadtree();
}

quadtree::~quadtree() {
		delete topLeft;
		delete topRight;
		delete botLeft;
		delete botRight;
}

void quadtree::clear() {
		obj.clear();
		topLeft->clear();
		topLeft = NULL;
		topRight->clear();
		topRight = NULL;
		botLeft->clear();
		botLeft = NULL;
		botRight->clear();
		botRight = NULL;
}

void quadtree::split() {
		float subWidth = static_cast<float> (rectangle.getSize().x / 2);
		float subHeight = static_cast<float> (rectangle.getSize().y / 2);
		float x = static_cast<float> (rectangle.getPosition().x);
		float y = static_cast<float> (rectangle.getPosition().y);
		sf::Vector2f size = sf::Vector2f(subWidth, subHeight);
		
		sf::RectangleShape topLeftShape = sf::RectangleShape();
		topLeftShape.setSize(size);
		topLeftShape.setPosition(x, y);
		topLeft = new quadtree(level + 1, topLeftShape);

		sf::RectangleShape topRightShape = sf::RectangleShape();
		topRightShape.setSize(size);
		topRightShape.setPosition(x + subWidth, y);
		topRight = new quadtree(level + 1, topRightShape);

		sf::RectangleShape botLeftShape = sf::RectangleShape();
		botLeftShape.setSize(size);
		botLeftShape.setPosition(x, y+ subHeight);
		botLeft = new quadtree(level + 1, botLeftShape);

		sf::RectangleShape botRightShape = sf::RectangleShape();
		botRightShape.setSize(size);
		botRightShape.setPosition(x + subWidth, y + subHeight);
		botRight = new quadtree(level + 1, botRightShape);
}

void quadtree::insert(object o) {
		sf::Vector2f pos = o.getPosition();
		
		float boundVerticalMid = rectangle.getPosition().x + (rectangle.getSize().x / 2);
		float boundHorizontalMid = rectangle.getPosition().y + (rectangle.getSize().y / 2);

		float objXPos = pos.x;
		float objYPos = pos.y;

		// If object is in the top half of the quadrant
		bool topQuad = objYPos < boundHorizontalMid;

		if(topQuad) {
				if(objXPos < boundVerticalMid) {
						// object is top right

				}	else {
						// object is top left
				
				}
		} else {
				if(objXPos < boundVerticalMid) {
						// object is bottom right
				
				} else {
						// object is bottom left

				}
		}
}
*/
