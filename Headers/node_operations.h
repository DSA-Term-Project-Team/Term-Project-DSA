#ifndef NODE_OPERATIONS_H
#define NODE_OPERATIONS_H
#include "node.h"
#include <string>
/*
* Node operations class for the AVL Tree
* it contains the methods to add, delete, update and display students
* it also contains the methods to add, delete, update and display courses
* it also contains the methods to find the student and course
*/
class node_operations {
private:
    static node* firstStudent(node* root, int rollNo);
public:
    void rightRotate(node * &x);
    void leftRotate(node*& x);
    static bool isBalanced(node*& root);
    static void updateTree(node*& root);
    static int updateHeight(node*& root);
    static bool addStudent(node*& root, int rollNo, std::string name, float cgpa, int numOfCourses, courses* course); 
    static bool deleteStudent(node*& root, int rollNo); 
    static node* findStudent(node*& root, int rollNo); 
    static void displayStudents(node* root); 
    static bool modifyStudentCGPA(node*& root, int rollNo, float cgpa);
    static bool modifyStudentCourses(node*& root, int numOfCourses, int rollNo); 
    static bool addCourse(node*& root, int rollNo, int courseId, float marks); 
    static bool deleteCourse(node*& root, int rollNo, int courseId); 
    static bool updateCourseMarks(node*& root, int rollNo, int courseId, float newMarks); 
    static bool updateCourseId(node*& root, int rollNo, int courseId, int newCourseId);
    static void displayCGPA(node*& root, int upperlimit, int lowerlimit);
    static void displayRoll(node*& root, int upperlimit, int lowerlimit);

};
#endif