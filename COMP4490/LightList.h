#pragma once
#include "Light.h"
class LightList {
	Light* lights[10];
	int currPos = 0;
public:
	LightList();
	void lightAdd(Light*);
	Light* getLight(int);
	int getSize();
};