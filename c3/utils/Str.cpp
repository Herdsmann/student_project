//
// Created by shepherd on 22.11.21.
//

#include <c3/utils/Str.hpp>
#include <algorithm>
#include <cstring>

Str::Str(Str::size_type n, char c) : data(n, c) {
}

Str::Str(const char *str) {
    std::copy(str, str + strlen(str), std::back_inserter(data));
}

template<class Iterator>
Str::Str(Iterator b, Iterator e) {
    std::copy(b, e, std::back_inserter(data));
}

char &Str::operator[](Str::size_type i) {
    return data[i];
}

const char &Str::operator[](Str::size_type i) const {
    return data[i];
}

Str::size_type Str::size() const {
    return data.size();
}

std::ostream &operator<<(std::ostream &out, const Str &s) {
    for (char i : s) {
        out << i;
    }
    return out;
}

std::istream &operator>>(std::istream &in, Str &s) {
    s.data.clear();
    char c;
    while (in.get(c) && isspace(c));
    if (in) {
        do s.data.push_back(c);
        while (in.get(c) && !isspace(c));
        if (in) {
            in.unget();
        }
    }
    return in;
}

Str operator+(const Str &s, const Str &t) {
    Str r = s;
    r += t;
    return r;
}

bool operator<(const Str &lhs, const Str &rhs) {
    return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

bool operator>(const Str &lhs, const Str &rhs) {
    return std::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end());
}

bool operator<=(const Str &lhs, const Str &rhs) {
    return !operator>(lhs, rhs);
}

bool operator>=(const Str &lhs, const Str &rhs) {
    return !operator<(lhs, rhs);
}

bool operator==(const Str &lhs, const Str &rhs) {
    return lhs.size() == rhs.size() &&
           std::equal(lhs.begin(), lhs.end(), rhs.begin());
}

bool operator!=(const Str &lhs, const Str &rhs) {
    return !operator==(lhs, rhs);
}

Str &Str::operator+=(const Str &s) {
    std::copy(s.data.begin(), s.data.end(), std::back_inserter(data));
    return *this;
}

Str::iterator Str::begin() {
    return data.begin();
}

Str::const_iterator Str::begin() const {
    return data.begin();
}

Str::iterator Str::end() {
    return data.end();
}

Str::const_iterator Str::end() const {
    return data.end();
}
