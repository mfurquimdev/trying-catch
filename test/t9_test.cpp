
#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "t9.h"

TEST_CASE( "Encode single uppercase letter --> return correct digit", "[Single Digit]")
{
	T9 encoder;

	INFO("Start testing second key");
	CHECK(encoder.Encode("A") ==  2);
	CHECK(encoder.Encode("B") ==  2);
	CHECK(encoder.Encode("C") ==  2);

	WARN("Maybe now?");
	INFO("Start testing third key");
	CHECK(encoder.Encode("D") ==  2);
//	REQUIRE(encoder.Encode("D") ==  2);
	// Test with both CHECK and REQUIRE.
	// Watch the CAPTURE and FAIL behaviour
	CAPTURE(encoder.getMChar());
	FAIL("I will fail after 'D'");
	CHECK(encoder.Encode("E") ==  3);
	CHECK(encoder.Encode("F") ==  3);

	CHECK(encoder.Encode("G") ==  4);
	CHECK(encoder.Encode("H") ==  4);
	CHECK(encoder.Encode("I") ==  4);

	CHECK(encoder.Encode("J") ==  5);
	CHECK(encoder.Encode("K") ==  5);
	CHECK(encoder.Encode("L") ==  5);

	CHECK(encoder.Encode("M") ==  6);
	CHECK(encoder.Encode("N") ==  6);
	CHECK(encoder.Encode("O") ==  6);

	CHECK(encoder.Encode("P") ==  7);
	CHECK(encoder.Encode("Q") ==  7);
	CHECK(encoder.Encode("R") ==  7);
	CHECK(encoder.Encode("S") ==  7);

	CHECK(encoder.Encode("T") ==  8);
	CHECK(encoder.Encode("U") ==  8);
	CHECK(encoder.Encode("V") ==  8);

	CHECK(encoder.Encode("W") ==  9);
	CHECK(encoder.Encode("X") ==  9);
	CHECK(encoder.Encode("Y") ==  9);
	CHECK(encoder.Encode("Z") ==  9);

	CHECK(encoder.Encode(" ") ==  0);

	CHECK(encoder.Encode(".") ==  1);
	CHECK(encoder.Encode(",") ==  1);

	CHECK(encoder.Encode("?") ==  -1);
}
