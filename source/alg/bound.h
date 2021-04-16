#pragma once

#include <algorithm>

template <typename I, typename T>
I lower_bound(I b, I e, T v)
{
    while (b < e)
    {
        const auto d = std::distance(b, e),
                    m = d / 2;
        auto q(b);
        std::advance(q, m);
        if (*q < v) b = ++q;
        else e = q;
    }
    return e;
}
