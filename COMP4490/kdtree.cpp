#include "kdtree.h"

enum DIMENSIONS { DIM_X = 0, DIM_Y, DIM_Z, NDIMS };


kdtree::kdtree() {}

treeNode * kdtree::getRoot() { return root; }

void kdtree::prepare(Vec3 * list, int count) {
	/* initialise values and memory */
	currNodes = count;
	maxSize = ((count - 1) * 2) + 1;
	points = new Vec3[maxSize];
	pointData = new treeNode[maxSize];
	assert(this->points != NULL);
	assert(this->pointData != NULL);

	// store all points in the tree
	for (int i = 0; i < count; i++) {
		this->points[i] = list[i];
	}

	// actually build tree
	printf("%d\n",count);
	this->root = build(0, count - 1, 0);

}


#define CMP(v1,v2) ((v1 > v2) ? 1 : ((v1 < v2) ? -1 : 0))

static int cmp_x(const void *a1, const void *a2) {
	const Vec3 *A1 = (const Vec3*)a1;
	const Vec3 *A2 = (const Vec3*)a2;
	return CMP(A1->x, A2->x);
}

static int cmp_y(const void *a1, const void *a2) {
	const Vec3 *A1 = (const Vec3*)a1;
	const Vec3 *A2 = (const Vec3*)a2;
	return CMP(A1->y, A2->y);
}

static int cmp_z(const void *a1, const void *a2) {
	const Vec3 *A1 = (const Vec3*)a1;
	const Vec3 *A2 = (const Vec3*)a2;
	return CMP(A1->z, A2->z);
}

/* datatype for cmp function pointer */
typedef int(*cmp_func)(const void *, const void *);

/* static array of cmp functions indexed by dim */
const cmp_func func[] = { cmp_x, cmp_y, cmp_z };

treeNode* kdtree::build(int start, int end,
	int depth) {
	double split;
	treeNode * node;
	Vec3 point;
	const int count = end - start + 1;
	const int mid = start + ((end - start) / 2);
	const int axis = depth % NDIMS;
	//printf("start: %d, end: %d, depth: %d\n", start, end, depth);
	// if there is only one point, return a leaf node *
	if (count == 1) return getLeaf(start);

	/* sort the points within this group to determine the median point
	* - This can be a potential performance bottleneck. There are methods
	*   to determine median in linear time, but that can get rather
	*   complicated. Will consider if this proves to be an issue.
	*/
	qsort((void*)(this->points + start), count,
		sizeof(Vec3), func[axis]);

	/* determine point where axis will be split */
	point = this->points[mid];
	//printf("x: %f y: %f z: %f\n", point.x, point.y, point.z);
	split = (axis == 0) ? point.x : ((axis == 1) ? point.y : point.z);
	/* recursively build a tree for the left and right planes */
	node = getBranch(split);
	node->addChild(build(start, mid, depth + 1), 'L');
	node->addChild(build(mid + 1, end, depth + 1), 'R');

	return node;
}

treeNode * kdtree::getBranch(double split) {
	treeNode * node = nextNode();
	node->setSplit(split);
	return node;
}

treeNode * kdtree::getLeaf(int offset) {
	treeNode * node = nextNode();
	node->addChild(NULL, 'R');
	node->addChild(NULL, 'L');
	node->setIndex(offset);
	return node;
}

treeNode * kdtree::nextNode() {
	assert(this->currPos < this->maxSize);
	return &this->pointData[this->currPos++];
}
void kdtree::printTree(treeNode * node) {
	if (node == NULL) {
		return;
	}
		printf("%d\n",node->getIndex());

		printTree(node->getLeft());
		printTree(node->getRight());

}