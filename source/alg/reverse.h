#pragma once

#include <algorithm>

template <typename T>
void reverse(T b, T e)
{
    while (b != e && b != --e) std::iter_swap(b++, e);
}
