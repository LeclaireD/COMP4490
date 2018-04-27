#pragma once
#include "Vec3.h"
#include "Ray.h"

class Shape {

public:
	Vec3 origin;
	virtual bool intersect(Ray) = 0;
	virtual float getT() = 0;
	virtual Vec3 getColour() = 0;
	virtual float getKMat() = 0;
	virtual float getSMat() = 0;
	virtual Vec3 getNormal(Vec3) = 0;
	virtual void getPoints() = 0;
	virtual bool checkPoints(int, int) = 0;
};