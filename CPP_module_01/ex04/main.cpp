#include <iostream>
#include <fstream>
#include <string>

int main(int ac, char **av)
{
    if (ac != 4 || !av[1][0] || !av[2][0] || !av[3][0]) {
        std::cout << "invalid args" << std::endl;
        return 1;
    }
    std::ifstream in_file(av[1]);
    if (!in_file.is_open()) {
        std::cout << "File opening failed" << std::endl;
        return 1;
    }
    std::string temp = av[1];
    temp.append(".replace");
    std::ofstream out_file(temp.c_str());
    if (!out_file.is_open()) {
        std::cout << "File creation failed" << std::endl;
        return 1;
    }
    std::string tmp;
    std::string copy;
    while (getline (in_file, tmp))
        copy.append(tmp + '\n');
    if (copy.empty()) {
        std::cout << "'" << av[1] << "'" << " is empty" << std::endl;
        return 1;
    }
    copy.erase(copy.length() - 1, 1);
    std::string::size_type j = 0;
    std::string s1 = av[2];
    std::string s2 = av[3];
    int s1_len = s1.length();
    while ((j = copy.find(s1, j)) != std::string::npos)
    {
        copy.erase(j, s1_len);
        copy.insert(j, s2);
        j += s2.length();
    }
    out_file << copy;
    out_file.close();
    in_file.close();
}