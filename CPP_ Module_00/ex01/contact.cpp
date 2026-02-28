#include "contact.hpp"

int Contact::add_contact(std::string str)
{
    std::string buffer;

    while (1)
    {
        std::cout << str << ": ";
        if (!getline(std::cin, buffer))
            return 0;
        if (!buffer[0])
            continue;
        if (str == "firstname")
        {
            this->_firstname = buffer;
            break;
        }
        else if (str == "lastname")
        {
            this->_lastname = buffer;
            break;
        }
        else if (str == "nickname")
        {
            this->_nickname = buffer;
            break;
        }
        else if (str == "phonenumber")
        {
            this->_phonenumber = buffer;
            break;
        }
        else if (str == "darkestsecret")
        {
            this->_darkestsecret = buffer;
            break;
        }
    }
    return 1;
}

void    Contact::print_tab(int index) const
{
    std::cout << std::right << std::setw(10) << index + 1 << "|";
    if (this->_firstname.length() >= 10)
        std::cout << std::right << this->_firstname.substr(0, 9) << "." << "|";
    else
        std::cout << std::right << std::setw(10) << this->_firstname << "|";
    if (this->_lastname.length() >= 10)
        std::cout << std::right << this->_lastname.substr(0, 9) << "." << "|";
    else
        std::cout << std::right << std::setw(10) << this->_lastname << "|";
    if (this->_nickname.length() >= 10)
        std::cout << std::right << this->_nickname.substr(0, 9) << "." << "|" << std::endl;
    else
        std::cout << std::right << std::setw(10) << this->_nickname << "|" << std::endl;
}

void    Contact::print(void) const
{
    std::cout << "firstname: " << _firstname << std::endl
    << "lastname: " << _lastname << std::endl
    << "nickname: " << _nickname << std::endl
    << "phonenumber: " << _phonenumber << std::endl
    << "darkestsecret: " <<_darkestsecret << std::endl;
}
