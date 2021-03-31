#include <iostream>
#include <alg/gcd.h>
#include <alg/rotate.h>

template <typename I>
void print(I b, I e, bool n = true)
{
    const auto l = std::distance(b, e);
    for (auto i(b); i != e; i++) std::cout << (i == b ? "" : " | ") << *i;
    if (n) std::cout << std::endl;
}

int main()
{
    const unsigned a = 224352, b = 2622792;
    std::cout << a << " | " << b << " | " << stein(a, b) << std::endl;

    std::cout << std::endl;

    int u[] = {1, 2, 3, 4, 5, 6};
    print(std::begin(u), std::end(u));

    rotate(std::begin(u), std::end(u), 4);
    print(std::begin(u), std::end(u));
    rotate(std::begin(u), std::end(u), -11);
    print(std::begin(u), std::end(u));

    return 0;
}
