#pragma once

#include <iostream>

struct site {
	int key;
	site* left;
	site* right;
};

class tree {
public:
	site* root;
	tree();
	~tree();
	site* insert(site* _root, site* _site);
	void write(site* _site);
};