#include <iostream>
#include <SFML/Graphics.hpp>

#define xBoundary 1500
#define yBoundary 900

class object{

		public:
				object();
				object(sf::Vector2f pos);
				~object();
				void render(sf::RenderTarget* target);
				sf::CircleShape getShape();
				sf::Vector2f getPosition();
				sf::Vector2f getMovement();
				void updatePosition();

		private:
				sf::CircleShape shape;
				sf::Vector2f position;
				sf::Vector2f movement;
				int radius;
};
