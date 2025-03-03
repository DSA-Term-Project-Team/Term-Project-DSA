#include "../Headers/node.h"
#include <string>
#include <iostream>

node::node(int rollNo, std::string name, float cgpa, int numOfCourses, courses* courseList) {
    this->rollNo = rollNo;
    this->name = name;
    this->cgpa = cgpa;
    this->numOfCourses = numOfCourses;
    this->course = (numOfCourses > 0) ? new courses[numOfCourses] : nullptr;
    for (int i = 0; i < numOfCourses; i++) {
        this->course[i] = courseList[i];
    }
    this->left = nullptr;
    this->right = nullptr;
    this->height = 1;
}

node::~node() {
    delete[] course;
}

courses node::getCourse(int index) const {
    if (index >= 0 && index < numOfCourses) {
        return course[index];
    }
    return courses(0, 0.0);
}

void node::addCourse(int courseId, float marks) {
    courses* newCourses = new courses[numOfCourses + 1];
    for (int i = 0; i < numOfCourses; i++) {
        newCourses[i] = course[i];
    }
    newCourses[numOfCourses].setCourseId(courseId);
    newCourses[numOfCourses].setMarks(marks);
    delete[] course;
    course = newCourses;
    numOfCourses++;
}

void node::deleteCourse(int courseId) {
    int index = -1;
    for (int i = 0; i < numOfCourses; i++) {
        if (course[i].getCourseId() == courseId) {
            index = i;
            break;
        }
    }
    if (index == -1) return;
    courses* newCourses = (numOfCourses > 1) ? new courses[numOfCourses - 1] : nullptr;
    for (int i = 0, j = 0; i < numOfCourses; i++) {
        if (i != index) {
            newCourses[j] = course[i];
            j++;
        }
    }
    delete[] course;
    course = newCourses;
    numOfCourses--;
}

void node::updateCourse(int courseId, float newMarks) {
    for (int i = 0; i < numOfCourses; i++) {
        if (course[i].getCourseId() == courseId) {
            course[i].setMarks(newMarks);
            return;
        }
    }
}

void node::displayCourses() const {
    for (int i = 0; i < numOfCourses; i++) {
        std::cout << course[i].getCourseId() << ": " << course[i].getMarks() << std::endl;
    }
}

void node::setCourses(courses* newCourses, int newNumCourses) {
    delete[] course;
    numOfCourses = newNumCourses;
    course = (newNumCourses > 0) ? new courses[newNumCourses] : nullptr;
    for (int i = 0; i < newNumCourses; i++) {
        course[i] = newCourses[i];
    }
}