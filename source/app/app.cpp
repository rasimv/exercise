#include <iostream>
#include <alg/gcd.h>
#include <alg/rotate.h>
#include <alg/bound.h>
#include <alg/qs.h>
#include <vector>
#include <cassert>

template <typename I>
void print(I b, I e, bool n = true)
{
    const auto l = std::distance(b, e);
    for (auto i(b); i != e; i++) std::cout << (i == b ? "" : " | ") << *i;
    if (n) std::cout << std::endl;
}

std::vector<int> random()
{
    std::vector<int> v(rand() % 1000);
    for (auto &q: v) q = rand();
    return v;
}

int main()
{
    const unsigned a = 224352, b = 2622792;
    std::cout << a << " | " << b << " | " << stein(a, b) << std::endl;

    std::cout << std::endl;

    std::vector<int> u = {1, 2, 3, 4, 5, 6};
    print(std::begin(u), std::end(u));

    std::cout << std::endl;

    rotate1(std::begin(u), std::end(u), 11);
    print(std::begin(u), std::end(u));
    rotate1(std::begin(u), std::end(u), -11);
    print(std::begin(u), std::end(u));

    std::cout << std::endl;

    rotate2(std::begin(u), std::end(u), 5);
    print(std::begin(u), std::end(u));
    rotate2(std::begin(u), std::end(u), -7);
    print(std::begin(u), std::end(u));

    std::cout << std::endl;

    rotate3(std::begin(u), std::begin(u) + 1, std::end(u));
    print(std::begin(u), std::end(u));
    rotate3(std::begin(u), std::begin(u) + 3, std::end(u));
    print(std::begin(u), std::end(u));
    rotate3(std::begin(u), std::begin(u) + 4, std::end(u));
    print(std::begin(u), std::end(u));
    rotate3(std::begin(u), std::begin(u) + 5, std::end(u));
    print(std::begin(u), std::end(u));

    //==========================================================================
    std::cout << std::endl;

    std::vector<int> v = { 1, 1, 3, 6, 6, 8, 11, 16, 16 };
    print(std::begin(v), std::end(v));

    for (int q = 0; q < 17; ++q)
    {
        const auto f = ::lower_bound(std::begin(v), std::end(v), q);
        std::cout << q << " | " << f - std::begin(v) << " | ";
        if (f == std::end(v)) std::cout << "-"; else std::cout << *f;
        std::cout << std::endl;
    }

    //==========================================================================
    std::cout << std::endl;

    while (true)
    {
        v = random();
        auto w(v);
        std::cout << v.size() << std::endl;
        std::sort(std::begin(v), std::end(v));
        qs(std::begin(w), std::end(w));
        assert(v == w);
    }

    return 0;
}
