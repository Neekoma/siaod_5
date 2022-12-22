#pragma once
#include<iostream>
#include"bank.h"
#define COUNT 16

using std::cout;
using std::endl;
using std::cin;

struct Node {
	int key;
	Bank data;
	int size;
	Node* left;
	Node* right;
	Node(int k, Bank b) { key = k; data = b; left = right = nullptr; size = 1; }
};

class Tree {
private:
	Node* _root;

public:
	Tree();
	Tree(int k, Bank b);
	Node* insert(Node* p, int, Bank k); // рандомизированная вставка нового узла
	
	Node* get(Node* n, int);
	void fixSize(Node* n);
	inline int getSize(Node* n);
	Node* rotateRight(Node* n);
	Node* rotateLeft(Node* n);
	Node* insertRoot(Node* n,int, Bank k);

	Node* root();

	Node* join(Node* n, Node* q) // объединение двух деревьев
	{
		if (!n) return q;
		if (!q) return n;
		if (rand() % (n->size + q->size) < n->size)
		{
			n->right = join(n->right, q);
			fixSize(n);
			return n;
		}
		else
		{
			q->left = join(n, q->left);
			fixSize(q);
			return q;
		}
	}

	Node* remove(Node* n, int k) // удаление из дерева p первого найденного узла с ключом k 
	{
		if (!n) return n;
		if (n->key == k)
		{
			Node* q = join(n->left, n->right);
			delete n;
			return q;
		}
		else if (k < n->key)
			n->left = remove(n->left, k);
		else
			n->right = remove(n->right, k);
		return n;
	}

	void print(Node* node, int level = 0);
};