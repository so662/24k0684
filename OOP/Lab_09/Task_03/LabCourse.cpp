#include <iostream>
using namespace std;
#include "LabCourse.h"
LabCourse::LabCourse(string CourseCode, int credits) : Course(CourseCode, credits) {}
void LabCourse::CalculateGrade() {
    cout << "Calculating grade for Lab Course: " << CourseCode << endl;
}
void LabCourse::DisplayCourseInfo() {
    cout << "Lab Course Code: " << CourseCode << endl;
    cout << "Credits: " << credits << endl;
}