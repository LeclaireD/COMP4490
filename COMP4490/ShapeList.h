#pragma once
#include "Shape.h"
#include <stdio.h>
class ShapeList {
	Shape* shapes[10];
	int currPos = 0, pointCount = 0;
	Vec3 * allPoints;
public:
	ShapeList();
	void shapeAdd(Shape*);
	Shape* getShape(int);
	int getSize();
	bool checkPoints(int, int);
	int getTotalPoints();
	Vec3 * getPoints();

};