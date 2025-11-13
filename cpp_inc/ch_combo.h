#ifndef CH_COMBO_H
#define CH_COMBO_H

#include <iostream>
#include <vector>

#include <ch_vector.h>

// combinations - k at a time

template <typename T>
std::vector<std::vector<T>> combinations (const std::vector<T>& v, int k)
{
    std::vector<std::vector<T>> results;

    if (v.size() > 1<<(sizeof(unsigned long long)-1))
    {
        std::cerr << "too large" << std::endl;
        return results;
    }

    unsigned long long num_combos = 1<<v.size();


    for (unsigned long long i = 0; i < num_combos; i++)             // bitmap
    {
        unsigned long long cnt = 0;

        for (unsigned long long j = 0; j < v.size(); j++)           // bit
        {
            if (i & 1<<j)
            {
                cnt++;
            }
        }

        if (cnt == k)
        {
            std::vector<T> tmp;

            for (unsigned long long j = 0; j < v.size(); j++)       // bit
                if (i & 1<<j)
                    tmp.push_back(v[j]);

            results.push_back(tmp);
        }
    }

    return results;
}

#endif // CH_COMBO_H
