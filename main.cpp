#include "Shape.hpp"
#include "Circle.hpp"
#include "Rectangle.hpp"
#include <string>
#include <iostream>


int main() {
	Circle* circle = new Circle();
	Rectangle* rectangle = new Rectangle();
	circle->setRadius(3.0);
	rectangle->setLength(4.2);
	rectangle->setWidth(5.1);

	Shape* pShape = circle;

	std::string json = "{\"type\":\"Circle\",\"radius\":5.1}";
	std::cout << json << "\n";
	pShape = Shape::fromJson(json);
	pShape->print();
	std::cout << "\n";
	std::cout << pShape->toJson() << "\n";
	
	json = "{\"type\":\"Rectangle\",\"length\":4.2\",\"width\":3.3}";
	std::cout << json << "\n";
	pShape = Shape::fromJson(json);
	pShape->print();
	std::cout << "\n";
	std::cout << pShape->toJson() << "\n";

	delete circle;
	delete rectangle;
	delete pShape;

	return 0;
}