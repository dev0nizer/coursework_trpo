#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cassert>
#include "../func.cpp"

#define testfilepath "./test/testdata.txt"

int testloadfromfile()
{
    std::vector <Citizen> testvector;
    
    testvector = LoadFromFile(testfilepath);
    std::ifstream file (testfilepath);
    std::string teststring;
    std::getline(file, teststring);

    assert(teststring == testvector[0].GetMember());

    std::cout << "File loading test passed" << std::endl;
    return 0;
}

int testfindbyexactphonetrue()
{
    std::vector <Citizen> testvector;
    Citizen temp;
    temp.Add("Putin", "Moscow", 1111);
    testvector.push_back(temp);
    temp.Add("Trump", "Washington", 2222);
    testvector.push_back(temp);

    assert(findbyexactphone(testvector, 2222));
    
    std::cout << "Find by exact true test passed" << std::endl;
    return 0;
}

int testfindbyexactphonefalse()
{
    std::vector <Citizen> testvector;
    Citizen temp;
    temp.Add("Putin", "Moscow", 1111);
    testvector.push_back(temp);
    temp.Add("Trump", "Washington", 2222);
    testvector.push_back(temp);

    assert(!findbyexactphone(testvector, 3333));
    
    std::cout << "Find by exact true false passed" << std::endl;

    return 0;
}

int testfindbyrangetrue()
{
    std::vector <Citizen> testvector;
    Citizen temp;
    temp.Add("Putin", "Moscow", 1111);
    testvector.push_back(temp);
    temp.Add("Trump", "Washington", 2222);
    testvector.push_back(temp);

    assert(findbyrange(testvector, 1000,1200));

    std::cout << "Find by range true passed" << std::endl;

    return 0;
}

int testfindbyrangefalse()
{
    std::vector <Citizen> testvector;
    Citizen temp;
    temp.Add("Putin", "Moscow", 1111);
    testvector.push_back(temp);
    temp.Add("Trump", "Washington", 2222);
    testvector.push_back(temp);

    assert(!findbyrange(testvector, 1200,2200));

    std::cout << "Find by range false passed" << std::endl;

    return 0;
}

int runtests()
{
        testloadfromfile();
        testfindbyexactphonetrue();
        testfindbyexactphonefalse();
        testfindbyrangetrue();
        testfindbyrangefalse();
        return 0;
}

int main()
{
    int result = runtests();
    std::cout << result;
    return result;
}