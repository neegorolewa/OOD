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

	bool ContainsPoint(const sf::Vector2f& point) const override;
	
	void DrawSelection(sf::RenderWindow& window) const override;
	
	void SetSelected(bool selected) override;
	
	bool IsSelected() const override;
	
	void Move(const sf::Vector2f& offset) override;

	CPoint GetTop1() const;

	CPoint GetTop2() const;

	CPoint GetTop3() const;

	std::string ToString() const override;

	void Draw(sf::RenderWindow& window) const override;

private:

	CPoint m_top1, m_top2, m_top3;

	bool m_selected = false;
};

