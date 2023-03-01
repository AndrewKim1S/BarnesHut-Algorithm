#include <iostream>
#include <SFML/Graphics.hpp>


class object{

		public:
				object();
				object(sf::Vector2f pos);
				~object();
				sf::CircleShape getShape();
				sf::Vector2f getPosition();

		private:
				sf::CircleShape shape;
				sf::Vector2f position;
				int radius;
};
