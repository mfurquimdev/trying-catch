#include "t9.h"

#include <iostream>

#include <string>

std::string toString(T9 const& t9)
{
	std::string str;
	str = t9.getMChar();
	return str;
}

int main()
{
	std::cout << "Escolha um caracter: ";
	std::string str;
	std::cin >> str;

	T9 t9;
	t9.Encode(str);

	std::cout << "Char: " << t9.getMChar() << "\tKey: " << t9.getMKey() << std:: endl;

	std::cout << std::endl << toString(t9) << std::endl;

	return 0;
}
