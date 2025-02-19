#ifndef NODE_H
#define NODE_H
#include "courseinfo.h"
/*
* Node class for the AVL Tree
* it contains the student information
* which is roll number, name, cgpa, number of courses and the courses
* it also contains the right and left pointers
* it also contains the methods to add, delete, update and display courses
*/
#include <string>
class node {
private:
	int rollNo;
	std::string name;
	node* left;
	node* right;
	float cgpa;
	int numOfCourses;
	int height;
public:
	courses* course;
	courses getCourse(int index);
	node(int rollNo, std::string name, float cgpa, int numOfCourses, courses* course);
	int getRollNo();
	int getNumOfCourses();
	std::string getName();
	float getCgpa();
	void setRollNo(int newRollNo);
	void setName(std::string newName);
	void setCgpa(float newCgpa);
	void addCourse(int courseId, float marks);
	void deleteCourse(int courseId);
	void updateCourse(int courseId, float newMarks);
	void displayCourses();
	node* getLeft();
	node* getRight();
	courses* getCourse();
	void setLeft(node* newLeft);
	void setRight(node* newRight);
	void setNumOfCourses(int newNumOfCourses);
	int getHeight();
	void setHeight(int newHeight);
};
#endif