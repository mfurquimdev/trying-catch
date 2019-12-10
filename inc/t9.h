#ifndef __T9_H__
#define __T9_H__

#include <string>

class T9
{
public:
	T9();
	T9( std::string str );

	int Encode( std::string str );

	// Receives a string but stores only the first char
	void setMChar( std::string str );
	char getMChar( void );

private:
	char mChar;
};
#endif
