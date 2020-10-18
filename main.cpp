#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include "func.cpp"

#define filepath data.txt

int main()
{
    std::vector <Citizen> people;
    bool exit = false;
    while (!exit)
    {
        std::cout << "Choose option:" << std::endl;
        std::cout << "1) Load from file(re-write current)" << std::endl;
        std::cout << "2) Add member to data" << std::endl;
        std::cout << "3) Find member by exact input" << std::endl;
        std::cout << "4) Find member by range" << std::endl;
        std::cout << "5) Print current dataset" << std::endl;
        std::cout << "6) Exit prog" << std::endl;
        int x;
        std::cin >> x;
        switch (x)
        {
        case 1:
            {
                people = LoadFromFile();
                break;
            }
        case 2:
        {
            Citizen temp;
            temp.AddFromKeyboard();
            people.push_back(temp);
            break;
        }
        case 3:
        {
            std::cout << "Enter number" << std::endl;
            int input;
            std::cin >> input;
            bool found = false;
            int i=0;
            for (i=0; i<people.size(); i++)
            {
                if (people[i].Getnumber() == input)
                {
                    found = true;
                    people[i].GetMember();
                }
            }
            if (!found)
            {
                std::cout << "Member not found" << std::endl;
            }
            
            break;
        }
        

        case 4:
        {
            int phone_range_begin;
            int phone_range_end;
            std::cout << "Enter range begin" << std::endl;
            std::cin >> phone_range_begin;
            std::cout << "Enter range end" << std::endl;
            std::cin >> phone_range_end;
            bool found = false;
            for (int i=0; i<people.size(); i++)
            {
                if(people[i].Getnumber() > phone_range_begin && people[i].Getnumber() < phone_range_end)
                {
                    people[i].GetMember();
                    found = true;
                }

            }
            
            if(!found)
            {
                std::cout << "OOPS! No result" << std::endl;
            }

            break;      
        }

        case 5:
        {
            for (int i=0; i<people.size(); i++)
            {
                people[i].GetMember();
            }
            break;
        }
        case 6:
        {
            return 0;
        }
        
        default:
            {
                std::cout << "Invalid input" << std::endl;
                break;
            }
        }
    }
    
    return 0;
}