#pragma once
#include <vector>
#include <memory>
#include <iostream>
#include "ShapeCreator.h"

class ShapeControl
{
public:

	//void ConstructShape(const std::string& line);

	void PrintInfo(const std::string& fileName);

	void DrawShapes();

	void ReadInfo(const std::string& fileName);

private:
	const int WIDTH_WINDOW = 1000;
	const int HEIGHT_WINDOW = 1000;
	const std::string NAME_WINDOW = "window";

	std::vector<std::shared_ptr<IShape>> m_shapes = {};

	std::shared_ptr<IShape> ConstructShape(const std::string& line);
};

