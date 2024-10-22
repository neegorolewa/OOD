#pragma once
#include "IShape.h"
#include "CPoint.h"

class CCircle : public IShape
{
public:

	static const std::string NAME;

	CCircle(CPoint center, double radius)
		:m_center(center)
		,m_radius(radius)
	{}

	/*double GetArea() const override;

	double GetPerimeter() const override;*/

	CPoint GetCenter() const;

	double GetRadius() const;

	std::string ToString() const override;

	void Draw(sf::RenderWindow& window) const  override;


private:
	CPoint m_center;

	double m_radius;
};

