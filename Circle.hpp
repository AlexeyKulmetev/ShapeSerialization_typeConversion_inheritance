#pragma once
#include "Shape.hpp"



class Circle : public Shape {
public:
	void setRadius(const double _radius) {
		radius = _radius;
	}
	std::string toJson() const override;

	void print() const override;

private:
	double radius = 0.0;
};