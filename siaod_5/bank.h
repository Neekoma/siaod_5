#pragma once
#include<string>
struct Bank {
	char title[45];
	char code[45];
	char address[45];
	int owner = -1; // 0 - гос, 1 - частн.

	
	int key();

	std::string toString();

	static Bank empty() {
		return Bank{};
	}
};