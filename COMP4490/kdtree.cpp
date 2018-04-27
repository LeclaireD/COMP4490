#include "kdtree.h"

kdtree::kdtree() {
	max = 0;
	root = new treeNode(0,0,new Vec3());
	currSize = 0;
	currPos = 0;
}
kdtree::kdtree(int max, treeNode * root) {
	this->max = max;
	this->root = root;
	currPos = 0;
	currSize = 1;
}
void kdtree::build() {

}