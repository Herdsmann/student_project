//
// Created by shepherd on 24.11.21.
//

#ifndef C3_STUDENT_HPP
#define C3_STUDENT_HPP

#include <c3/school/Grad.hpp>

class Student {
public:
    Student() = default;
    explicit Student(std::istream &in);
    Student(const Student &s);
    ~Student();

    Student &operator=(const Student &x);

    std::istream &read(std::istream&in);
    Str getName() const;
    double grade() const;

    static bool compare(const Student &x, const Student &y);

private:
    Core *cp{};
};


#endif //C3_STUDENT_HPP
