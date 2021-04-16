#pragma once

#include <algorithm>

template <typename I>
void qs(I b, I e)
{
    if (b == e || ++decltype(b)(b) == e) return;
    auto m(b);
    const auto d = std::distance(b, e);
    std::advance(m, d / 2);
    const auto p(*m);
    for (auto i(b), j(e); ; )
    {
        while (*i < p) ++i;
        while (p < *(--j));
        if (i == j || i == ++decltype(j)(j))
        {
            qs(b, i);
            qs(i, e);
            return;
        }
        std::iter_swap(i, j);
        ++i;
    }
}
