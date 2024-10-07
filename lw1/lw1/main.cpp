#include <iostream>
#include "CPoint.h"
#include "CRectangle.h"
#include "CCircle.h"
#include "CTriangle.h"
#include "ShapeControl.h"

int main()
{
	ShapeControl shapeController;

	std::string rect = "RECTANGLE 100 100 200 200";
	std::string circle = "CIRCLE 300 400 20";
	std::string trian = "TRIANGLE 100 100 200 200 300 300";


	shapeController.ConstructShape(rect, sf::Color::Black);
	shapeController.ConstructShape(circle, sf::Color::Blue);
	shapeController.ConstructShape(trian, sf::Color::Green);

	shapeController.DrawShapes();

	shapeController.ToString();

}
