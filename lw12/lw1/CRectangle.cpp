#include "CRectangle.h"

const std::string CRectangle::NAME = "RECTANGLE";

bool CRectangle::ContainsPoint(const sf::Vector2f& point) const
{
    return point.x >= m_leftTop.m_x && 
        point.x <= m_rightBottom.m_x &&
        point.y >= m_leftTop.m_y &&
        point.y <= m_rightBottom.m_y;
}

void CRectangle::DrawSelection(sf::RenderWindow& window) const
{
    sf::RectangleShape rectangle;
    rectangle.setSize(sf::Vector2f(GetWidth() + 10, GetHeight() + 10));
    rectangle.setPosition(m_leftTop.m_x - 5, m_leftTop.m_y - 5);
    rectangle.setFillColor(sf::Color::Transparent);
    rectangle.setOutlineColor(sf::Color::Red);
    rectangle.setOutlineThickness(2);
    window.draw(rectangle);
}

void CRectangle::SetSelected(bool selected)
{
    m_selected = selected;
}

bool CRectangle::IsSelected() const
{
    return m_selected;
}

void CRectangle::Move(const sf::Vector2f& offset)
{
    m_leftTop.m_x += offset.x;
    m_leftTop.m_y += offset.y;
    m_rightBottom.m_x += offset.x;
    m_rightBottom.m_y += offset.y;
}

double CRectangle::GetWidth() const
{
    return m_rightBottom.m_x - m_leftTop.m_x;
}

double CRectangle::GetHeight() const
{
    return m_rightBottom.m_y - m_leftTop.m_y;
}

CPoint CRectangle::GetLeftTop() const
{
    return m_leftTop;
}

CPoint CRectangle::GetRightBottom() const
{
    return m_rightBottom;
}

std::string CRectangle::ToString() const
{
    return NAME;
}

void CRectangle::Draw(sf::RenderWindow& window) const
{
    sf::RectangleShape rectangle;

    rectangle.setSize(sf::Vector2f(GetWidth(), GetHeight()));

    rectangle.setPosition(m_leftTop.m_x, m_leftTop.m_y);

    rectangle.setFillColor(sf::Color::Black);

    window.draw(rectangle);
}
