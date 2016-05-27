#include "tree.h"

tree::tree() {
	root = NULL;
}
tree::~tree() {

}
site* tree::insert(site* _root, site* _site) {            // x Ч корень поддерева, z Ч вставл€емый ключ
	if (_root == NULL)
		_root = _site;                       // подвесим Node с key = z
	else if (_site->key < root->key)
		root->left = insert(_root->left, _site);
	else if (_site->key > root->key)
		_root->right = insert(_root->right, _site);
	return NULL;
}
void tree::write(site* _site) {
	if (_site != NULL) {
		write(_site->left);
		std::cout << _site->key << " ";
		write(_site->right);
	}
}