#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "object.h"


#define MaxLevel 6
#define MaxObjs 3

class quadtree{

		public:
				quadtree();
				quadtree(sf::RectangleShape rect, int level);
				~quadtree();

				void insert(object& o);
				void clear();
				void render(sf::RenderTarget* target);


		private:
				sf::RectangleShape rectangle;
				
				int level;
				
				quadtree* topLeft;
				quadtree* topRight;
				quadtree* botLeft;
				quadtree* botRight;

				std::vector<object> objs;
};
