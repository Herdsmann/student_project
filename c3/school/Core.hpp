//
// Created by shepherd on 24.11.21.
//

#ifndef C3_CORE_HPP
#define C3_CORE_HPP

#include <c3/utils/Str.hpp>
#include <c3/utils/Vec.hpp>
#include <c3/school/Student.hpp>

class Core {
public:
    Core() = default;
    explicit Core(std::istream&in);
    virtual ~Core();

    virtual double grade() const;

    const Str &getName() const;
    double getMidterm() const;
    double getFinal() const;
    const Vec<double> &getHomeworks() const;

protected:
    Vec<double> homeworks;

    virtual std::istream &read(std::istream &in);
    virtual Core *clone() const;

    std::istream &read_common(std::istream &in);

private:
    Str name;
    double midterm{}, final{};

    friend class Student;
};

std::istream &read_hw(std::istream &in, Vec<double> &hws);

#endif //C3_CORE_HPP
