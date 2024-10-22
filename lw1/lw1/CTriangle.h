#pragma once
#include "IShape.h"
#include "CPoint.h"
class CTriangle : public IShape
{
public:

	static const std::string NAME;

	CTriangle(CPoint top1, CPoint top2, CPoint top3)
		:m_top1(top1)
		, m_top2(top2)
		, m_top3(top3)
	{}

	//double GetArea() const override;

	//double GetPerimeter() const override;

	CPoint GetTop1() const;

	CPoint GetTop2() const;

	CPoint GetTop3() const;

	std::string ToString() const override;

	void Draw(sf::RenderWindow& window) const override;

private:

	//double GetSide(const CPoint& top1, const CPoint& top2) const;

	CPoint m_top1, m_top2, m_top3;
};

