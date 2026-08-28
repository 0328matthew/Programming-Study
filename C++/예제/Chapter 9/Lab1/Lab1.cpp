#include "course.h"
#include <iomanip>
#include <cmath>

Course::Course(int num, const char* ifn) : numOfStds(num), inputFileName(ifn); {
    inputFile.open(inputFileName);
    students = new Student[numOfStds];
    getInput();
    setGrades();
    setAverage();
    setDeviation();
    printResult();

    Course::~Course() {
        
    }






}