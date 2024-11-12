#include "CTriangleMathDecorator.h"
#include "CPoint.h"
#include "CTriangle.h"

bool CTriangleMathDecorator::ContainsPoint(const sf::Vector2f& point) const
{
    return std::dynamic_pointer_cast<CTriangle>(m_shape)->ContainsPoint(point);
}

void CTriangleMathDecorator::Draw(sf::RenderWindow& window) const
{
    m_shape->Draw(window);
}

void CTriangleMathDecorator::DrawSelection(sf::RenderWindow& window) const
{
    m_shape->DrawSelection(window);
}

void CTriangleMathDecorator::SetSelected(bool selected)
{
    m_shape->SetSelected(selected);
}

bool CTriangleMathDecorator::IsSelected() const
{
    return m_shape->IsSelected();
}

void CTriangleMathDecorator::Move(const sf::Vector2f& offset)
{
    m_shape->Move(offset);
}

double CTriangleMathDecorator::CalculatePerimeter() const
{
    CPoint top1 = std::dynamic_pointer_cast<CTriangle>(m_shape)->GetTop1();
    CPoint top2 = std::dynamic_pointer_cast<CTriangle>(m_shape)->GetTop2();
    CPoint top3 = std::dynamic_pointer_cast<CTriangle>(m_shape)->GetTop3();

    return CTriangleMathDecorator::GetSide(top1, top2) +
        CTriangleMathDecorator::GetSide(top2, top3) +
        CTriangleMathDecorator::GetSide(top3, top1);
}

double CTriangleMathDecorator::CalculateArea() const
{
    CPoint top1 = std::dynamic_pointer_cast<CTriangle>(m_shape)->GetTop1();
    CPoint top2 = std::dynamic_pointer_cast<CTriangle>(m_shape)->GetTop2();
    CPoint top3 = std::dynamic_pointer_cast<CTriangle>(m_shape)->GetTop3();

    return 0.5 * abs(
                (top2.m_x - top1.m_x) *
                (top3.m_y - top1.m_y) -
                (top3.m_x - top1.m_x) *
                (top2.m_y - top1.m_y)
            );
}

double CTriangleMathDecorator::GetSide(const CPoint& top1, const CPoint& top2) const
{
    return std::sqrt(std::pow(top1.m_x - top2.m_x, 2) + std::pow(top1.m_y - top2.m_y, 2));
}
