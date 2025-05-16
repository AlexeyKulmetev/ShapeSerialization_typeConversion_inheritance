#pragma once
#include <string>



class Shape {
public:
	virtual ~Shape() = default;

	virtual std::string toJson() const = 0;

	// need static since Shape entity cant be instantiate
	// constructors can`t be virtual
	static Shape* fromJson(const std::string& _jsonStr);

	virtual void print() const = 0;
};