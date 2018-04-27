#pragma once
class Vec3 {
public:
	float x, y, z;
	Vec3();
	Vec3(float x, float y, float z);
	Vec3 normalize();
	float getX();
	float getY();
	float getZ();
	Vec3 operator + (Vec3 v);
	Vec3 operator - (Vec3 v);
	Vec3 operator * (float d);
	Vec3 operator / (float d);

};