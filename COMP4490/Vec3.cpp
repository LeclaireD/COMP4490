#include "Vec3.h"
#include <cmath>

Vec3::Vec3() {
	x = y = z = 0.0;
}
Vec3::Vec3(float x, float y, float z) {
	this->x = x;
	this->y = y;
	this->z = z;
}
Vec3 Vec3::normalize() {
	float norm = sqrt((x*x) + (y*y) + (z*z));
	return Vec3(x / norm, y / norm, z / norm);
}

float Vec3::getX() { return x; }
float Vec3::getY() { return y; }
float Vec3::getZ() { return z; }
Vec3 Vec3::operator + (Vec3 v) { return Vec3(x + v.getX(), y + v.getY(), z + v.getZ()); }
Vec3 Vec3::operator - (Vec3 v) { return Vec3(x - v.getX(), y - v.getY(), z - v.getZ()); }
Vec3 Vec3::operator * (float d) { return Vec3(x*d, y*d, z*d); }
Vec3 Vec3::operator / (float d) { return Vec3(x / d, y / d, z / d); }