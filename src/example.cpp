#include <stdio.h>
#include <cmath>
#include "a1main.h"
#include "Sphere.h"
#include "Vec3.h"
#include "Vecmath.h"
#include "Ray.h"
#include "ShapeList.h"
#include "PointLight.h"
#include "LightList.h"
#include "DirectionalLight.h"

float MAX = 255;

void trace(char *input_file, void *window, int width, int height) {

	Shape* shape = new Sphere(Vec3(250, 250, 0), Vec3(255,0,0), 100, 0.90,0.90);
	Shape* shape2 = new Sphere(Vec3(450, 250, 0), Vec3(0, 255, 0), 50, 0.75, 0.75);
	ShapeList shapes = ShapeList();
	shapes.shapeAdd(shape);
	shapes.shapeAdd(shape2);

	Light* light = new PointLight(Vec3(0, 0, 200), Vec3(1, 1, 1), 0.2);
	Light* light2 = new PointLight(Vec3(640, 0, 90), Vec3(1, 1, 1), 0.2);
	Light* light3 = new DirectionalLight(Vec3(-1, 0, 0), Vec3(1, 1, 1), 0.5);
	LightList lights = LightList();
	lights.lightAdd(light);
	lights.lightAdd(light2);
	lights.lightAdd(light3);
	shapes.getPoints();
	for (int x = 0; x < width; x++)
		for (int y = 0; y < height; y++) {
			//Ray ray = Ray(Vec3(x, y, 0), Vec3(0, 0, -1));
			//Vec3 result = shader(ray, shapes, lights);
			if(shapes.checkPoints(x,y))
			set(window, x, y, 255, 255, 255);
		}
}

void pick(void *window, int x, int y) {
	unsigned char r, g, b;
	if (get(window, x, y, r, g, b)) {
		printf("pick @ (%d, %d): colour [%d %d %d]\n", x, y, r, g, b);
		set(window, x, y, (128+r)%256, (128+g)%256, (128+b)%256);
		redraw(window);
	}
}
