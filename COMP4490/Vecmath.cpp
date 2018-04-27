#include "Vecmath.h"



float AMBIENTLIGHT = 0.4;
Vec3 AMBIENT = Vec3(AMBIENTLIGHT,AMBIENTLIGHT,AMBIENTLIGHT);
int ALPHA = 64;

float dotProd(Vec3 a, Vec3 b) {
	return ((a.getX() * b.getX()) + (a.getY() * b.getY()) + (a.getZ() * b.getZ()));
}
Vec3 crossProd(Vec3 a, Vec3 b) {
	return Vec3((a.getY()*b.getZ())- (a.getZ()*b.getY()), (a.getZ()*b.getX()) - (a.getX()*b.getZ()), (a.getX()*b.getY()) - (a.getY()*b.getX()));
}
float min(float a, float b) {
	if (a < b) {
		return a;
	}
	else {
		return b;
	}
}
Vec3 vecMult(Vec3 a, Vec3 b) {
	return Vec3(a.getX() * b.getX(), a.getY() * b.getY(), a.getZ() * b.getZ());
}

float getDiffuse(Ray ray, Light* light, Shape* shape) {
	float dot;
	Vec3 P = (ray.getA() + (ray.getB()*shape->getT()));
	Vec3 N = (shape->getNormal(P));
	if (light->hasLoc()) {
		dot = dotProd(N, (light->getLoc() - P).normalize());
	}
	else {
		dot = dotProd(N, (light->getDir() ).normalize());
	}
	if (dot < 0) {
		dot = 0;
	}
	float ld = (shape->getKMat()*dot);
	return ld;
}
float getSpec(Ray ray, Light* light, Shape* shape) {
	Vec3 P = (ray.getA() + (ray.getB()*shape->getT()));
	Vec3 N = (shape->getNormal(P));
	Vec3 L = Vec3();
	if (light->hasLoc()) {
		L = (N, (light->getLoc() - P).normalize());
	}
	Vec3 R = (N - L)*(2 * (dotProd(N, L)));
	Vec3 V = (ray.getB()).normalize();
	float cos = dotProd(R, V);
	float result = pow(cos, ALPHA);

	if (result < 0) {
		result = 0;
	}
	return result;
}
Vec3 shader(Ray ray, ShapeList shapes, LightList lights) {
	for (int i = 0; i < shapes.getSize(); i++) {
		
			if (shapes.getShape(i)->intersect(ray)) {
				Vec3 colour = shapes.getShape(i)->getColour();
				Vec3 total = Vec3();
				for (int j = 0; j < lights.getSize(); j++) {
					Vec3 lColour = lights.getLight(j)->getColour();
					float diffuse = getDiffuse(ray, lights.getLight(j), shapes.getShape(i));
					float spec = getSpec(ray, lights.getLight(j), shapes.getShape(i));
					float DS = (diffuse + spec)*lights.getLight(j)->getIntensity();
					Vec3 difSpec = Vec3(DS*lColour.getX(), DS*lColour.getY(), DS*lColour.getZ());
					total = total + difSpec;
					
				}
				Vec3 light = AMBIENT + total;
				colour = vecMult(light,colour);
				return colour;

		}
	}
	return Vec3(0,0,200);
}