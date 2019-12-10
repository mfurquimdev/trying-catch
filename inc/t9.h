#ifndef __T9_H__
#define __T9_H__

#include <string>

#include <iostream>

class T9
{
public:
	T9();

	void Encode( std::string str );

	char getMChar( void ) const;
	int getMKey( void ) const;

//	friend std::ostream& operator << (std::ostream&, T9 const&);

private:
	// Receives a string but stores only the first char
	void setMChar( std::string str );

	char mChar;
	int  mKey;
};
#endif
