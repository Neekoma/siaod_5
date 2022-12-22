#include"tree.h"

Tree::Tree() {}
Tree::Tree(int k, Bank b)
{
	_root = new Node(k, b);
}

Node* Tree::insert(Node* n, int k, Bank b)
{
	if (!_root) {
		_root = new Node(k, b);
		return _root;
	}

	if (!n) return new Node(k, b);

	if (rand() % (n->size + 1) == 0)
		return insertRoot(n, k, b);

	if (n->key > k)
		n->left = insert(n->left, k, b);

	else
		n->right = insert(n->right, k, b);

	fixSize(n);
	return n;
}

Node* Tree::get(Node* n, int k)
{
	if (!n) return nullptr;
	if (k == n->key)
		return n;
	if (k < n->key)
		return get(n->left, k);
	else
		return get(n->right, k);
}

void Tree::fixSize(Node* n)
{
	n->size = getSize(n->left) + getSize(n->right) + 1;
}

inline int Tree::getSize(Node* n)
{
	if (!n) return 0;
	return n->size;
}

Node* Tree::rotateRight(Node* n)
{
	Node* q = n->left;
	if (!q) return n;
	n->left = q->right;
	q->right = n;
	q->size = n->size;
	fixSize(n);
	return q;
}

Node* Tree::rotateLeft(Node* n)
{
	Node* p = n->right;
	if (!p) return n;
	n->right = p->left;
	p->left = n;
	p->size = n->size;
	fixSize(n);
	return p;
}

Node* Tree::insertRoot(Node* n, int k, Bank b)
{
	if (!n) return new Node(k, b);
	if (k < n->key)
	{
		n->left = insertRoot(n->left, k, b);
		return rotateRight(n);
	}
	else
	{
		n->right = insertRoot(n->right, k, b);
		return rotateLeft(n);
	}
}

Node* Tree::root()
{
	return _root;
}

void Tree::print(Node* node, int level)
{
	if (node == nullptr)
		return;

	level += COUNT;
	print(node->right, level);

	cout << endl;
	for (int i = COUNT; i < level; i++)
		cout << ' ';
	cout << node->data.toString();

	print(node->left, level);
}
