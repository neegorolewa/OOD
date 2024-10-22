#include "ShapeCreator.h"
#include <regex>
#include <iostream>

std::shared_ptr<IShape> ShapeCreator::CreateShape(const std::string& line)
{
	std::regex pattern(R"(^(\w+):\s*(.*)$)");
	std::smatch matches;

	std::string nameShape, info;
	if (std::regex_search(line, matches, pattern))
	{
		nameShape = matches[1].str();
		info = matches[2].str();
	}

	if (nameShape == CRectangle::NAME)
	{
		return ShapeCreator::CreateRectangle(info);
	}
	else if (nameShape == CTriangle::NAME)
	{
		return ShapeCreator::CreateTriangle(info);
	}
	else if (nameShape == CCircle::NAME)
	{
		return ShapeCreator::CreateCircle(info);
	}

	return nullptr;
}

std::shared_ptr<CRectangle> ShapeCreator::CreateRectangle(std::string& info)
{
	double leftTopX, leftTopY, rightBottomX, rightBottomY;

	std::regex pattern(R"(^P1=(\d+),(\d+);\s*P2=(\d+),(\d+)$)");
	std::smatch matches;

	if (std::regex_search(info, matches, pattern))
	{
		leftTopX = std::stoi(matches[1].str());
		leftTopY = std::stoi(matches[2].str());
		rightBottomX = std::stoi(matches[3].str());
		rightBottomY = std::stoi(matches[4].str());
	}
	else
	{
		std::cout << "Invalid rectangle coordinates" << std::endl;
		return nullptr;
	}
	
	CPoint leftTop = { leftTopX, leftTopY };
	CPoint rightBottom = { rightBottomX, rightBottomY };

	return std::make_shared<CRectangle>(leftTop, rightBottom);
}

std::shared_ptr<CTriangle> ShapeCreator::CreateTriangle(std::string& info)
{
	double top1X, top1Y;
	double top2X, top2Y;
	double top3X, top3Y;

	std::regex pattern(R"(^P1=(\d+),(\d+);\s*P2=(\d+),(\d+);\s*P3=(\d+),(\d+)$)");
	std::smatch matches;

	if (std::regex_search(info, matches, pattern))
	{
		top1X = std::stoi(matches[1].str());
		top1Y = std::stoi(matches[2].str());
		top2X = std::stoi(matches[3].str());
		top2Y = std::stoi(matches[4].str());
		top3X = std::stoi(matches[5].str());
		top3Y = std::stoi(matches[6].str());
	}
	else
	{
		std::cout << "Invalid triangle coordinates" << std::endl;
		return nullptr;
	}

	CPoint top1 = { top1X, top1Y };
	CPoint top2 = { top2X, top2Y };
	CPoint top3 = { top3X, top3Y };

	return std::make_shared<CTriangle>(top1, top2, top3);
}

std::shared_ptr<CCircle> ShapeCreator::CreateCircle(std::string& info)
{
	double centerX, centerY, radius;

	std::regex pattern(R"(^C=(\d+),(\d+);\s*R=(\d+)$)");
	std::smatch matches;

	if (std::regex_search(info, matches, pattern))
	{
		centerX = std::stoi(matches[1].str());
		centerY = std::stoi(matches[2].str());
		radius = std::stoi(matches[3].str());
	}
	else
	{
		std::cout << "Invalid circle coordinates or sizes" << std::endl;
		return nullptr;
	}

	CPoint center = { centerX, centerY };

	return std::make_shared<CCircle>(center, radius);
}
