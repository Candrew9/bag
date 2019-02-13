////////////////////////////////////////////////////////
// ECE 2574, Homework 1
//
// File name:   hw1_test.cpp
// Description: STARTER CODE
// Date:        1/2019  
//
#define CATCH_CONFIG_MAIN			// this line tells Catch to provide a main() function
#define CATCH_CONFIG_COLOUR_NONE	// this line avoids problems due to color-coding the output
#include "catch.hpp"

#include "ArrayBag.h" 

// The following set of tests needs to be expanded
TEST_CASE("Test an empty bag of integers", "[ArrayBag]") {
	
	ArrayBag<int> b;
	REQUIRE(b.isEmpty()); 
	REQUIRE(b.getCurrentSize() == 0);
	REQUIRE(!b.contains(5));
}

TEST_CASE("Test an bag of strings", "[ArrayBag]") {

	ArrayBag<std::string> b;
	REQUIRE(b.isEmpty()); 
	REQUIRE(b.getCurrentSize() == 0);
	REQUIRE(b.add("Hello"));
	REQUIRE(b.contains("Hello"));
}


