#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cassert>
#include "../func.cpp"

#define testfilepath "testdata.txt"

void testloadfromfile()
{
    std::vector <Citizen> testvector;
    
    testvector = LoadFromFile(testfilepath);
    std::ifstream file (testfilepath);
    std::string teststring;
    std::getline(file, teststring);

    assert(teststring == testvector[0].GetMember());

    std::cout << "File loading test passed" << std::endl;
    
}

int main()
{
    testloadfromfile();

    int x;
    std::cin >> x;
    return 0;
}