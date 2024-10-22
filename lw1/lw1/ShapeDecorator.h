#pragma once
#include "IShape.h"
class ShapeDecorator : public IShape
{
public:
	 ShapeDecorator(std::shared_ptr<IShape> shape)
        : m_shape(std::move(shape))
    {}

     double GetArea() const;

     double GetPerimeter() const;

     virtual std::string ToString() const;

     void Draw(sf::RenderWindow& window) const;

protected:
    virtual double CalculatePerimeter() const = 0;
    virtual double CalculateArea() const = 0;
    void SetPerimeter();
    void SetArea();
    std::shared_ptr<IShape> m_shape;

private:
    double m_area = 0, m_perimeter = 0;
};

