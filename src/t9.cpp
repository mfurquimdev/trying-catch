#include "t9.h"

#include <boost/algorithm/string.hpp>

int
T9::Encode( std::string str )
{
	setMChar( str );
	int encoded = -1;

	switch( getMChar() )
	{
		case 'A':
		case 'B':
		case 'C':
			encoded = 2;
			break;

		case 'D':
		case 'E':
		case 'F':
			encoded = 3;
			break;

		case 'G':
		case 'H':
		case 'I':
			encoded = 4;
			break;

		case 'J':
		case 'K':
		case 'L':
			encoded = 5;
			break;

		case 'M':
		case 'N':
		case 'O':
			encoded = 6;
			break;

		case 'P':
		case 'Q':
		case 'R':
		case 'S':
			encoded = 7;
			break;

		case 'T':
		case 'U':
		case 'V':
			encoded = 8;
			break;

		case 'W':
		case 'X':
		case 'Y':
		case 'Z':
			encoded = 9;
			break;

		case ' ':
			encoded = 0;
			break;

		case '.':
		case ',':
			encoded = 1;
			break;

		default:
			encoded = -1;
			break;
	}

	setMKey(encoded);
	return getMKey();
}


T9::T9()
{
	setMChar( "" );
}

char
T9::getMChar( void ) const
{
	return mChar;
}

int
T9::getMKey( void ) const
{
	return mKey;
}

std::ostream& operator<< (std::ostream& os, T9 const& t9)
{
	os << "[" << t9.getMChar() << " -> " << t9.getMKey() << "]";
	return os;
}

void
T9::setMKey( int key )
{
	mKey = key;
}

void
T9::setMChar( std::string str )
{
	// Get the first char only
	mChar = boost::to_upper_copy<std::string>(str).c_str()[0];
}
