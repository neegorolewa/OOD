#include "ShapeCreator.h"

std::shared_ptr<IShape> ShapeCreator::CreateShape(const std::string& line)
{
	std::istringstream input(line);
	std::string nameShape;
	input >> nameShape;

	if (nameShape == CRectangle::NAME)
	{
		return ShapeCreator::CreateRectangle(input);
	}
	else if (nameShape == CTriangle::NAME)
	{
		return ShapeCreator::CreateTriangle(input);
	}
	else if (nameShape == CCircle::NAME)
	{
		return ShapeCreator::CreateCircle(input);
	}

	return nullptr;
}

std::shared_ptr<CRectangle> ShapeCreator::CreateRectangle(std::istringstream& input)
{
	double leftTopX, leftTopY, rightBottomX, rightBottomY;
	input >> leftTopX >> leftTopY >> rightBottomX >> rightBottomY;
	
	CPoint leftTop = { leftTopX, leftTopY };
	CPoint rightBottom = { rightBottomX, rightBottomY };

	return std::make_shared<CRectangle>(leftTop, rightBottom);
}

std::shared_ptr<CTriangle> ShapeCreator::CreateTriangle(std::istringstream& input)
{
	double top1X, top1Y;
	double top2X, top2Y;
	double top3X, top3Y;

	input >> top1X >> top1Y >>
		top2X >> top2Y >>
		top3X >> top3Y;

	CPoint top1 = { top1X, top1Y };
	CPoint top2 = { top2X, top2Y };
	CPoint top3 = { top3X, top3Y };

	return std::make_shared<CTriangle>(top1, top2, top3);
}

std::shared_ptr<CCircle> ShapeCreator::CreateCircle(std::istringstream& input)
{
	double centerX, centerY, radius;

	input >> centerX >> centerY >> radius;

	CPoint center = { centerX, centerY };

	return std::make_shared<CCircle>(center, radius);
}
