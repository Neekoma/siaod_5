#include"bank.h"



int Bank::key()
{
	int sum = 0;
	for (int i = 0; i < strlen(code); i++) {
		if (code[i] >= '0' && code[i] <= '9')
			sum += code[i] - 48;
	}
	return sum;
}

std::string Bank::toString()
{
	return std::string(std::string(title) + "|" + std::string(code) + "|" + std::string(address) + "|" + std::string((owner == 0) ? "Гос." : "Частн."));
}
