#pragma once

#include "reverse.h"

// m - where the first element in the original range will be in the rotated range
template <typename T>
void rotate(T b, T m, T e)
{
    reverse(b, e);
    reverse(b, m);
    reverse(m, e);
}

// n - right rotation steps
template <typename T>
void rotate(T b, T e, decltype(e - b) n)
{
    const auto s = std::distance(b, e);
    auto o = n % s;
    if (o < 0) o += s;
    decltype(b) m(b);
    std::advance(m, o);
    rotate(b, m, e);
}
