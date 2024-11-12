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

	bool ContainsPoint(const sf::Vector2f& point) const override;

	void DrawSelection(sf::RenderWindow& window) const override;
	
	void SetSelected(bool selected) override;
	
	bool IsSelected() const override;
	
	void Move(const sf::Vector2f& offset) override;

	double GetWidth() const;

	double GetHeight() const;

	CPoint GetLeftTop() const;

	CPoint GetRightBottom() const;

	std::string ToString() const override;

	void Draw(sf::RenderWindow & window) const override;

private:
	CPoint m_leftTop;
	CPoint m_rightBottom;
	bool m_selected = false;
};

