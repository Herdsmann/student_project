//
// Created by shepherd on 21.11.21.
//

#ifndef C1_MEDIAN_HPP
#define C1_MEDIAN_HPP

#include <stdexcept>
#include <algorithm>
#include <c3/utils/Vec.hpp>

template<class T>
T median(Vec<T> v) {
    typedef typename Vec<T>::size_type vec_sz;
    vec_sz size = v.size();
    if (size == 0) {
        throw std::domain_error("median of an empty Vec");
    }
    std::sort(v.begin(), v.end());
    vec_sz mid = size / 2;
    return size % 2 == 0 ? (v[mid] + v[mid - 1]) / 2 : v[mid];
}

#endif //C1_MEDIAN_HPP
