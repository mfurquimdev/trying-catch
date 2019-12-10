
#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "t9.h"

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
