#include "Ray.h"
Ray::Ray(Vec3 a, Vec3 b) {
	this->a = a;
	this->b = b;
	t = 0;
}
Vec3 Ray::getA() { return a; }
Vec3 Ray::getB() { return b; }
float Ray::getT() { return t; }
void Ray::setT(float t) { this->t = t; }
