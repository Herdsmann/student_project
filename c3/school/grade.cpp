//
// Created by shepherd on 21.11.21.
//

#include <stdexcept>
#include <c3/school/grade.hpp>
#include <c3/utils/median.hpp>
#include <c3/school/Core.hpp>

double grade(double mid, double fin, double median_of_hws) {
    return 0.2 * mid + 0.4 * fin + 0.4 * median_of_hws;
}

double grade(double mid, double fin, const Vec<double> &hws) {
    if(hws.empty()){
        throw std::domain_error("student has done no homework");
    }
    return grade(mid, fin, median(hws));
}

//double grade(const Student &s) {
//    return grade(s.midterm, s.final, s.homework);
//}

