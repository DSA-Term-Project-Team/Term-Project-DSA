#ifndef NODE_H
#define NODE_H

#include "courseinfo.h"
#include <string>

class node {
private:
    int rollNo;
    std::string name;
    float cgpa;
    int numOfCourses;
    courses* course;
    node* left;
    node* right;
    int height;

public:
    node(int rollNo, std::string name, float cgpa, int numOfCourses, courses* courseList);
    ~node();
    int getRollNo() const { return rollNo; }
    std::string getName() const { return name; }
    float getCgpa() const { return cgpa; }
    int getNumOfCourses() const { return numOfCourses; }
    courses* getCourse() const { return course; }
    node* getLeft() const { return left; }
    node* getRight() const { return right; }
    int getHeight() const { return height; }
    courses getCourse(int index) const;
    void setRollNo(int newRollNo) { rollNo = newRollNo; }
    void setName(std::string newName) { name = newName; }
    void setCgpa(float newCgpa) { cgpa = newCgpa; }
    void setNumOfCourses(int newNumOfCourses) { numOfCourses = newNumOfCourses; }
    void setLeft(node* newLeft) { left = newLeft; }
    void setRight(node* newRight) { right = newRight; }
    void setHeight(int newHeight) { height = newHeight; }
    void addCourse(int courseId, float marks);
    void deleteCourse(int courseId);
    void updateCourse(int courseId, float newMarks);
    void displayCourses() const;
    void setCourses(courses* newCourses, int newNumCourses);
};

#endif