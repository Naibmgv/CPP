#include "contact.hpp"
#include "phonebook.hpp"

int main(void)
{
    std::string buffer;
    Phonebook phonebook(0);

    while (1)
    {
        std::cout << "Enter command: ";
        if (!std::getline(std::cin, buffer))
            break;
        if (buffer == "EXIT")
            break;
        else if (buffer == "ADD")
        {
            if (!phonebook.add())
                break;
        }
        else if (buffer == "SEARCH")
            phonebook.search();
        else if (buffer[0])
            std::cout << "\033[31mCommand not found\033[0m" << std::endl;
    }
}
