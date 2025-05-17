#include "Circle.hpp"
#include "Constants.hpp"
#include <iostream>

std::string Circle::toJson() const {
	std::string result = "{\"type\":\"" + Constants::CIRCLE_NAME + "\"," + Constants::RADIUS + doubleWithoutExtraZeroes(radius) + "}";
	return result;
}
void Circle::print() const {
	std::cout << "Circle, radius: " << radius;
}