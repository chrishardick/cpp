#include <iostream>
#include <string>
#include <vector>

#include <ch_vector.h>
#include <ch_combo.h>


int main (int argc, const char* argv[])
{
    std::vector<std::vector<int>> results;

    std::vector<int> v { 1, 2, 3, 4, 5 };

    std::cout << "input=" << v << std::endl;

    results = combinations (v, 2);

    std::cout << "combinations of 2" << std::endl;

    for (auto i = results.begin(); i != results.end(); i++)
    {
        std::vector<int>& vv = *i;

        std::cout << vv << std::endl;
    }

    return 0;
}

