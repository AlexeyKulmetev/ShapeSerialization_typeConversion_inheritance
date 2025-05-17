#include "Shape.hpp"
#include "Constants.hpp"
#include "Circle.hpp"
#include "Rectangle.hpp"


std::string Shape::doubleWithoutExtraZeroes(double d) const {
	std::string result = std::to_string(d);
	result.erase(result.find_last_not_of('0') + 1, std::string::npos);
	if (result.back() == '.') {
		result.pop_back();
	}
	return result;
}

Shape* Shape::fromJson(const std::string& _jsonStr) {
	
	if (_jsonStr.find(Constants::TYPE_CIRCLE) != std::string::npos) {
		Circle* circle = new Circle;

		// find where radius starts in json
		size_t radiusInd = _jsonStr.find(Constants::RADIUS);

		// find where raduis value starts in json
		size_t firstRadiusValueInd = _jsonStr.find_first_not_of(" \t:", radiusInd + Constants::RADIUS.length());
		
		// find where radius value ends in json
		size_t lastRadiusValueInd = _jsonStr.find_first_not_of("+-0123456789.eE", firstRadiusValueInd);

		// create double with radius value from the required part of the string
		double tmpRadius = std::stod(_jsonStr.substr(firstRadiusValueInd, lastRadiusValueInd - firstRadiusValueInd));

		// set radius in Circle object
		circle->setRadius(tmpRadius);

		return circle;
	}
	if (_jsonStr.find(Constants::TYPE_RECTANGLE) != std::string::npos) {
		Rectangle* rectangle = new Rectangle;

		// find where length starts in json
		size_t lengthInd = _jsonStr.find(Constants::LENGTH);

		// find where length value starts in json
		size_t firstLengthValueInd = _jsonStr.find_first_not_of(" \t:", lengthInd + Constants::LENGTH.length());

		// find where length value ends in json
		size_t lastLengthValueInd = _jsonStr.find_first_not_of("+-0123456789.eE", firstLengthValueInd);

		// create double with length value from the required part of the string
		double tmpLength = std::stod(_jsonStr.substr(firstLengthValueInd, lastLengthValueInd - firstLengthValueInd));

		// set length in Rectangle object
		rectangle->setLength(tmpLength);
		
		// ------------------------------------------------------------------
		// start searching width not from length`s end in 
		// order to make the functionality more flexible
		// in case of changing the sequence of data entry into the json-file
		// ------------------------------------------------------------------

		// find where width starts in json
		size_t widthInd = _jsonStr.find(Constants::WIDTH);

		// find where width value starts in json
		size_t firstWidthValueInd = _jsonStr.find_first_not_of(" \t:", widthInd + Constants::WIDTH.length());

		// find where width value ends in json
		size_t lastWidhtValueInd = _jsonStr.find_first_not_of("+-0123456789.eE", firstWidthValueInd);

		// create double with width value from the required part of the string
		double tmpWidth = std::stod(_jsonStr.substr(firstWidthValueInd, lastWidhtValueInd - firstWidthValueInd));

		// set width in Rectangle object
		rectangle->setWidth(tmpWidth);
		
		return rectangle;
	}
	return nullptr;
}
