#include "CRectangleMathDecorator.h"
#include "CRectangle.h"

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
