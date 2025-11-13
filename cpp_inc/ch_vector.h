#ifndef CH_VECTOR_H
#define CH_VECTOR_H

#include <ostream>
#include <vector>

template <typename T>
std::ostream& operator<< (std::ostream& os, const std::vector<T>& v)
{
    for (auto i = v.begin(); i != v.end(); i++)
    {
        if (i != v.begin())
            os << ",";

        os << *i;
    }

    return os;
}

#endif // CH_VECTOR_H
