#include "../Headers/courseinfo.h"
#include <iostream>
courses::courses(int courseId, float marks) : courseId(courseId), marks(marks) {}
int courses::getCourseId() {
    return courseId;
}

float courses::getMarks() {
    return marks;
}

void courses::setCourseId(int newCourseId) {
    if (newCourseId > 0) {
        courseId = newCourseId;
    }
    else {
        std::cerr << "Invalid course ID. Must be positive." << std::endl;
    }
}

void courses::setMarks(float newMarks) {
    if (newMarks >= 0.0f && newMarks <= 100.0f) {
        marks = newMarks;
    }
    else {
        std::cerr << "Invalid marks. Must be between 0.0 and 100.0." << std::endl;
    }
}