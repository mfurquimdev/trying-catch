#include "t9.h"

#include <iostream>

int main()
{
	std::cout << "Escolha um caracter: ";
	std::string str;
	std::cin >> str;
	T9 t9(str);

	std::cout << "Tu escolhestes a string: [" << t9.getMChar() << "]" << std::endl;

	std::cout << "Encoded: [" << t9.Encode(str) << "]" << std::endl;

	return 0;
}
