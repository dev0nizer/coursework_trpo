#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

#define filepath data.txt


class Citizen
{
    std::string name;
    std::string city;
    int phonenumber;
    Citizen* next;
    public:
        void Add(std::string add_name, std::string add_city, int add_phonenumber)
        {
            name = add_name;
            city = add_city;
            phonenumber = add_phonenumber;
        }

        void AddFromKeyboard()
        {
            std::cout << "Enter name" << std::endl;
            std::cin >> name;
            std::cout << "Enter city" << std::endl;
            std::cin >> city;
            std::cout << "Enter phone number" << std::endl;
            std::cin >> phonenumber;        
        }

        int Getnumber()
        {
            return phonenumber;
        }

        void GetMember()
        {
            std::cout << name << " " << city << " " << phonenumber << std::endl;
        }

};

std::vector <Citizen> LoadFromFile()
{
    std::vector <Citizen> temppeople;
    std::ifstream file("data.txt");
    if (file.is_open())
    {
        while(!file.eof()) // push from file to vector
        {
            std::string templine;
            std::string tempname;
            std::string tempcity;
            int tempphonenumber;
            std::getline(file, templine);
            int pos = templine.find("|");
            tempname = templine.substr(0, pos);
            templine.erase(0, pos + 1);
            pos = templine.find("|");
            tempcity = templine.substr(0, pos);
            templine.erase (0, pos +1);
            tempphonenumber = std::stoi(templine);
            Citizen temp;
            temp.Add(tempname, tempcity, tempphonenumber);
            temppeople.push_back(temp);
        }
        std::cout << "Successfully loaded from file!" << std::endl;
        return temppeople;
    }
    else
    {
        std::cout << "Error! Cannot open file";
        return temppeople;
    }
}

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
                    break;
                }
            }
            if (found)
            {
                std::cout << "Found: ";
                people[i].GetMember();
            }
            else
            {
                std::cout << "Member not found" << std::endl;
            }
            
            break;
        }
        

        case 4:
        {
            std::map<int,int> index;
            std::map<int,int>::iterator it;
            for (int i = 0; i < people.size(); i++)
            {
                index.insert(std::make_pair(people[i].Getnumber(), i));
            }

            
            int phone_range_begin;
            int phone_range_end;
            std::cout << "Enter range begin" << std::endl;
            std::cin >> phone_range_begin;
            std::cout << "Enter range end" << std::endl;
            std::cin >> phone_range_end;
            bool found = false;
            for (it = index.begin(); it != index.end(); it++)
            {
                if(it->first > phone_range_begin && it->first < phone_range_end)
                {
                    people[it->second].GetMember();
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