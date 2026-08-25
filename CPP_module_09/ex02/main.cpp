#include "PmergeMe.hpp"

bool parsing(const char **av)
{
    for (int i = 0; av[i]; i++) 
    {
        if (!av[i][0]) return false;
        for (int j = 0; av[i][j]; j++) 
            if (!isdigit(av[i][j])) return false;
    }
    long tmp = 0;
    char *ptr = NULL;
    for (int i = 0; av[i]; i++)
    {
        tmp = strtol(av[i], &ptr, 10);
        if (*ptr != '\0') return false;
        if (tmp < 0 || tmp > INT_MAX) return false;
    }
    return true;
}

int main(int ac, char **av)
{
    if (ac < 3) {
        std::cerr << "Arguments missing\n";
        return 1;
    }
    if (!parsing(av)) {
        std::cerr << "Error\n";
        return 1;
    }
}
