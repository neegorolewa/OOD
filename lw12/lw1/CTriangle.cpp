#include "CTriangle.h"
#include <cmath>

const std::string CTriangle::NAME = "TRIANGLE";

bool CTriangle::ContainsPoint(const sf::Vector2f& point) const
{
    double d1 = (m_top2.m_x - m_top1.m_x) * (point.y - m_top1.m_y) - (m_top2.m_y - m_top1.m_y) * (point.x - m_top1.m_x);
    double d2 = (m_top3.m_x - m_top2.m_x) * (point.y - m_top2.m_y) - (m_top3.m_y - m_top2.m_y) * (point.x - m_top2.m_x);
    double d3 = (m_top1.m_x - m_top3.m_x) * (point.y - m_top3.m_y) - (m_top1.m_y - m_top3.m_y) * (point.x - m_top3.m_x);

    bool has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
    bool has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

    return !(has_neg && has_pos);
}

void CTriangle::DrawSelection(sf::RenderWindow& window) const
{
    sf::ConvexShape triangle;
    triangle.setPointCount(3);
    triangle.setPoint(0, sf::Vector2f(m_top1.m_x, m_top1.m_y));
    triangle.setPoint(1, sf::Vector2f(m_top2.m_x, m_top2.m_y));
    triangle.setPoint(2, sf::Vector2f(m_top3.m_x, m_top3.m_y));
    triangle.setFillColor(sf::Color::Transparent);
    triangle.setOutlineColor(sf::Color::Red);
    triangle.setOutlineThickness(2);
    window.draw(triangle);
}

void CTriangle::SetSelected(bool selected)
{
    m_selected = selected;
}

bool CTriangle::IsSelected() const
{
    return m_selected;
}

void CTriangle::Move(const sf::Vector2f& offset)
{
    m_top1.m_x += offset.x;
    m_top1.m_y += offset.y;
    m_top2.m_x += offset.x;
    m_top2.m_y += offset.y;
    m_top3.m_x += offset.x;
    m_top3.m_y += offset.y;
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

std::string CTriangle::ToString() const
{
    return NAME;
}

void CTriangle::Draw(sf::RenderWindow& window) const
{
    sf::ConvexShape triangle;

    triangle.setPointCount(3);

    triangle.setPoint(0, sf::Vector2f(m_top1.m_x, m_top1.m_y));
    triangle.setPoint(1, sf::Vector2f(m_top2.m_x, m_top2.m_y));
    triangle.setPoint(2, sf::Vector2f(m_top3.m_x, m_top3.m_y));

    triangle.setFillColor(sf::Color::Green);

    window.draw(triangle);
}

