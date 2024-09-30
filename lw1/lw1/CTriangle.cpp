#include "CTriangle.h"
#include <cmath>

const std::string CTriangle::NAME = "TRIANGLE";

double CTriangle::GetSide(const CPoint& top1, const CPoint& top2) const
{
    return std::sqrt(std::pow(top1.m_x - top2.m_x, 2) + std::pow(top1.m_y - top2.m_y, 2));
}

double CTriangle::GetArea() const
{
    return 0.5 * abs(
        (m_top2.m_x - m_top1.m_x) *
        (m_top3.m_y - m_top1.m_y) -
        (m_top3.m_x - m_top1.m_x) *
        (m_top2.m_y - m_top1.m_y)
    );
}

double CTriangle::GetPerimeter() const
{
    return CTriangle::GetSide(m_top1, m_top2) + 
        CTriangle::GetSide(m_top2, m_top3) + 
        CTriangle::GetSide(m_top3, m_top1);
}

CPoint CTriangle::GetTop1() const
{
    return m_top1;
}

CPoint CTriangle::GetTop2() const
{
    return m_top2;
}

CPoint CTriangle::GetTop3() const
{
    return m_top3;
}

void CTriangle::Draw(sf::RenderWindow& window)
{
    sf::ConvexShape triangle;

    triangle.setPointCount(3);

    triangle.setPoint(0, sf::Vector2f(m_top1.m_x, m_top1.m_y));
    triangle.setPoint(1, sf::Vector2f(m_top2.m_x, m_top3.m_y));
    triangle.setPoint(2, sf::Vector2f(m_top3.m_x, m_top3.m_y));

    triangle.setFillColor(sf::Color::Green);

    window.draw(triangle);
}

