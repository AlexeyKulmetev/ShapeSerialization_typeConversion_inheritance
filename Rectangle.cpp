#include "Rectangle.hpp"
#include "Constants.hpp"
#include <iostream>


std::string Rectangle::toJson() const {
	std::string result = "{\"type\":\"" + Constants::RECTANGLE_NAME + "\"," + Constants::LENGTH +
		std::to_string(length) + "\"," + Constants::WIDTH + std::to_string(width) + "}";
	return result;
}

void Rectangle::print() const {
	std::cout << "Rectangle, length: " << length << " width: " << width;
}