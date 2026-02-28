#include "phonebook.hpp"

Phonebook::Phonebook(int i) : _index(i), _total(i)
{

}

int    Phonebook::add(void)
{
    if (this->_index >= 8)
        this->_index = 0;
    if (!this->_contacts[this->_index].add_contact("firstname"))
        return 0;
    if (!this->_contacts[this->_index].add_contact("lastname"))
        return 0;
    if (!this->_contacts[this->_index].add_contact("nickname"))
        return 0;
    if (!this->_contacts[this->_index].add_contact("phonenumber"))
        return 0;
    if (!this->_contacts[this->_index].add_contact("darkestsecret"))
        return 0;
    this->_index++;
    if (this->_total < 8)
        this->_total++;
    return 1;
}

void    Phonebook::search(void) const
{
    std::string buffer;

    for (int i = 0; i < this->_total; i++)
        this->_contacts[i].print_tab(i);
    std::cout << "Enter index: ";
    getline (std::cin, buffer);
    if (buffer[0] && !buffer[1] && std::isdigit(buffer[0]))
    {
        const int i2 = buffer[0] - '0';

        if (i2 <= this->_total && i2 > 0)
            Phonebook::_contacts[i2 - 1].print();
        else
            std::cout << "\033[31mInvalid index\033[0m" << std::endl;
    }
    else
        std::cout << "\033[31mInvalid index\033[0m" << std::endl;
}
