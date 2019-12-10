
#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "t9.h"

#include <string>

// Does not work, WHY?
namespace Catch
{
	std::string toString(T9 const& t9)
	{
		std::string str;
		str = t9.getMChar();
		return str;
	}
}

TEST_CASE("Encode key 2 letters (A,B,C) --> return 2", "[Single Digit] [Key 2 Letters]")
{
	T9 t9;

	t9.Encode("A");
	CAPTURE(t9);
	CHECK(t9.getMChar() ==  'A');
	REQUIRE(t9.getMKey() ==  2);

	t9.Encode("B");
	CAPTURE(t9);
	CHECK(t9.getMChar() ==  'B');
	REQUIRE(t9.getMKey() ==  2);

	t9.Encode("C");
	CAPTURE(t9);
	CHECK(t9.getMChar() ==  'C');
	REQUIRE(t9.getMKey() ==  2);
}

TEST_CASE("Encode key 3 letters (D,E,F) --> return 3", "[Single Digit] [Key 3 Letters]")
{
	T9 t9;

	t9.Encode("D");
	CAPTURE(t9);
	CHECK(t9.getMChar() ==  'D');
	REQUIRE(t9.getMKey() ==  3);

	t9.Encode("E");
	CAPTURE(t9);
	CHECK(t9.getMChar() ==  'E');
	REQUIRE(t9.getMKey() ==  3);

	t9.Encode("F");
	CAPTURE(t9);
	CHECK(t9.getMChar() ==  'F');
	REQUIRE(t9.getMKey() ==  3);
}

TEST_CASE("Encode key 4 letters (G,H,I) --> return 4", "[Single Digit] [Key 4 Letters]")
{
	T9 t9;

	t9.Encode("G");
	CAPTURE(t9);
	CHECK(t9.getMChar() ==  'G');
	REQUIRE(t9.getMKey() ==  4);

	t9.Encode("H");
	CAPTURE(t9);
	CHECK(t9.getMChar() ==  'H');
	REQUIRE(t9.getMKey() ==  4);

	t9.Encode("I");
	CAPTURE(t9);
	CHECK(t9.getMChar() ==  'I');
	REQUIRE(t9.getMKey() ==  4);
}

TEST_CASE("Encode key 5 letters (J,K,L) --> return 5", "[Single Digit] [Key 5 Letters]")
{
	T9 t9;

	t9.Encode("J");
	CAPTURE(t9);
	CHECK(t9.getMChar() ==  'J');
	REQUIRE(t9.getMKey() ==  5);

	t9.Encode("K");
	CAPTURE(t9);
	CHECK(t9.getMChar() ==  'K');
	REQUIRE(t9.getMKey() ==  5);

	t9.Encode("L");
	CAPTURE(t9);
	CHECK(t9.getMChar() ==  'L');
	REQUIRE(t9.getMKey() ==  5);
}

TEST_CASE("Encode key 6 letters (M,N,O) --> return 6", "[Single Digit] [Key 6 Letters]")
{
	T9 t9;

	t9.Encode("M");
	CAPTURE(t9);
	CHECK(t9.getMChar() ==  'M');
	REQUIRE(t9.getMKey() ==  6);

	t9.Encode("N");
	CAPTURE(t9);
	CHECK(t9.getMChar() ==  'N');
	REQUIRE(t9.getMKey() ==  6);

	t9.Encode("O");
	CAPTURE(t9);
	CHECK(t9.getMChar() ==  'O');
	REQUIRE(t9.getMKey() ==  6);
}

TEST_CASE("Encode key 7 letters (P,Q,R,S) --> return 7", "[Single Digit] [Key 7 Letters]")
{
	T9 t9;

	t9.Encode("P");
	CAPTURE(t9);
	CHECK(t9.getMChar() ==  'P');
	REQUIRE(t9.getMKey() ==  7);

	t9.Encode("Q");
	CAPTURE(t9);
	CHECK(t9.getMChar() ==  'Q');
	REQUIRE(t9.getMKey() ==  7);

	t9.Encode("R");
	CAPTURE(t9);
	CHECK(t9.getMChar() ==  'R');
	REQUIRE(t9.getMKey() ==  7);

	t9.Encode("S");
	CAPTURE(t9);
	CHECK(t9.getMChar() ==  'S');
	REQUIRE(t9.getMKey() ==  7);
}

TEST_CASE("Encode key 8 letters (T,U,V) --> return 8", "[Single Digit] [Key 8 Letters]")
{
	T9 t9;

	t9.Encode("T");
	CAPTURE(t9);
	CHECK(t9.getMChar() ==  'T');
	REQUIRE(t9.getMKey() ==  8);

	t9.Encode("U");
	CAPTURE(t9);
	CHECK(t9.getMChar() ==  'U');
	REQUIRE(t9.getMKey() ==  8);

	t9.Encode("V");
	CAPTURE(t9);
	CHECK(t9.getMChar() ==  'V');
	REQUIRE(t9.getMKey() ==  8);
}

TEST_CASE("Encode key 9 letters (W,X,Y,Z) --> return 9", "[Single Digit] [Key 9 Letters]")
{
	T9 t9;

	t9.Encode("W");
	CAPTURE(t9);
	CHECK(t9.getMChar() ==  'W');
	REQUIRE(t9.getMKey() ==  9);

	t9.Encode("X");
	CAPTURE(t9);
	CHECK(t9.getMChar() ==  'X');
	REQUIRE(t9.getMKey() ==  9);

	t9.Encode("Y");
	CAPTURE(t9);
	CHECK(t9.getMChar() ==  'Y');
	REQUIRE(t9.getMKey() ==  9);

	t9.Encode("Z");
	CAPTURE(t9);
	CHECK(t9.getMChar() ==  'Z');
	REQUIRE(t9.getMKey() ==  0);
}

TEST_CASE("Encode key 1 letters (.,,,) --> return 1", "[Single Digit] [Key 1 Letters]")
{
	T9 t9;

	t9.Encode(".");
	CAPTURE(t9);
	CHECK(t9.getMChar() ==  '.');
	REQUIRE(t9.getMKey() ==  1);

	t9.Encode(",");
	CAPTURE(t9);
	CHECK(t9.getMChar() ==  ',');
	REQUIRE(t9.getMKey() ==  1);
}

TEST_CASE("Encode key 0 letters ( ) --> return 0", "[Single Digit] [Key 0 Letters]")
{
	T9 t9;

	t9.Encode(" ");
	CAPTURE(t9);
	CHECK(t9.getMChar() ==  ' ');
	REQUIRE(t9.getMKey() ==  0);
}

TEST_CASE("Encode incorrect letter --> return -1", "[Single Digit] [Incorrect Letter]")
{
	INFO("INFO: At the top of the TEST CASE");
	WARN("WARN: At the top of the TEST CASE");

	{
		INFO("INFO: Inside a scope");
		WARN("WARN: Inside a scope");
	}

	T9 t9;

	INFO("INFO: Test on Encode(\"?\")");
	t9.Encode("?");
	CAPTURE(t9);
	CHECK(t9.getMChar() ==  '?');
	REQUIRE(t9.getMKey() ==  -1);
	FAIL("I will fail after '?'");
}
