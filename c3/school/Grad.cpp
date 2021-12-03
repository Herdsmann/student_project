//
// Created by shepherd on 24.11.21.
//

#include <c3/school/Grad.hpp>
#include <algorithm>

Grad::Grad(std::istream &in) : Core(in) {
    read(in);
}

std::istream &Grad::read(std::istream &in) {
    read_common(in);
    std::cout << "enter thesis: ";
    in >> thesis;
    read_hw(in, homeworks);
    return in;
}

double Grad::grade() const {
    return std::min(Core::grade(), thesis) ;
}

Grad *Grad::clone() const {
    return new Grad(*this);
}

