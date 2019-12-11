
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

class T9Tests
{
	T9 t9;

protected:
	void EncodeAndCheck( const std::string& str, int expectedDigit )
	{
		auto result = t9.Encode(str);

		CAPTURE(t9);
		CHECK(result == expectedDigit);
	}
};

TEST_CASE_METHOD(T9Tests, "Encode letters to keys")
{
	SECTION("Encode letters on key 2", "[Single Digit] [Key 2 Letters]")
	{
		EncodeAndCheck("A", 2);
		EncodeAndCheck("B", 2);
		EncodeAndCheck("C", 2);
	}

	SECTION("Encode letters on key 3", "[Single Digit] [Key 3 Letters]")
	{
		EncodeAndCheck("D", 3);
		EncodeAndCheck("E", 3);
		EncodeAndCheck("F", 3);
	}

	SECTION("Encode letters on key 4", "[Single Digit] [Key 4 Letters]")
	{
		EncodeAndCheck("G", 4);
		EncodeAndCheck("H", 4);
		EncodeAndCheck("I", 4);
	}

	SECTION("Encode letters on key 5", "[Single Digit] [Key 5 Letters]")
	{
		EncodeAndCheck("J", 5);
		EncodeAndCheck("K", 5);
		EncodeAndCheck("L", 5);
	}

	SECTION("Encode letters on key 6", "[Single Digit] [Key 6 Letters]")
	{
		EncodeAndCheck("M", 6);
		EncodeAndCheck("N", 6);
		EncodeAndCheck("O", 6);
	}

	SECTION("Encode letters on key 7", "[Single Digit] [Key 7 Letters]")
	{
		EncodeAndCheck("P", 7);
		EncodeAndCheck("Q", 7);
		EncodeAndCheck("R", 7);
		EncodeAndCheck("S", 7);
	}

	SECTION("Encode letters on key 8", "[Single Digit] [Key 8 Letters]")
	{
		EncodeAndCheck("T", 8);
		EncodeAndCheck("U", 8);
		EncodeAndCheck("V", 8);
	}

	SECTION("Encode letters on key 9", "[Single Digit] [Key 9 Letters]")
	{
		EncodeAndCheck("W", 9);
		EncodeAndCheck("X", 9);
		EncodeAndCheck("Y", 9);
		EncodeAndCheck("Z", 9);
	}

	SECTION("Encode letters on key 0", "[Single Digit] [Key 0 Letters]")
	{
		EncodeAndCheck(" ", 0);
	}

	SECTION("Encode letters on key 1", "[Single Digit] [Key 1 Letters]")
	{
		EncodeAndCheck(".", 1);
		EncodeAndCheck(",", 1);
	}
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
