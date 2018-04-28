#include "Sphere.h"
#include <math.h>

float PI = 3.141592654f;
Sphere::Sphere(Vec3 origin, Vec3 colour, float radius, float kmat, float smat) {
	this->colour = colour;
	this->origin = origin;
	this->radius = radius;
	latLines = 40;
	longLines = 40;
	this->kMat = kmat;
	this->sMat = smat;
	t = 0;
}

Vec3 Sphere::getColour() { return colour; }
float Sphere::getKMat() { return kMat; }
float Sphere::getSMat() { return sMat; }
float Sphere::getT() { return t; }
Vec3 Sphere::getNormal(Vec3 n){ return (n - origin) / radius; }
int Sphere::totalPoints() { return numPoints; }

Vec3 * Sphere::getPoints() {
	// One vertex at every latitude-longitude intersection,
	// plus one for the north pole and one for the south.
	// One meridian serves as a UV seam, so we float the vertices there.
	numPoints = latLines * (longLines + 1) + 2;

	points = new Vec3[numPoints];
	texVals = new Vec3[numPoints];

		// North pole.
	points[0] = Vec3(0, radius, 0) + origin;

		// South pole.
	points[numPoints - 1] = Vec3(0, -radius, 0) + origin;

		// +1.0f because there's a gap between the poles and the first parallel.
	float latitudeSpacing = 1.0f / (latLines + 1.0f);
	float longitudeSpacing = 1.0f / (longLines);

		// start writing new vertices at position 1
	int v = 1;
	for (int latitude = 0; latitude < latLines; latitude++) {
			for (int longitude = 0; longitude <= longLines; longitude++) {

				// Scale coordinates into the 0...1 texture coordinate range,
				// with north at the top (y = 1).
				texVals[v] = Vec3(longitude * longitudeSpacing, 1.0f - (latitude + 1) * latitudeSpacing, 0) + origin;

					// Convert to spherical coordinates:
					// theta is a longitude angle (around the equator) in radians.
					// phi is a latitude angle (north or south of the equator).
				float theta = (texVals[v].x * 2.0f) * PI;
				float phi = (texVals[v].y - 0.5f) * PI;

					// This determines the radius of the ring of this line of latitude.
					// It's widest at the equator, and narrows as phi increases/decreases.
				double c = cos(phi);

					// Usual formula for a vector in spherical coordinates.
					// You can exchange x & z to wind the opposite way around the sphere.
				points[v] = Vec3(c * cos(theta), sin(phi), c * sin(theta)) * radius + origin;

					// Proceed to the next vertex.
					v++;
			}
		}
	return points;
}


bool Sphere::checkPoints(int x, int y) {

	for (int i = 0; i < numPoints; i++) {
		if ((int)points[i].x == x && (int)points[i].y == y) {
			return true;
		}
	}
	return false;
}

bool Sphere::intersect(Ray ray) { 
	bool show = true;
	float disc;
	float t;
	float t2;
	Vec3 e = ray.getA();
	Vec3 d = ray.getB();
	disc = (((dotProd(d, (e - origin))*dotProd(d, (e - origin))) - (dotProd(d, d)))*(dotProd((e - origin), (e - origin)) - (radius*radius)));
	if (disc < 0) {
		show = false;
	}
	else if (disc == 0) {
		t = ((dotProd(Vec3()-d, (e - origin))) / dotProd(d, d));
		ray.setT(t);
	}
	else{
		disc = sqrt(disc);
		t = (((dotProd(Vec3() - d, (e - origin))) -disc) / dotProd(d, d));
		t2 = (((dotProd(Vec3() - d, (e - origin))) + disc) / dotProd(d, d));
		if (t < t2) {
			this->t = t;
		}
		else if (t2 < t){
			this->t = t2;
		}
	}
	return show;
}
