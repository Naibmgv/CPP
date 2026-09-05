#include "MutantStack.hpp"

int main() {
    std::cout << "=== Test avec MutantStack ===" << std::endl;
    {
        MutantStack<int> mstack;

        mstack.push(5);
        mstack.push(17);

        std::cout << "Top: " << mstack.top() << std::endl; // 17

        mstack.pop();

        std::cout << "Size: " << mstack.size() << std::endl; // 1

        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);

        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();

        ++it;
        --it;
        while (it != ite) {
            std::cout << *it << std::endl;
            ++it;
        }

        // Test du constructeur par copie de std::stack
        std::stack<int> s(mstack);
    }

    std::cout << "\n=== Test identique avec std::list ===" << std::endl;
    {
        std::list<int> mlist;

        mlist.push_back(5);
        mlist.push_back(17);

        std::cout << "Top (back): " << mlist.back() << std::endl; // 17

        mlist.pop_back();

        std::cout << "Size: " << mlist.size() << std::endl; // 1

        mlist.push_back(3);
        mlist.push_back(5);
        mlist.push_back(737);
        mlist.push_back(0);

        std::list<int>::iterator it = mlist.begin();
        std::list<int>::iterator ite = mlist.end();

        ++it;
        --it;
        while (it != ite) {
            std::cout << *it << std::endl;
            ++it;
        }
    }

    return 0;
}