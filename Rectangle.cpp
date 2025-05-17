#include "Rectangle.hpp"
#include "Constants.hpp"
#include <iostream>


std::string Rectangle::toJson() const {
	std::string result = "{\"type\":\"" + Constants::RECTANGLE_NAME + "\"," + Constants::LENGTH +
		doubleWithoutExtraZeroes(length) + "\"," + Constants::WIDTH + doubleWithoutExtraZeroes(width) + "}";
	return result;
}

void Rectangle::print() const {
	std::cout << "Rectangle, length: " << length << " width: " << width;
}