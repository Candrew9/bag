////////////////////////////////////////////////////////
// ECE 2574, Homework 1, Andrew Caldwell
//
// File name:   hw1_test.cpp
// Description: Test a modified bag ADT
// Date:        2/7/19
//
#define CATCH_CONFIG_MAIN			// this line tells Catch to provide a main() function
#define CATCH_CONFIG_COLOUR_NONE	// this line avoids problems due to color-coding the output
#include "catch.hpp"

#include "ArrayBag.h" 

// This test creates a bag of integers,
// then determines if it can be turned into a vector
TEST_CASE("Test an empty bag of integers", "[ArrayBag]") {
	
	ArrayBag<int> b;
	REQUIRE(b.isEmpty()); 
	REQUIRE(b.getCurrentSize() == 0);
	REQUIRE(!b.contains(5));
    
    //Adding integers
}

//Tests an empty bag, fills it with integers,
//tests the default ceiling and then clears it
TEST_CASE("Fills bag with integers, then removes them", "[ArrayBag]") {
    
    ArrayBag<int> b;
    REQUIRE(b.isEmpty());
    REQUIRE(b.add(1));
    REQUIRE(b.getCurrentSize() == 1);
    REQUIRE(b.add(2));
    REQUIRE(b.getCurrentSize() == 2);
    REQUIRE(b.add(3));
    REQUIRE(b.getCurrentSize() == 3);
    REQUIRE(b.add(4));
    REQUIRE(b.getCurrentSize() == 4);
    REQUIRE(b.add(5));
    REQUIRE(b.getCurrentSize() == 5);
    REQUIRE(b.add(6));
    REQUIRE(b.getCurrentSize() == 6);
    REQUIRE(!b.isEmpty());
    REQUIRE(!b.add(7));
    REQUIRE(b.getCurrentSize() == 6);
    REQUIRE(b.remove(6));
    REQUIRE(b.getCurrentSize() == 5);
    b.clear();
    REQUIRE(b.getCurrentSize() == 0);
    REQUIRE(b.isEmpty());
}

//Tests the contains, frequency methods of the bag
//Tests reduce with the full bag
TEST_CASE("Strings are put in bag, then frequency ensured", "[ArrayBag]") {

	ArrayBag<std::string> b;
	REQUIRE(b.isEmpty()); 
	REQUIRE(b.getCurrentSize() == 0);
	REQUIRE(b.add("Hello"));
	REQUIRE(b.contains("Hello"));
    REQUIRE(b.add("Hi"));
    REQUIRE(b.contains("Hi"));
    REQUIRE(b.add("Hello"));
    REQUIRE(b.contains("Hello"));
    REQUIRE(b.add("This is a bag"));
    REQUIRE(b.contains("This is a bag"));
    REQUIRE(b.add("Hello"));
    REQUIRE(b.contains("Hello"));
    REQUIRE(b.add("Hi"));
    REQUIRE(b.contains("Hi"));
    REQUIRE(b.getCurrentSize() == 6);
    
    //testing the frequency of strings in the bag
    REQUIRE(b.getFrequencyOf("Hello") == 3);
    REQUIRE(b.getFrequencyOf("Hi") == 2);
    REQUIRE(b.getFrequencyOf("This is a bag") == 1);
    REQUIRE(b.getFrequencyOf("bag") == 0);
    
    //Testing reduce methods
    REQUIRE(b.flatten());
    REQUIRE(b.getFrequencyOf("Hello") == 1);
    REQUIRE(b.getFrequencyOf("Hi") == 1);
    REQUIRE(b.getFrequencyOf("This is a bag") == 1);
    REQUIRE(!b.flatten());
}

//Test The reduce method with a bag
TEST_CASE("Reduces a bag filled with integers", "[ArrayBag]") {
    ArrayBag<int> b; //Creates the bag
    
    //Adding entries to the bag, various amounts
    REQUIRE(b.add(1));
    REQUIRE(b.add(1));
    REQUIRE(b.add(1));
    REQUIRE(b.add(3));
    REQUIRE(b.add(2));
    REQUIRE(b.add(2));
    REQUIRE(!b.isEmpty());
    REQUIRE(b.getFrequencyOf(1) == 3);
    REQUIRE(b.getFrequencyOf(2) == 2);
    REQUIRE(b.getFrequencyOf(3) == 1);
    
    REQUIRE(b.reduce());
    REQUIRE(b.getCurrentSize() == 5);
    REQUIRE(b.getFrequencyOf(3) == 0);
    REQUIRE(b.getFrequencyOf(2) == 2);
    REQUIRE(b.getFrequencyOf(1) == 3);
    
    
    REQUIRE(b.reduce());
    REQUIRE(b.getCurrentSize() == 3);
    REQUIRE(b.getFrequencyOf(1) == 3);
    REQUIRE(b.getFrequencyOf(3) == 0);
    REQUIRE(b.getFrequencyOf(2) == 0);
    
    
    REQUIRE(b.reduce());
    REQUIRE(b.isEmpty());
    REQUIRE(b.getFrequencyOf(1) == 0);
    REQUIRE(b.getFrequencyOf(3) == 0);
    REQUIRE(b.getFrequencyOf(2) == 0);
    REQUIRE(b.getCurrentSize() == 0);
    
    
    REQUIRE(!b.reduce());
}
TEST_CASE("test second constructor", "[ArrayBag]") {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    
    ArrayBag<int> b(arr, 8);
    ArrayBag<int> s;
    REQUIRE(b.getCurrentSize() == 6);
    b.clear();
    REQUIRE(b.getCurrentSize() == 0);
    REQUIRE(b.add(1));
    REQUIRE(b.add(2));
    REQUIRE(b.add(3));
    REQUIRE(s.add(4));
    REQUIRE(s.add(5));
    REQUIRE(s.add(6));
    
    REQUIRE(b.bagUnion(s).getCurrentSize() == 6);
    
}
TEST_CASE("replace tested using a bag full of integers", "[ArrayBag]") {
    ArrayBag<int> b;
    REQUIRE(b.getCurrentSize() == 0);
    REQUIRE(b.add(1));
    REQUIRE(b.add(2));
    REQUIRE(b.add(1));
    REQUIRE(b.add(2));
    REQUIRE(b.add(3));
    REQUIRE(b.add(3));
    REQUIRE(b.getCurrentSize() == 6);
    REQUIRE(b.getFrequencyOf(1) == 2);
    REQUIRE(b.getFrequencyOf(4) == 0);
    REQUIRE(b.replace(1, 4));
    REQUIRE(b.getFrequencyOf(1) == 0);
    REQUIRE(b.getFrequencyOf(4) == 2);
    REQUIRE(b.getFrequencyOf(5) == 0);
    REQUIRE(!b.replace(5, 3));
}


