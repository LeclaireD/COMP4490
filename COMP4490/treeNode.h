#pragma once
#include "Vec3.h"
#include <stdio.h>

class treeNode{
	treeNode * left;
	treeNode * right;
	double split; //x,y, or z plane
	int index;
	Vec3 * bounds[2];

public:
	treeNode();
	treeNode(char split, int index, Vec3 * bounds);
	void addChild(treeNode * node, char LR);
	void setSplit(double split);
	void setIndex(int idx);
	treeNode * getLeft();
	treeNode * getRight();
	Vec3* getBounds();
	int getIndex();
	bool isLeaf();
};