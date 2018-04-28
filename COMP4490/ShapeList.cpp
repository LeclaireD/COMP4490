#include "ShapeList.h"

ShapeList::ShapeList() {
	allPoints = new Vec3[100000];
}
void ShapeList::shapeAdd(Shape *shape) {
		shapes[currPos] = shape;
		currPos++;
}
int ShapeList::getSize() { return currPos;}
Shape* ShapeList::getShape(int i) {return shapes[i];}
int ShapeList::getTotalPoints() { return pointCount; }

Vec3 * ShapeList::getPoints() {
	Vec3 * list;
	for (int i = 0; i < currPos; i++) {
		list = shapes[i]->getPoints();
		for (int j = 0; j < shapes[i]->totalPoints(); j++) {
			allPoints[pointCount] = list[j];
			pointCount++;
		}
	}
	return allPoints;
}
bool ShapeList::checkPoints(int x, int y) {
	for (int i = 0; i < currPos; i++) {
		if (shapes[i]->checkPoints(x, y)) {
			return true;
		}
	}
	return false;
}

