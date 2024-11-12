#include "CCircle.h"
#define _USE_MATH_DEFINES
#include <math.h>

const std::string CCircle::NAME = "CIRCLE";

bool CCircle::ContainsPoint(const sf::Vector2f& point) const
{
    float dx = point.x - m_center.m_x;
    float dy = point.y - m_center.m_y;

    return (dx * dx + dy * dy) <= m_radius * m_radius;
}

void CCircle::DrawSelection(sf::RenderWindow& window) const
{
    sf::CircleShape circle(m_radius + 5);
    circle.setPosition(m_center.m_x - 5, m_center.m_y - 5);
    circle.setFillColor(sf::Color::Transparent);
    circle.setOutlineColor(sf::Color::Red);
    circle.setOutlineThickness(2);
    window.draw(circle);
}

void CCircle::SetSelected(bool selected)
{
    m_selected = selected;
}

bool CCircle::IsSelected() const
{
    return m_selected;
}

void CCircle::Move(const sf::Vector2f& offset)
{
    m_center.m_x += offset.x;
    m_center.m_y += offset.y;
}

CPoint CCircle::GetCenter() const
{
    return m_center;
}

double CCircle::GetRadius() const
{
    return m_radius;
}

std::string CCircle::ToString() const
{
    return NAME;
}

void CCircle::Draw(sf::RenderWindow& window) const
{
    sf::CircleShape circle(m_radius);

    circle.setPosition(m_center.m_x, m_center.m_y);

    circle.setFillColor(sf::Color::Blue);

    window.draw(circle);
}


