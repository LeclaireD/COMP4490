#pragma once
#include "Vec3.h"

class treeNode{
	treeNode * left;
	treeNode * right;
	char split; //x,y, or z plane
	int index;
	Vec3 * bounds[2];

public:
	treeNode(char split, int index, Vec3 * bounds);
	void addChild(treeNode * node, char LR);
	char getSplit();
	Vec3* getBounds();
};