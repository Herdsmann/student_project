//
// Created by shepherd on 21.11.21.
//

#ifndef C2_GRADE_HPP
#define C2_GRADE_HPP

#include <c3/utils/Vec.hpp>
#include <c3/school/Core.hpp>

double grade(double mid, double fin, double median_of_hws);
double grade(double mid, double fin, const Vec<double> &hws);

#endif //C2_GRADE_HPP
