#pragma once
#include "ShapeDecorator.h"
class CCircleMathDecorator : public ShapeDecorator
{
public:
	CCircleMathDecorator(std::shared_ptr<IShape>&& shape)
		: ShapeDecorator(std::move(shape))
	{
		SetArea();
		SetPerimeter();
	}
protected:
	double CalculatePerimeter() const override;
	double CalculateArea() const override;
};

