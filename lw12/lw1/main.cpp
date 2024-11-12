#include <iostream>
#include "CPoint.h"
#include "CRectangle.h"
#include "CCircle.h"
#include "CTriangle.h"
#include "ShapeControl.h"

int main()
{
	ShapeControl shapeController;

	shapeController.ReadInfo("input.txt");
	shapeController.DrawShapes();
	shapeController.PrintInfo("output.txt");

	return 0;
}
