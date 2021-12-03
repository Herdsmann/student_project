#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <c3/school/Core.hpp>
#include <c3/school/Student.hpp>

int main() {
    Vec<Student> students;
    Student record;
    Str::size_type maxlen = 0;

    while (record.read(std::cin)) {
        maxlen = std::max(maxlen, record.getName().size());
        students.push_back(record);
    }

    std::sort(students.begin(), students.end(), Student::compare);
    for (auto const &s: students) {
        std::cout << s.getName()
                  << Str(maxlen + 1 - s.getName().size(), ' ');
        try {
            double final_grade = s.grade();
            std::cout << std::setprecision(3) << final_grade << std::endl;
        } catch (std::domain_error &e) {
            std::cout << e.what() << std::endl;
        }
    }
}