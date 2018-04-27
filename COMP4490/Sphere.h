#pragma once
#include "Vec3.h"
#include "Ray.h"
#include "Shape.h"
#include "Vecmath.h"
#include <stdio.h>

class Sphere : public Shape{
	Vec3 origin, colour;
	float radius, kMat, sMat, t;
	int numPoints, latLines, longLines;
	Vec3 * points;
	Vec3 * texVals;
public:
	Sphere(Vec3, Vec3, float, float, float);
	Vec3 getNormal(Vec3);
	float getT();
	Vec3 getColour();
	float getKMat();
	void getPoints();
	bool checkPoints(int, int);
	float getSMat();
	bool intersect(Ray);
};