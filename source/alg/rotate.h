#pragma once

#include "reverse.h"
#include "gcd.h"

// https://stackoverflow.com/a/876410/13806653
// m - where the first element in the original range will be in the rotated range
template <typename T>
void rotate1(T b, T m, T e)
{
    ::reverse(b, e);
    ::reverse(b, m);
    ::reverse(m, e);
}

// n - rotation steps (positive - rotate right)
template <typename T>
void rotate1(T b, T e, decltype(e - b) n)
{
    const auto s = std::distance(b, e);
    const auto o = n < 0? n % s + s: n % s;
    auto m(b);
    std::advance(m, o);
    rotate1(b, m, e);
}

// https://stackoverflow.com/a/32698823/13806653
// n - rotation steps (positive - rotate left)
template <typename T>
void rotate2(T b, T e, decltype(e - b) n)
{
    const auto s = std::distance(b, e);
    const auto o = n < 0? n % s + s: n % s;
    if (o == 0) return;
    const auto d = stein(s, o);
    auto u(b);
    for (typename std::remove_const<decltype(d)>::type i = 0; i < d; i++)
    {
        auto v(u++);
        auto q(std::move(*v));
        for (auto j = i; ; )
        {
            auto w(v);
            const auto k = s - j;
            if (o < k)
            {
                j += o;
                if (i == j) { *v = std::move(q); break; }
                std::advance(w, o);
            }
            else
            {
                j = o - k;
                if (i == j) { *v = std::move(q); break; }
                w = b;
                std::advance(w, j);
            }
            *v = std::move(*w);
            v = w;
        }
    }
}
