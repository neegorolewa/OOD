#pragma once
#include <vector>
#include <memory>
#include <iostream>
#include "ShapeCreator.h"

class ShapeControl
{
public:

	void ConstructShape(const std::string& line, sf::Color fillColor);

	void ToString() const;

	void DrawShapes();

private:
	const int WIDTH_WINDOW = 1000;
	const int HEIGHT_WINDOW = 1000;
	const std::string NAME_WINDOW = "window";

	std::vector<std::shared_ptr<IShape>> m_shapes = {};
};

