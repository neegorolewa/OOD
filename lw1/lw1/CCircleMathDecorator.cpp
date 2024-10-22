#include "CCircleMAthDecorator.h"
#include "CCircle.h"
#define _USE_MATH_DEFINES
#include <math.h>

double CCircleMathDecorator::CalculatePerimeter() const
{
    double radius = std::dynamic_pointer_cast<CCircle>(m_shape)->GetRadius();
    return 2 * M_PI * radius;
}

double CCircleMathDecorator::CalculateArea() const
{
    double radius = std::dynamic_pointer_cast<CCircle>(m_shape)->GetRadius();
    return M_PI * radius * radius;
}
