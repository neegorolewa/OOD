#pragma once
#include "IShape.h"
#include "CPoint.h"

class CRectangle : public IShape
{
public:

	static const std::string NAME;

	CRectangle(CPoint leftTop, CPoint rightBottom)
		:m_leftTop(leftTop)
		, m_rightBottom(rightBottom)
	{}

	double GetArea() const override;

	double GetPerimeter() const override;

	double GetWidth() const;

	double GetHeight() const;

	CPoint GetLeftTop() const;

	CPoint GetRightBottom() const;

	void Draw(sf::RenderWindow & window) override;

private:
	CPoint m_leftTop;
	CPoint m_rightBottom;
};

