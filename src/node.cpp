#include "../Headers/node.h"
#include <string>
node::node(int rollNo, std::string name, float cgpa, int numOfCourses, courses* courseList) {
	this->rollNo = rollNo;
	this->name = name;
	this->cgpa = cgpa;
	this->numOfCourses = numOfCourses;
	this->course = new courses[numOfCourses];
	for (int i = 0; i < numOfCourses; i++) {
		this->course[i] = courseList[i];
	}
	this->left = nullptr;
	this->right = nullptr;
}

int node::getRollNo() {
	return rollNo;
}
int node::getNumOfCourses() {
	return numOfCourses;
}
std::string node::getName() {
	return name;
}
float node::getCgpa() {
	return cgpa;
}
void node::setRollNo(int newRollNo) {
	rollNo = newRollNo;
}
void node::setName(std::string newName) {
	name = newName;
}
void node::setCgpa(float newCgpa) {
	cgpa = newCgpa;
}
void node::setNumOfCourses(int newNumOfCourses) {
	numOfCourses = newNumOfCourses;
}
courses* node::getCourse() {
	return course;
}
node* node::getLeft() {
	return left;
}
node* node::getRight() {
	return right;
}
void node::setLeft(node* newLeft) {
	left = newLeft;
}
void node::setRight(node* newRight) {
	right = newRight;
}
courses node::getCourse(int index)
{
	return course[index];
}
int getHeight() {
	return height;
}
void setHeight(int newHeight) {
	height = newHeight;
}
