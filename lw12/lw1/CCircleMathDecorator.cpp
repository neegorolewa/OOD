#include "CCircleMAthDecorator.h"
#include "CCircle.h"
#define _USE_MATH_DEFINES
#include <math.h>

bool CCircleMathDecorator::ContainsPoint(const sf::Vector2f& point) const
{
    return std::dynamic_pointer_cast<CCircle>(m_shape)->ContainsPoint(point);
}

void CCircleMathDecorator::Draw(sf::RenderWindow& window) const
{
    m_shape->Draw(window);
}

void CCircleMathDecorator::DrawSelection(sf::RenderWindow& window) const
{
    m_shape->DrawSelection(window);
}

void CCircleMathDecorator::SetSelected(bool selected)
{
    m_shape->SetSelected(selected);
}

bool CCircleMathDecorator::IsSelected() const
{
    return m_shape->IsSelected();
}

void CCircleMathDecorator::Move(const sf::Vector2f& offset)
{
    m_shape->Move(offset);
}

double CCircleMathDecorator::CalculatePerimeter() const
{
    double radius = std::dynamic_pointer_cast<CCircle>(m_shape)->GetRadius();
    return 2 * M_PI * radius;
}

double CCircleMathDecorator::CalculateArea() const
{
    double radius = std::dynamic_pointer_cast<CCircle>(m_shape)->GetRadius();
    return M_PI * radius * radius;
}
