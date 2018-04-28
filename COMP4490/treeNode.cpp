#include "treeNode.h"

treeNode::treeNode() {
	split = 0;
	index = 0;
	bounds[0] = new Vec3();
	bounds[1] = new Vec3();
}
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
void treeNode::setSplit(double split) { this->split = split;}
Vec3* treeNode::getBounds() {return *bounds;}
void treeNode::setIndex(int idx) { index = idx; }
treeNode* treeNode::getLeft() { return left; }
treeNode* treeNode::getRight() { return right; }
int treeNode::getIndex() { return index; }
bool treeNode::isLeaf() { 
	if (left == NULL && right == NULL){ 
		return true; 
	} 
	return false; 
}