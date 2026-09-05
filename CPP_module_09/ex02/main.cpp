#include "PmergeMe.hpp"

bool parsing(char **av)
{
    for (int i = 1; av[i]; i++)
    {
        if (!av[i][0]) 
            return false;
        for (int j = 0; av[i][j]; j++) 
            if (!isdigit(av[i][j]))
                return false;
    }
    long tmp = 0;
    char *ptr = NULL;
    for (int i = 1; av[i]; i++)
    {
        tmp = strtol(av[i], &ptr, 10);
        if (*ptr != '\0')
            return false;
        if (tmp < 0 || tmp > INT_MAX) 
            return false;
    }
    return true;
}

int main(int ac, char **av)
{
    if (ac < 2) {
        std::cerr << "Arguments missing\n";
        return 1;
    }
    if (!parsing(av)) {
        std::cerr << "Error\n";
        return 1;
    }

    PmergeMe test(av + 1);

    // 1. Affichage "Before"
    std::cout << "Before: ";
    for (int i = 1; av[i]; i++)
        std::cout << av[i] << " ";
    std::cout << "\n";

    // 2. Chronométrage std::vector
    clock_t start_vec = clock();
    test.mergeInsertSort(test._vec);
    clock_t end_vec = clock();
    double time_vec = static_cast<double>(end_vec - start_vec) / CLOCKS_PER_SEC * 1000000.0;

    // 3. Chronométrage std::deque
    clock_t start_deq = clock();
    test.mergeInsertSort(test._deq);
    clock_t end_deq = clock();
    double time_deq = static_cast<double>(end_deq - start_deq) / CLOCKS_PER_SEC * 1000000.0;

    // 4. Affichage "After"
    std::cout << "After:  ";
    for (std::size_t i = 0; i < test._vec.size(); i++)
        std::cout << test._vec[i] << " ";
    std::cout << "\n";

    // 5. Affichage des temps avec std::fixed et std::setprecision
    std::cout << "Time to process a range of " << test._vec.size() 
              << " elements with std::vector : " 
              << std::fixed << std::setprecision(5) << time_vec << " us\n";

    std::cout << "Time to process a range of " << test._deq.size() 
              << " elements with std::deque  : " 
              << std::fixed << std::setprecision(5) << time_deq << " us\n";

    return 0;
}