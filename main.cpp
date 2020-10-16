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
    std::vector <Citizen> people;
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
            people.push_back(temp);
        }
        std::cout << "Successfully loaded from file!" << std::endl;
        return people;
    }
    else
    {
        std::cout << "Error! Cannot open file";
        return people;
    }
}

int main()
{
    std::vector <Citizen> people = LoadFromFile();

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
    
    if(!found) std::cout << "OOPS! No result" << std::endl;

    system("pause");
    return 0;
}