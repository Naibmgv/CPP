#include "Zombie.hpp"

int main(void)
{
    int N = 3;

    Zombie *horde = zombieHorde(3, "Rick");

    for(int i = 0; i < N; i++)
        horde[i].announce();
    delete[] horde;
}
