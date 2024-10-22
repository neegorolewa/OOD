#pragma once
#include <memory>
#include <string>
#include "IShape.h"
#include "CRectangle.h"
#include "CTriangle.h"
#include "CCircle.h"
class ShapeCreator
{
public:

	static std::shared_ptr<IShape> CreateShape(const std::string& line);

private:

	static std::shared_ptr<CRectangle> CreateRectangle(std::string& info);

	static std::shared_ptr<CTriangle> CreateTriangle(std::string& info);

	static std::shared_ptr<CCircle> CreateCircle(std::string& info);

};

