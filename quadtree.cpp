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
		rectangle.setFillColor(sf::Color::Black);
		rectangle.setOutlineThickness(2);
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


		// Test, may have to remove
		if(topLeft == NULL) {
				sf::RectangleShape r = sf::RectangleShape();
				r.setSize(sf::Vector2f(rectangle.getSize().x/2, rectangle.getSize().y/2));
				r.setPosition(rectangle.getPosition());
				topLeft = new quadtree(r, level+1);
		} if(botLeft == NULL) {
				sf::RectangleShape r = sf::RectangleShape();
				r.setSize(sf::Vector2f(rectangle.getSize().x/2, rectangle.getSize().y/2));
				r.setPosition(rectangle.getPosition().x, rectangle.getPosition().y + 
						rectangle.getSize().y/2);
				botLeft = new quadtree(r, level+1);
		} if(topRight == NULL) {
				sf::RectangleShape r = sf::RectangleShape();
				r.setSize(sf::Vector2f(rectangle.getSize().x/2, rectangle.getSize().y/2));
				r.setPosition(rectangle.getPosition().x +	rectangle.getSize().x/2, 
						rectangle.getPosition().y);
				topRight = new quadtree(r, level+1);
		}
		if(botRight == NULL) {
				sf::RectangleShape r = sf::RectangleShape();
				r.setSize(sf::Vector2f(rectangle.getSize().x/2, rectangle.getSize().y/2));
				r.setPosition(rectangle.getPosition().x + rectangle.getSize().x/2,
						rectangle.getPosition().y + rectangle.getSize().y/2);
				botRight = new quadtree(r, level+1);
		}


		// object is left side
		if(verticalMid >= o.getPosition().x) {
				// object is top left
				if(horizontalMid >= o.getPosition().y) {
						/*if(topLeft == NULL) {
								sf::RectangleShape r = sf::RectangleShape();
								r.setSize(sf::Vector2f(rectangle.getSize().x/2, rectangle.getSize().y/2));
								r.setPosition(rectangle.getPosition());
								topLeft = new quadtree(r, level+1);
						}*/
						topLeft->insert(o);
				} 
				// object is bot left
				else {
						/*if(botLeft == NULL) {
								sf::RectangleShape r = sf::RectangleShape();
								r.setSize(sf::Vector2f(rectangle.getSize().x/2, rectangle.getSize().y/2));
								r.setPosition(rectangle.getPosition().x, rectangle.getPosition().y + 
										rectangle.getSize().y/2);
								botLeft = new quadtree(r, level+1);
						} */ 
						botLeft->insert(o);
				}
		} 

		// object is right side
		else {
				// object is top right
				if(horizontalMid >= o.getPosition().y) {
						/*if(topRight == NULL) {
								sf::RectangleShape r = sf::RectangleShape();
								r.setSize(sf::Vector2f(rectangle.getSize().x/2, rectangle.getSize().y/2));
								r.setPosition(rectangle.getPosition().x +	rectangle.getSize().x/2, 
										rectangle.getPosition().y);
								topRight = new quadtree(r, level+1);
						}*/
						topRight->insert(o);
				}
				// object is bot right
				else {
						/*if(botRight == NULL) {
								sf::RectangleShape r = sf::RectangleShape();
								r.setSize(sf::Vector2f(rectangle.getSize().x/2, rectangle.getSize().y/2));
								r.setPosition(rectangle.getPosition().x + rectangle.getSize().x/2,
										rectangle.getPosition().y + rectangle.getSize().y/2);
								botRight = new quadtree(r, level+1);
						}*/
						botRight->insert(o);
				}
		}
}

void quadtree::render(sf::RenderTarget* target) {
		target->draw(rectangle);
		if(topLeft != NULL) {
				topLeft->render(target);
		}
		if(botLeft != NULL) {
				botLeft->render(target);
		}
		if(topRight != NULL) {
				topRight->render(target);
		}
		if(botRight != NULL) {
				botRight->render(target);
		}
}

