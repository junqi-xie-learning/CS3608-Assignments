#pragma once

#include <iostream>
#include <string>
#include <utility>
#include <algorithm>
#include <vector>
#include <queue>
#include <random>
#include <limits>
using namespace std;

template <typename T>
istream &operator>>(istream &is, vector<T> &v)
{
    char ch{};
    is >> ch;

    v.clear();
    is >> ch;
    if (ch == ']')
        return is;
    is.putback(ch);

    T t{};
    while (ch != ']')
    {
        T t{};
        is >> t >> ch;
        v.push_back(t);
    }

    return is;
}

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
    os << '[';
    for (int i = 0; i < v.size(); ++i)
    {
        os << v[i];
        if (i + 1 != v.size())
            os << ',';
    }
    os << ']';

    return os;
}
