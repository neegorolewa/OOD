#include "CRectangleMathDecorator.h"
#include "CRectangle.h"

bool CRectangleMathDecorator::ContainsPoint(const sf::Vector2f& point) const
{
    return std::dynamic_pointer_cast<CRectangle>(m_shape)->ContainsPoint(point);
}

void CRectangleMathDecorator::Draw(sf::RenderWindow& window) const
{
    m_shape->Draw(window);
}

void CRectangleMathDecorator::DrawSelection(sf::RenderWindow& window) const
{
    m_shape->DrawSelection(window);
}

void CRectangleMathDecorator::SetSelected(bool selected)
{
    m_shape->SetSelected(selected);
}

bool CRectangleMathDecorator::IsSelected() const
{
    return m_shape->IsSelected();
}

void CRectangleMathDecorator::Move(const sf::Vector2f& offset)
{
    m_shape->Move(offset);
}

double CRectangleMathDecorator::CalculatePerimeter() const
{
    double width = std::dynamic_pointer_cast<CRectangle>(m_shape)->GetWidth();
    double height = std::dynamic_pointer_cast<CRectangle>(m_shape)->GetHeight();

    return 2 * (width + height);
}

double CRectangleMathDecorator::CalculateArea() const
{
    double width = std::dynamic_pointer_cast<CRectangle>(m_shape)->GetWidth();
    double height = std::dynamic_pointer_cast<CRectangle>(m_shape)->GetHeight();

    return width * height;
}
