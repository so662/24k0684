#pragma once
#include <iostream>
using namespace std;
#include "Course.h"
class LabCourse : public Course{
    public:
    LabCourse(string CourseCode,int credits);
    void CalculateGrade();
    void DisplayCourseInfo();
};