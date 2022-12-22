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
	cout << "Текстовый файл прочитан. Построено дерево: \n";
	t.print(t.root());
	writeBin(t);
	cout << "Сформирован двоичный файл...\n";
	Bank b;
	string s;
	loop:
	cout << "Введите код банка, который хотите получить по прямому доступу:\n>";
	cin >> s;
	strcpy(b.code, s.c_str());
	auto bank = getRecord(b.key());
	cout << "Вы нашли банк:\n" << bank.title << " из " << bank.address << endl;
	goto loop;
	return 0;
}