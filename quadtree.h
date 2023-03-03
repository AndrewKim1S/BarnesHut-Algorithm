#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "object.h"


#define MaxLevel 5
#define MaxObjs 3

class quadtree{

		public:
				quadtree();
				quadtree(sf::RectangleShape rect, int level);
				~quadtree();

				void insert(object& o);
				void clear();


		private:
				sf::RectangleShape rectangle;
				
				int level;
				
				quadtree* topLeft;
				quadtree* topRight;
				quadtree* botLeft;
				quadtree* botRight;

				// Perhaps change to vector
				object obj;
				// std::vector<object*> objs;
};
