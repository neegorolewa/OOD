#include "CRectangle.h"

const std::string CRectangle::NAME = "RECTANGLE";

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

double CRectangle::GetArea() const
{
    return GetWidth() * GetHeight();
}

double CRectangle::GetPerimeter() const
{
    return 2 * (GetWidth() + GetHeight());
}

void CRectangle::Draw(sf::RenderWindow& window)
{
    sf::RectangleShape rectangle;

    rectangle.setSize(sf::Vector2f(GetWidth(), GetHeight()));

    rectangle.setPosition(m_leftTop.m_x, m_leftTop.m_y);

    rectangle.setFillColor(sf::Color::Black);

    window.draw(rectangle);
}
