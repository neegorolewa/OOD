#pragma once
#include <vector>
#include <memory>
#include "ShapeCreator.h"

class ShapeControl
{
public:

	void ConstructShape(const std::string& line);

	void DrawShapes();

private:
	const int WIDTH_WINDOW = 1000;
	const int HEIGHT_WINDOW = 1000;
	const std::string NAME_WINDOW = "window";

	std::vector<std::shared_ptr<IShape>> m_shapes = {};
};

