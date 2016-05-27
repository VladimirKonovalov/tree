#include "stdio.h"
#include "stdlib.h"
#include <iostream>
//---------
typedef struct tr {
	int val;
	tr *l, *r, *par;
} tree, *ptree;

//---------
ptree root; //root
			//---------

ptree create(ptree root, ptree p, int value) {
	if (!p) {
		p = new tree;
		p->l = NULL;
		p->r = NULL;
		p->par = NULL;
		p->val = value;
		if (!root) return p;
		if (value < root->val) {
			root->l = p; p->par = root;
		}
		else {
			root->r = p; p->par = root;
		}

		return p;
	}
	if (value < p->val) create(p, p->l, value);
	else create(p, p->r, value);

	return root;
}
//----------
void print(int deep, ptree p) {
	if (p) {
		print(deep + 1, p->l);
		for (int i = 0; i < deep; i++) {
			printf("  ");
		}
		printf(">%d", p->val);
		printf("\n");
		print(deep + 1, p->r);
	}
}
void del(ptree p) {
	if ((p->l) && (p->r)) {
		del(p->l);
		del(p->r);
		delete p;
	}
	else if (p->l) {
		del(p->l);
		delete p;
	}
	else if (p->r) {
		del(p->r);
		delete p;
	}
	else if (!(p->l) && !(p->r)) delete p;
}
ptree search(int x, ptree p) {
	ptree temp = NULL;
	if (x == p->val) return p;
	else if (x < p->val) temp = search(x, p->l);
	else if (x > p->val) temp = search(x, p->r);
	return temp;
}
ptree findmin(ptree p) {
	if (p->l) findmin(p->l);
	else return p;
}
void removeroot(ptree p);
void remove(int x, ptree p) {
	if (p == NULL)
		return;/*-----------------------------*/
	if ((p->val == x) && (p->par == NULL)) {
		removeroot(p);
		/*-------------------------------------------------*/
	}
	else if (x < p->val)
		remove(x, p->l);
	else if (x > p->val)
		remove(x, p->r);
	else {                              // случай 1
		if ((p->l == NULL) && (p->r == NULL)) {
			if (p->par->r == p)	p->par->r = NULL;
			else p->par->l = NULL;
			delete p;
		}
		else if (p->l == NULL) {
			ptree old = p;
			if (p->par->r == p) { p->par->r = old->r; old->r->par = p->par; }
			else { p->par->l = old->r; old->l->par = p->par; }
			delete old;
		}
		else if (p->r == NULL) {     // случай 2
			ptree old = p;
			if (p->par->r == p) { p->par->r = old->l; old->l->par = p->par; }
			else { p->par->l = old->l; old->l->par = p->par; }
			delete old;
		}
		else {	                          // случай 3
			ptree m = findmin(p->r);
			p->val = m->val;
			remove(m->val, p->r);
		}
	}
}
void removeroot(ptree p) {
	if (p == NULL) return;
	if ((p->l == NULL) && (p->r == NULL)) delete p;
	else if (p->l == NULL) {
		p->val = p->r->val;
		remove(p->r->val, p->r);
	}
	else if (p->r == NULL) {
		p->val = p->l->val;
		remove(p->l->val, p->l);
	}
	else {
		ptree m = findmin(p->r);
		p->val = m->val;
		remove(m->val, m);
	}
}
//-----------
void main() {
	int length = 7;
	int* mas;
	mas = new int[length];
	//for (int i = 0; i < length; i++)
		//mas[i] = rand();
	//mas[0] = 20000;
	/*mas[0] = 8;
	mas[1] = 10;
	mas[2] = 5;
	mas[3] = 11;
	mas[4] = 9;
	mas[5] = 6;
	mas[6] = 3;
	mas[7] = 7;
	mas[8] = 4;
	mas[9] = 2;
	mas[10] = 12;
	mas[11] = 1;*/
	mas[0] = 7;
	mas[1] = 8;
	mas[2] = 3;
	mas[3] = 9;
	mas[4] = 5;
	mas[5] = 2;
	mas[6] = 4;
	for (int i = 0;i<length;i++) root = create(root, root, mas[i]);
	print(0, root);

//	del(root);
//	if (root) print(0, root);
//	std::cout << findmin(root)->val;//search(1, root)->val << std::endl;
	std::cout << std::endl;
	remove(8, root);
	print(0, root);
	std::cout << std::endl;std::cout << std::endl;std::cout << std::endl;
	remove(5, root);
	print(0, root);
	std::cout << std::endl;std::cout << std::endl;std::cout << std::endl;
	remove(9, root);
	print(0, root);
	std::cout << std::endl;std::cout << std::endl;std::cout << std::endl;
	remove(3, root);
	print(0, root);
	std::cout << std::endl;std::cout << std::endl;std::cout << std::endl;
	remove(7, root);
	print(0, root);
}
