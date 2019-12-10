#include "t9.h"

#include <iostream>

int main()
{
	std::cout << "Escolha um caracter: ";
	std::string str;
	std::cin >> str;

	T9 t9;
	t9.Encode(str);

	std::cout << "Char: " << t9.getMChar() << "\tKey: " << t9.getMKey() << std:: endl;

	return 0;
}
