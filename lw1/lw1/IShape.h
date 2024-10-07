#pragma once
#include <cstdint>
#include <sstream>
#include <string>
#include <iomanip>
#include "SFML/Graphics.hpp"

class IShape
{
public:

	virtual ~IShape() {}

	virtual double GetArea() const = 0;

	virtual double GetPerimeter() const = 0;

	virtual std::string ToString() const
	{
		std::stringstream output;
		output << "Area: " << GetArea() << std::endl;
		output << "Perimeter: " << GetPerimeter() << std::endl;

		return output.str();
	}

	virtual void Draw(sf::RenderWindow& window) = 0;
};