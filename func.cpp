#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

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