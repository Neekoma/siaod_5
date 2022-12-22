#include "files.h"

void readTxt(Tree& t) {
	ifstream fi(FILENAME_TXT, ios::in);

	if (!fi.is_open())
		exit(-1);

	Bank b;

	while (!fi.eof()) {
		fi >> b.code >> b.title >> b.address >> b.owner;
		t.insert(t.root(), b.key(), b);
	}

	fi.close();
}


void writeBin(Tree& t)
{
	ofstream fo;
	fo.open(FILENAME_BIN, ios::out | ios::binary);
	int count = writeNode(t.root(), fo);
	fo.close();
}

int writeNode(Node* node, ofstream& fo, int num)
{
	FileNode fnode;
	fnode.number = num;
	int lnum = num;
	fnode.data = fnode.data = node->data;
	fo.write((char*)&fnode, sizeof(FileNode));
	if (node->left) {
		fnode.left = ++num;
		num = writeNode(node->left, fo, num);
	}
	if (node->right) {
		fnode.right = ++num;
		num = writeNode(node->right, fo, num);
	}
	fo.seekp(lnum * sizeof(FileNode));
	fo.write((char*)&fnode, sizeof(FileNode));
	return num;
}

Bank getRecord(int key)
{
	ifstream f;
	f.open(FILENAME_BIN, ios::binary);
	FileNode node;
	f.read((char*)&node, sizeof(FileNode));
	while (node.data.key() != key) {
		if (key < node.data.key()) {
			f.seekg(node.left * sizeof(FileNode));
		}
		else {
			f.seekg(node.right * sizeof(FileNode));
		}
		f.read((char*)&node, sizeof(FileNode));
	}
	f.close();
	return node.data;
}