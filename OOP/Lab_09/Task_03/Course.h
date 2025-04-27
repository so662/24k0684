#pragma once
#include "iostream"
using namespace std;
class Course{
    protected :
    string CourseCode;
    int credits;
    public:
    Course(string CourseCode,int credtits):CourseCode(CourseCode),credits(credits){}
    virtual void CalculateGrade() = 0;
    virtual void DisplayCourseInfo() = 0;
};