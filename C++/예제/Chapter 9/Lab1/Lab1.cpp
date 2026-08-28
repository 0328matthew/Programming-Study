#include "course.h"
#include <iomanip>
#include <cmath>

Course::Course(int num, const char* ifn) : numOfStds(num), inputFileName(ifn) {
    inputFile.open(inputFileName);
    students = new Student[numOfStds];
    getInput();
    setGrades();
    setAverage();
    setDeviations();
    printResult();
}

Course::~Course() {
    delete[] students;
    inputFile.close();
}

void Course::getInput() {
    for(int i = 0; i < numOfStds; i++) {
        inputFile >> students[i].id;
        inputFile >> students[i].score;
    }
}

void Course::setGrades() {
    char charGrades[] = {'F', 'F', 'F', 'F', 'F', 'F', 'D', 'C', 'B', 'A', 'A'};
    for(int i = 0; i < numOfStds; i++) {
        int index = students[i].score / 10;
        students[i].grade = charGrades[index];
    }
}

void Course::setAverage() {
    int sum = 0;
    for(int i = 0; i < numOfStds; i++) {
        sum += students[i].score;
    }
    averageScore = static_cast<double>(sum) / numOfStds;
}

void Course::setDeviations() {
    standardDeviation = 0.0;
    for(int i = 0; i < numOfStds; i++) {
        students[i].deviaiton = student[i].score - averageScore;
        s
    }
}