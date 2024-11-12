#pragma once
#include "CCircleMathDecorator.h"
#include "CRectangleMathDecorator.h"
#include "CShapeComposite.h"
#include "CTriangleMathDecorator.h"
#include "fstream"
#include "regex"
#include "ShapeControl.h"
#include "ShapeCreator.h"
#include "ShapeDecorator.h"
#include <iostream>
#include <iostream>
#include <memory>
#include <vector>

class ShapeControl
{
public:

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

