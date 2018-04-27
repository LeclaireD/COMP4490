#include "ShapeList.h"

ShapeList::ShapeList() {

}
void ShapeList::shapeAdd(Shape *shape) {
	shapes[currPos] = shape;
	currPos++;
}
int ShapeList::getSize() {
	return currPos;
}
Shape* ShapeList::getShape(int i) {
	return shapes[i];
}
void ShapeList::getPoints() {
	for (int i = 0; i < currPos; i++) {
		shapes[i]->getPoints();
	}
}
bool ShapeList::checkPoints(int x, int y) {
	for (int i = 0; i < currPos; i++) {
		if (shapes[i]->checkPoints(x, y)) {
			return true;
		}
	}
	return false;
}