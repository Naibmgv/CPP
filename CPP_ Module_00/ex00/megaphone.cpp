#include <iostream>
#include <cctype>

int main(int ac, char **av)
{
    if (ac < 2)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
    {
        for(int i = 1; av[i]; i++)
        {
            for(int j = 0; av[i][j]; j++)
            {
                if (av[i][j] >= 97 && av[i][j] <= 122)
                    std::cout << (char)std::toupper(av[i][j]);
                else
                    std::cout << av[i][j];
            }
        }
        std::cout << "\n";
    }
}
