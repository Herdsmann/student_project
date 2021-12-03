//
// Created by shepherd on 24.11.21.
//

#ifndef C3_GRAD_HPP
#define C3_GRAD_HPP

#include <c3/school/Core.hpp>

class Grad : public Core {
public:
    Grad() = default;
    explicit Grad(std::istream &in);

    std::istream &read(std::istream &in) override;
    double grade() const override;

protected:
    Grad *clone() const override;

private:
    double thesis{};
};


#endif //C3_GRAD_HPP
