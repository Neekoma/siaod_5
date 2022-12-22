#pragma once

#include<string>
#include"bank.h"
#include<fstream>
#include<iostream>
#include"tree.h"

#define FILENAME_TXT "source.txt"
#define FILENAME_BIN "test.bin"
using namespace std;

struct FileNode {
	int number;
	int left = -1;
	int right = -1;
	Bank data;
};

void readTxt(Tree& t);
void writeBin(Tree& t);
int writeNode(Node* node, ofstream& fo, int number=0);
Bank getRecord(int key);