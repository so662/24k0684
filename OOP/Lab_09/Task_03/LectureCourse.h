#pragma once
#include <iostream>
using namespace std;
#include "Course.h"
class LectureCourse : public Course{
    public:
    LectureCourse(string CourseCode,int credits);
    void CalculateGrade() ;
    void DisplayCourseInfo();
};