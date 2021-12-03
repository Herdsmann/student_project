//
// Created by shepherd on 24.11.21.
//

#include <c3/school/Student.hpp>
#include <c3/school/Grad.hpp>

Student::Student(std::istream &in) {
    read(in);
}

Student::Student(const Student &s) {
    if (s.cp) {
        cp = s.cp->clone();
    }
}

std::istream &Student::read(std::istream &in) {
    delete cp;
    char input;
    std::cout << "what type of student are you? Core[C] or Graduate[G]: ";
    in >> input;
    if (input == 'C') {
        cp = new Core(in);
    } else {
        cp = new Grad(in);
    }
    return in;
}

Str Student::getName() const {
    return cp->getName();
}

double Student::grade() const {
    if (cp) {
        return cp->grade();
    } else {
        throw std::runtime_error("uninitialized Student");
    }
}

bool Student::compare(const Student &x, const Student &y) {
    return x.getName() < y.getName();
}

Student::~Student() {
    delete cp;
}

Student &Student::operator=(const Student &x) {
    if (&x != this) {
        delete cp;
        if (x.cp) {
            cp = x.cp->clone();
        } else {
            cp = nullptr;
        }
    }
    return *this;
}
