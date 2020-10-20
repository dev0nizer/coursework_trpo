#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cassert>
#include "../func.cpp"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#define testfilepath "./tests/testdata.txt"

TEST_CASE("testloadfromfile")
{
    std::vector <Citizen> testvector;
    testvector = LoadFromFile(testfilepath);
    std::ifstream file (testfilepath);
    std::string teststring;
    std::getline(file, teststring);
    REQUIRE(teststring == testvector[0].GetMember());
}

TEST_CASE("testfindbyexact")
{
    std::vector <Citizen> testvector;
    Citizen temp;
    temp.Add("Putin", "Moscow", 1111);
    testvector.push_back(temp);
    temp.Add("Trump", "Washington", 2222);
    testvector.push_back(temp);
    REQUIRE(findbyexactphone(testvector, 2222));    
    REQUIRE(!findbyexactphone(testvector, 2000));
}

TEST_CASE("testfindbyrange")
{
    std::vector <Citizen> testvector;
    Citizen temp;
    temp.Add("Putin", "Moscow", 1111);
    testvector.push_back(temp);
    temp.Add("Trump", "Washington", 2222);
    testvector.push_back(temp);
    REQUIRE(findbyrange(testvector, 1000,1200));    
    REQUIRE(!findbyrange(testvector, 1200,2000));    
}