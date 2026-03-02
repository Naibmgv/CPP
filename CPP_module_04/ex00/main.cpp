#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    std::cout << "========================================" << std::endl;
    std::cout << "TEST 1: Basic polymorphism (from subject)" << std::endl;
    std::cout << "========================================" << std::endl;
    
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    std::cout << "\nTypes:" << std::endl;
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    
    std::cout << "\nSounds:" << std::endl;
    i->makeSound(); // Will output the cat sound!
    j->makeSound(); // Will output the dog sound!
    meta->makeSound();
    
    std::cout << "\nDeleting animals:" << std::endl;
    delete i;
    delete j;
    delete meta;

    std::cout << "\n========================================" << std::endl;
    std::cout << "TEST 2: Wrong classes (NO polymorphism)" << std::endl;
    std::cout << "========================================" << std::endl;
    
    const WrongAnimal* wrong_meta = new WrongAnimal();
    const WrongAnimal* wrong_cat = new WrongCat();
    
    std::cout << "\nTypes:" << std::endl;
    std::cout << wrong_cat->getType() << std::endl;
    
    std::cout << "\nSounds (should be WrongAnimal sound!):" << std::endl;
    wrong_cat->makeSound(); // ❌ Will output WrongAnimal sound (NOT polymorphic!)
    wrong_meta->makeSound();
    
    std::cout << "\nDeleting wrong animals:" << std::endl;
    delete wrong_cat;
    delete wrong_meta;

    std::cout << "\n========================================" << std::endl;
    std::cout << "TEST 3: Direct WrongCat instance" << std::endl;
    std::cout << "========================================" << std::endl;
    
    WrongCat direct_wrong;
    std::cout << "\nSound (should be WrongCat sound!):" << std::endl;
    direct_wrong.makeSound(); // ✅ Will output WrongCat sound

    std::cout << "\n========================================" << std::endl;
    std::cout << "TEST 4: Copy constructor test" << std::endl;
    std::cout << "========================================" << std::endl;
    
    Dog original_dog;
    std::cout << "\nCreating copy:" << std::endl;
    Dog copy_dog(original_dog);
    
    std::cout << "\nBoth should be type 'Dog':" << std::endl;
    std::cout << "Original: " << original_dog.getType() << std::endl;
    std::cout << "Copy: " << copy_dog.getType() << std::endl;
    
    std::cout << "\nBoth should make dog sound:" << std::endl;
    original_dog.makeSound();
    copy_dog.makeSound();

    std::cout << "\n========================================" << std::endl;
    std::cout << "TEST 5: Assignment operator test" << std::endl;
    std::cout << "========================================" << std::endl;
    
    Cat cat1;
    Cat cat2;
    
    std::cout << "\nAssigning cat1 to cat2:" << std::endl;
    cat2 = cat1;
    
    std::cout << "\nBoth should be type 'Cat':" << std::endl;
    std::cout << "Cat1: " << cat1.getType() << std::endl;
    std::cout << "Cat2: " << cat2.getType() << std::endl;
    
    std::cout << "\nBoth should make cat sound:" << std::endl;
    cat1.makeSound();
    cat2.makeSound();

    std::cout << "\n========================================" << std::endl;
    std::cout << "TEST 6: Array of animals (polymorphism)" << std::endl;
    std::cout << "========================================" << std::endl;
    
    const Animal* animals[4];
    animals[0] = new Dog();
    animals[1] = new Cat();
    animals[2] = new Dog();
    animals[3] = new Cat();
    
    std::cout << "\nAll animals make their sound:" << std::endl;
    for (int idx = 0; idx < 4; idx++)
    {
        std::cout << "Animal " << idx << " (" << animals[idx]->getType() << "): ";
        animals[idx]->makeSound();
    }
    
    std::cout << "\nDeleting array:" << std::endl;
    for (int idx = 0; idx < 4; idx++)
        delete animals[idx];

    std::cout << "\n========================================" << std::endl;
    std::cout << "TEST 7: Stack vs Heap allocation" << std::endl;
    std::cout << "========================================" << std::endl;
    
    std::cout << "\nCreating on stack:" << std::endl;
    Dog stack_dog;
    Cat stack_cat;
    
    std::cout << "\nMaking sounds:" << std::endl;
    stack_dog.makeSound();
    stack_cat.makeSound();
    
    std::cout << "\nEnd of scope (automatic destruction):" << std::endl;
}