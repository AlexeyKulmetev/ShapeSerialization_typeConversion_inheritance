#pragma once
#include "Shape.hpp"


class Rectangle : public Shape {
public:
	void setLength(const double _length) {
		length = _length;
	}
	void setWidth(const double _width) {
		width = _width;
	}
	std::string toJson() const override;

	void print() const override;

private:
	double length = 0.0;
	double width = 0.0;
};