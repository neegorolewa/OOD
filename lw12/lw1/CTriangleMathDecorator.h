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

	bool ContainsPoint(const sf::Vector2f& point) const override;
	void Draw(sf::RenderWindow& window) const override;
	void DrawSelection(sf::RenderWindow& window) const override;
	void SetSelected(bool selected) override;
	bool IsSelected() const override;
	void Move(const sf::Vector2f& offset) override;

protected:
	double CalculatePerimeter() const override;
	double CalculateArea() const override;

private:
	double GetSide(const CPoint& top1, const CPoint& top2) const;
};

