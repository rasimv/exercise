#pragma once

template <typename T>
T stein(T a, T b)
{
    // https://en.wikipedia.org/wiki/Binary_GCD_algorithm
    for (T r = 0; ; )
    {
        if (a == 0) return b << r;
        if (b == 0 || a == b) return a << r;

        if ((1 & a) == 0)
        {
            a >>= 1;
            if ((1 & b) == 0) { ++r; b >>= 1; }
            continue;
        }

        if ((1 & b) == 0) { b >>= 1; continue; }

        if (a < b) b -= a; else a -= b;
    }
}
