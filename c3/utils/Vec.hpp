//
// Created by shepherd on 21.11.21.
//

#ifndef C1_VEC_HPP
#define C1_VEC_HPP

#include <memory>
#include <algorithm>

template<class T>
class Vec {
public:
    typedef T* iterator;
    typedef const T* const_iterator;
    typedef typename std::size_t size_type;
    typedef T value_type;

    Vec();
    explicit Vec(size_type n, const T &val = T());
    Vec(const Vec &v);
    ~Vec();

    Vec &operator=(const Vec &v);
    T &operator[](size_type i);
    const T &operator[](size_type i) const;

    size_type size() const;
    iterator begin();
    const_iterator begin() const;
    iterator end();
    const_iterator end() const;
    void clear();
    bool empty() const;
    void push_back(const T &val);

private:
    iterator data;
    iterator avail;
    iterator limit;
    std::allocator<T> alloc;

    void create();
    void create(size_type n, const T &val);
    void create(const_iterator begin, const_iterator end);
    void uncreate();
    void grow();
    void unchecked_append(const T &val);
};

template<class T>
void Vec<T>::create() {
    data = avail = limit = 0;
}

template<class T>
void Vec<T>::create(Vec::size_type n, const T &val) {
    data = alloc.allocate(n);
    limit = avail = data + n;
    std::uninitialized_fill(data, limit, val);
}

template<class T>
void Vec<T>::create(Vec::const_iterator begin, Vec::const_iterator end) {
    data = alloc.allocate(end - begin);
    limit = avail = std::uninitialized_copy(begin, end, data);
}

template<class T>
void Vec<T>::uncreate() {
    if(data){
        iterator i = avail;
        while(i != data){
            alloc.destroy(--i);
        }
        alloc.deallocate(data, limit - data);
    }
    data = limit = avail = 0;
}

template<class T>
void Vec<T>::grow() {
    size_type new_size = std::max(2 * (limit - data), ptrdiff_t(1));
    iterator new_data = alloc.allocate(new_size);
    iterator new_avail = std::uninitialized_copy(data, avail, new_data);

    uncreate();

    data = new_data;
    avail = new_avail;
    limit = data + new_size;
}

template<class T>
void Vec<T>::unchecked_append(const T &val) {
    alloc.construct(avail++, val);
}

template<class T>
Vec<T>::Vec() {
    create();
}

template<class T>
Vec<T>::Vec(Vec::size_type n, const T &val) {
    create(n, val);
}

template<class T>
typename Vec<T>::size_type Vec<T>::size() const{
    return avail - data;
}

template<class T>
typename Vec<T>::iterator Vec<T>::begin() {
    return data;
}

template<class T>
typename Vec<T>::const_iterator Vec<T>::begin() const {
    return data;
}

template<class T>
typename Vec<T>::iterator Vec<T>::end() {
    return avail;
}

template<class T>
typename Vec<T>::const_iterator Vec<T>::end() const {
    return avail;
}

template<class T>
Vec<T>::Vec(const Vec &v) {
    create(v.begin(), v.end());
}

template<class T>
Vec<T> &Vec<T>::operator=(const Vec &v) {
     if(&v != this){
         uncreate();
         create(v.begin(), v.end());
     }
     return *this;
}

template<class T>
Vec<T>::~Vec() {
    uncreate();
}

template<class T>
T &Vec<T>::operator[](Vec::size_type i) {
    return data[i];
}

template<class T>
const T &Vec<T>::operator[](Vec::size_type i) const {
    return data[i];
}

template<class T>
void Vec<T>::clear() {
    uncreate();
}

template<class T>
bool Vec<T>::empty() const {
    return data == avail;
}

template<class T>
void Vec<T>::push_back(const T &val) {
    if(avail == limit){
        grow();
    }
    unchecked_append(val);
}


#endif //C1_VEC_HPP
