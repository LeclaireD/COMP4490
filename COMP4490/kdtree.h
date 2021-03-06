#pragma once
#include "Vec3.h"
#include "treeNode.h"
#include "assert.h"
#include <stdlib.h>
#include <stdio.h>
class kdtree {
	int maxSize, currNodes, currPos = 0;

	treeNode * pointData;
	treeNode * root;
	Vec3 * points;
public:

	kdtree();
	void prepare(Vec3 * points, int count);
	treeNode * build(int startIdx, int endIdx, int depth);
	treeNode * getBranch(double split);
	treeNode * getLeaf(int index);
	void printTree(treeNode * node);
	treeNode * nextNode();
	treeNode * getRoot();
};

/* control value to indicate the end of iteration 

struct data_point {
	float x;
	float y;
	float z;
	size_t idx;  //index of original data point
};

				struct tree_node {
				struct tree_node *left;
				struct tree_node *right;
				float split;
				size_t idx;
				};

				struct boundaries {
				float min;
				float max;
				};

				struct space {
				struct boundaries dim[3];
				};
				*/

	

	/*typedef struct {
	size_t count;
	size_t max_nodes;
	size_t next_node;
	struct data_point *points;
	struct tree_node *node_data;
	struct tree_node *root;
	} kdtree;


	void kdtree_build(float *x, float *y, float *z, size_t count, kdtree **tree);
	void kdtree_delete(kdtree **tree_ptr);
	void kdtree_search(kdtree *tree,,
	float x, float y, float z, float apothem);
	void kdtree_search_space(kdtree *tree,
	float x_min, float x_max,
	float y_min, float y_max,
	float z_min, float z_max);
	size_t kdtree_iterator_get_next(kdtree_iterator *iter);
	void kdtree_iterator_rewind(kdtree_iterator *iter);
	void kdtree_iterator_sort(kdtree_iterator *iter);
	void kdtree_iterator_delete(kdtree_iterator **iter_ptr);*/



