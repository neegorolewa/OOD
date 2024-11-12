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

	bool ContainsPoint(const sf::Vector2f& point) const override;

	void DrawSelection(sf::RenderWindow& window) const override;

	void SetSelected(bool selected) override;

	bool IsSelected() const override;

	void Move(const sf::Vector2f& offset) override;

	CPoint GetCenter() const;

	double GetRadius() const;

	std::string ToString() const override;

	void Draw(sf::RenderWindow& window) const  override;


private:
	CPoint m_center;

	double m_radius;

	bool m_selected = false;
};

