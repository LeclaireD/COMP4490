#pragma once
#include "Vec3.h"
#include "Ray.h"
#include "ShapeList.h"
#include "PointLight.h"
#include "Shape.h"
#include "LightList.h"
#include "Light.h"
#include "math.h"

float dotProd(Vec3, Vec3);
Vec3 shader(Ray, ShapeList, LightList);
float getDiffuse(Ray, Light*, Shape*);
Vec3 vecMult(Vec3, Vec3);
float getSpec(Ray, Light*, Shape*);
float min(float, float);
Vec3 crossProd(Vec3, Vec3);