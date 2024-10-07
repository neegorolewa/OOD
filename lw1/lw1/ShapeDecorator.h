#pragma once
#include "IShape.h"
class ShapeDecorator : public IShape
{
	 ShapeDecorator(std::shared_ptr<IShape> shape, sf::Color fillColor)
        : m_shape(shape)
        , m_fillColor(fillColor)
    {}

    double GetArea() const override
    {
        return m_shape->GetArea();
    }

    double GetPerimeter() const override
    {
        return m_shape->GetPerimeter();
    }

    std::string ToString() const override
    {
        return m_shape->ToString();
    }

    void Draw(sf::RenderWindow& window) override
    {
        m_shape->Draw(window);
    }

    sf::Color GetFillColor() const
    {
        return m_fillColor;
    }

protected:
    std::shared_ptr<IShape> m_shape;
    sf::Color m_fillColor = sf::Color::Blue;
};

