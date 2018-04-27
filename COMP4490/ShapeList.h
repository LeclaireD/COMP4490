#pragma once
#include "Shape.h"
#include <stdio.h>
class ShapeList {
	Shape* shapes[10];
	int currPos = 0;
public:
	ShapeList();
	void shapeAdd(Shape*);
	Shape* getShape(int);
	int getSize();
	bool checkPoints(int, int);
	void getPoints();

};