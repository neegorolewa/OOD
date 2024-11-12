#include "ShapeDecorator.h"

double ShapeDecorator::GetArea() const
{
	return m_area;
}

double ShapeDecorator::GetPerimeter() const
{
	return m_perimeter;
}

std::string ShapeDecorator::ToString() const
{
	std::ostringstream oss;
	oss << m_shape->ToString() << " P=" << GetPerimeter() << " S=" << GetArea();
	return oss.str();
}

void ShapeDecorator::Draw(sf::RenderWindow& window) const
{
	m_shape->Draw(window);
}

bool ShapeDecorator::ContainsPoint(const sf::Vector2f& point) const
{
	return m_shape->ContainsPoint(point);
}

void ShapeDecorator::DrawSelection(sf::RenderWindow& window) const
{
	m_shape->DrawSelection(window);
}

void ShapeDecorator::SetSelected(bool selected)
{
	m_shape->SetSelected(selected);
}

bool ShapeDecorator::IsSelected() const
{
	return m_shape->IsSelected();
}

void ShapeDecorator::Move(const sf::Vector2f& offset)
{
	m_shape->Move(offset);
}

void ShapeDecorator::SetPerimeter()
{
	m_perimeter = CalculatePerimeter();
}

void ShapeDecorator::SetArea()
{
	m_area = CalculateArea();
}
