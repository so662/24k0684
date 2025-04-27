#include <iostream>
using namespace std;
#include "LectureCourse.h"
LectureCourse::LectureCourse(string CourseCode, int credits) : Course(CourseCode, credits) {}
void LectureCourse::CalculateGrade() {
    cout << "Calculating grade for Lecture Course: " << CourseCode << endl;
}
void LectureCourse::DisplayCourseInfo() {
    cout << "Lecture Course Code: " << CourseCode << endl;
    cout << "Credits: " << credits << endl;
}