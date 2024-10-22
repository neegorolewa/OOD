#pragma once
#include "ShapeDecorator.h"
#include "CPoint.h"

class CTriangleMathDecorator : public ShapeDecorator
{
public:
	CTriangleMathDecorator(std::shared_ptr<IShape> shape)
		: ShapeDecorator(std::move(shape))
	{
		SetArea();
		SetPerimeter();
	}

protected:
	double CalculatePerimeter() const override;
	double CalculateArea() const override;

private:
	double GetSide(const CPoint& top1, const CPoint& top2) const;
};

