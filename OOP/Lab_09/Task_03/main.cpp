#include <iostream>
using namespace std;
#include "LectureCourse.h"
#include "LabCourse.h"

int main() {

    LectureCourse course1("CS101", 3);
    LabCourse course2("CS102", 4);
    course1.CalculateGrade();
    course1.DisplayCourseInfo();
    course2.CalculateGrade();
    course2.DisplayCourseInfo();
    cout << endl;
    return 0;
}
