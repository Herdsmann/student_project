//
// Created by shepherd on 24.11.21.
//

#include <iostream>
#include <c3/school/Core.hpp>
#include <c3/school/grade.hpp>

const Str &Core::getName() const {
    return name;
}

double Core::getMidterm() const {
    return midterm;
}

double Core::getFinal() const {
    return final;
}

const Vec<double> &Core::getHomeworks() const {
    return homeworks;
}

std::istream &Core::read(std::istream &in) {
    read_common(in);
    std::cout << "enter hws: ";
    read_hw(in, homeworks);
    return in;
}

Core::Core(std::istream &in) {
    read(in);
}

std::istream &Core::read_common(std::istream &in) {
    std::cout << "enter name, midterm and final: ";
    in >> name >> midterm >> final;
    return in;
}

double Core::grade() const {
    return ::grade(midterm, final, homeworks);
}

Core::~Core() = default;

Core *Core::clone() const {
    return new Core(*this);
}

std::istream &read_hw(std::istream &in, Vec<double> &hws) {
    if (in) {
        hws.clear();
        double x;
        while (in >> x) {
            hws.push_back(x);
        }
        in.clear();
    }
    return in;
}

