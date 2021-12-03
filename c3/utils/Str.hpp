//
// Created by shepherd on 22.11.21.
//

#ifndef C2_STR_HPP
#define C2_STR_HPP

#include <c3/utils/Vec.hpp>
#include <iostream>

class Str {
public:
    typedef Vec<char>::size_type size_type;
    typedef char *iterator;
    typedef const char *const_iterator;

    Str() = default;
    Str(size_type n, char c);
    Str(const char *str);
    template<class Iterator>Str(Iterator b, Iterator e);

    char &operator[](size_type i);
    const char &operator[](size_type i) const;
    Str &operator+=(const Str&s);

    size_type size() const;
    iterator begin();
    const_iterator begin() const;
    iterator end();
    const_iterator end() const;

private:
    Vec<char> data;
    friend std::istream &operator>>(std::istream &in, Str &s);
};

std::istream &operator>>(std::istream &in, Str &s);
std::ostream &operator<<(std::ostream &out, const Str &s);
Str operator+(const Str&s, const Str&t);
bool operator<(const Str &lhs, const Str &rhs);
bool operator>(const Str &lhs, const Str &rhs);
bool operator<=(const Str &lhs, const Str &rhs);
bool operator>=(const Str &lhs, const Str &rhs);
bool operator==(const Str&lhs, const Str&rhs);
bool operator!=(const Str&lhs, const Str&rhs);

#endif //C2_STR_HPP
