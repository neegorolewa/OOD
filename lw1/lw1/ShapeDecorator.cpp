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

void ShapeDecorator::SetPerimeter()
{
	m_perimeter = CalculatePerimeter();
}

void ShapeDecorator::SetArea()
{
	m_area = CalculateArea();
}
