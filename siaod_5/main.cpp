#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"tree.h"
#include"bank.h"
#include"files.h"
#include<fstream>

using namespace std;


int main() {
	setlocale(LC_ALL, "Ru");
	Tree t;
	readTxt(t);
	cout << "��������� ���� ��������. ��������� ������: \n";
	t.print(t.root());
	writeBin(t);
	cout << "����������� �������� ����...\n";
	Bank b;
	string s;
	loop:
	cout << "������� ��� �����, ������� ������ �������� �� ������� �������:\n>";
	cin >> s;
	strcpy(b.code, s.c_str());
	auto bank = getRecord(b.key());
	cout << "�� ����� ����:\n" << bank.title << " �� " << bank.address << endl;
	goto loop;
	return 0;
}