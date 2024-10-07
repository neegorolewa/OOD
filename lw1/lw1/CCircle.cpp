#include "CCircle.h"
#define _USE_MATH_DEFINES
#include <math.h>

const std::string CCircle::NAME = "CIRCLE";

double CCircle::GetArea() const
{
    return M_PI * m_radius * m_radius;
}

double CCircle::GetPerimeter() const
{
    return 2 * M_PI * m_radius;
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
    std::stringstream output;

    output << NAME << std::endl;
    output << IShape::ToString();

    return output.str();
}

void CCircle::Draw(sf::RenderWindow& window)
{
    sf::CircleShape circle(m_radius);

    circle.setPosition(m_center.m_x, m_center.m_y);

    circle.setFillColor(sf::Color::Blue);

    window.draw(circle);
}


