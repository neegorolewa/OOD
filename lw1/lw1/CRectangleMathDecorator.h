#pragma once
#include "ShapeDecorator.h"
class CRectangleMathDecorator: public ShapeDecorator
{
public:
	CRectangleMathDecorator(std::shared_ptr<IShape> shape)
		: ShapeDecorator(std::move(shape))
	{
		SetArea();
		SetPerimeter();
	}

protected:
	double CalculatePerimeter() const override;
	double CalculateArea() const override;
	
};

