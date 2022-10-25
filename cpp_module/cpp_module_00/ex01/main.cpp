#include <iostream>
#include "PhoneBook.hpp"

int main()
{
    PhoneBook phoneBook;
    std::string text;
    while (1)
    {
        std::cout << "command : ";
        std::cin >> text;
        if (std::cin.eof())
        {
            std::cout << "^D == EXIT" << std::endl;    
            break ;
        }
        if (text.compare("ADD") == 0)
            phoneBook.add();
        else if (text.compare("SEARCH") == 0)
            phoneBook.search();
        else if (text.compare("EXIT") == 0)
            phoneBook.exitBook();
        else
            std::cout << "You can command ADD, SEARCH, EXIT" << std::endl;
    }
    // if (std::cin.eof())
    //         std::cout << "^D == EXIT" << std::endl;
    return (0);
}