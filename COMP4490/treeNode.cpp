#include "treeNode.h"


treeNode::treeNode(char split, int index, Vec3 * bound) {
	this->split = split;
	this->index = index;
	this->bounds[0] = bounds[0];
	this->bounds[1] = bounds[1];
}
void treeNode::addChild(treeNode * node, char LR) {
	if (LR == 'R') {
		right = node;
	}
	else {
		left = node;
	}
}
char treeNode::getSplit() {
	return split;
}
Vec3* treeNode::getBounds() {
	return *bounds;
}