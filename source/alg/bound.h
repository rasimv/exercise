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

template <typename I, typename T>
I lower_bound2(I b, I e, T v)
{
    decltype(std::distance(b, e)) c = std::distance(b, e), s;
    for (auto m{b}; c > 0; )
    {
        s = c / 2;
        std::advance(m, s);
        if (*m < v)
        {
            b = ++m;
            c -= s + 1;
        }
        else
        {
            m = b;
            c = s;
        }
    }
    return b;
}
