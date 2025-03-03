#include "../Headers/node_operations.h"
#include <iostream>
#include <algorithm>

node* node_operations::firstStudent(node* root, int rollNo) {
    if (!root) return nullptr;
    if (root->getRollNo() == rollNo) return root;
    if (rollNo < root->getRollNo()) return firstStudent(root->getLeft(), rollNo);
    return firstStudent(root->getRight(), rollNo);
}

void node_operations::rightRotate(node*& x) {
    node* y = x->getLeft();
    x->setLeft(y->getRight());
    y->setRight(x);
    updateHeight(x);
    updateHeight(y);
    x = y;
}

void node_operations::leftRotate(node*& x) {
    node* y = x->getRight();
    x->setRight(y->getLeft());
    y->setLeft(x);
    updateHeight(x);
    updateHeight(y);
    x = y;
}

bool node_operations::isBalanced(node*& root) {
    if (!root) return true;
    int leftHeight = (root->getLeft()) ? root->getLeft()->getHeight() : 0;
    int rightHeight = (root->getRight()) ? root->getRight()->getHeight() : 0;
    return std::abs(leftHeight - rightHeight) <= 1;
}

int node_operations::updateHeight(node*& root) {
    if (!root) return 0;
    int leftHeight = (root->getLeft()) ? root->getLeft()->getHeight() : 0;
    int rightHeight = (root->getRight()) ? root->getRight()->getHeight() : 0;
    root->setHeight(std::max(leftHeight, rightHeight) + 1);
    return root->getHeight();
}

void node_operations::updateTree(node*& root) {
    if (!root) return;
    updateHeight(root);
    int leftHeight = (root->getLeft()) ? root->getLeft()->getHeight() : 0;
    int rightHeight = (root->getRight()) ? root->getRight()->getHeight() : 0;
    int balance = leftHeight - rightHeight;

    if (balance > 1) {
        int leftLeftHeight = (root->getLeft()->getLeft()) ? root->getLeft()->getLeft()->getHeight() : 0;
        int leftRightHeight = (root->getLeft()->getRight()) ? root->getLeft()->getRight()->getHeight() : 0;
        if (leftLeftHeight >= leftRightHeight) {
            node_operations::rightRotate(root);
        }
        else {
            node* leftChild = root->getLeft();
            node_operations::leftRotate(leftChild);
            root->setLeft(leftChild);
            node_operations::rightRotate(root);
        }
    }
    else if (balance < -1) {
        int rightRightHeight = (root->getRight()->getRight()) ? root->getRight()->getRight()->getHeight() : 0;
        int rightLeftHeight = (root->getRight()->getLeft()) ? root->getRight()->getLeft()->getHeight() : 0;
        if (rightRightHeight >= rightLeftHeight) {
            node_operations::leftRotate(root);
        }
        else {
            node* rightChild = root->getRight();
            node_operations::rightRotate(rightChild);
            root->setRight(rightChild);
            node_operations::leftRotate(root);
        }
    }
}

bool node_operations::addStudent(node*& root, int rollNo, std::string name, float cgpa, int numOfCourses, courses* course) {
    if (!root) {
        root = new node(rollNo, name, cgpa, numOfCourses, course);
        return true;
    }
    if (rollNo < root->getRollNo()) {
        node* leftChild = root->getLeft();
        bool result = addStudent(leftChild, rollNo, name, cgpa, numOfCourses, course);
        root->setLeft(leftChild);
        updateTree(root);
        return result;
    }
    else if (rollNo > root->getRollNo()) {
        node* rightChild = root->getRight();
        bool result = addStudent(rightChild, rollNo, name, cgpa, numOfCourses, course);
        root->setRight(rightChild);
        updateTree(root);
        return result;
    }
    else {
        return false;
    }
}

bool node_operations::deleteStudent(node*& root, int rollNo) {
    if (!root) return false;
    if (rollNo < root->getRollNo()) {
        node* leftChild = root->getLeft();
        bool result = deleteStudent(leftChild, rollNo);
        root->setLeft(leftChild);
        updateTree(root);
        return result;
    }
    else if (rollNo > root->getRollNo()) {
        node* rightChild = root->getRight();
        bool result = deleteStudent(rightChild, rollNo);
        root->setRight(rightChild);
        updateTree(root);
        return result;
    }
    else {
        if (!root->getLeft() && !root->getRight()) {
            delete root;
            root = nullptr;
        }
        else if (!root->getRight()) {
            node* temp = root;
            root = root->getLeft();
            delete temp;
        }
        else if (!root->getLeft()) {
            node* temp = root;
            root = root->getRight();
            delete temp;
        }
        else {
            node* successor = firstStudent(root->getRight(), root->getRight()->getRollNo());
            root->setRollNo(successor->getRollNo());
            root->setName(successor->getName());
            root->setCgpa(successor->getCgpa());
            int numCourses = successor->getNumOfCourses();
            root->setNumOfCourses(numCourses);
            courses* newCourses = new courses[numCourses];
            for (int i = 0; i < numCourses; i++) {
                newCourses[i] = successor->getCourse(i);
            }
            delete[] root->getCourse();
            root->setCourses(newCourses, numCourses);
            node* rightChild = root->getRight();
            deleteStudent(rightChild, successor->getRollNo());
            root->setRight(rightChild);
            updateTree(root);
            delete[] newCourses;
        }
        return true;
    }
}

node* node_operations::findStudent(node* root, int rollNo) {
    if (!root || root->getRollNo() == rollNo) return root;
    if (rollNo < root->getRollNo()) return findStudent(root->getLeft(), rollNo);
    return findStudent(root->getRight(), rollNo);
}

void node_operations::displayStudents(node* root) {
    if (!root) return;
    displayStudents(root->getLeft());
    std::cout << "Roll No: " << root->getRollNo() << std::endl;
    std::cout << "Name: " << root->getName() << std::endl;
    std::cout << "CGPA: " << root->getCgpa() << std::endl;
    std::cout << "Courses: " << std::endl;
    for (int i = 0; i < root->getNumOfCourses(); i++) {
        std::cout << root->getCourse()[i].getCourseId() << ": " << root->getCourse()[i].getMarks() << std::endl;
    }
    std::cout << std::endl;
    displayStudents(root->getRight());
}

bool node_operations::modifyStudentCGPA(node*& root, int rollNo, float cgpa) {
    node* student = findStudent(root, rollNo);
    if (!student) return false;
    student->setCgpa(cgpa);
    return true;
}

bool node_operations::modifyStudentCourses(node*& root, int numOfCourses, int rollNo) {
    node* student = findStudent(root, rollNo);
    if (!student) return false;
    student->setNumOfCourses(numOfCourses);
    return true;
}

bool node_operations::addCourse(node*& root, int rollNo, int courseId, float marks) {
    node* student = findStudent(root, rollNo);
    if (!student) return false;
    student->addCourse(courseId, marks);
    return true;
}

bool node_operations::deleteCourse(node*& root, int rollNo, int courseId) {
    node* student = findStudent(root, rollNo);
    if (!student) return false;
    student->deleteCourse(courseId);
    return true;
}

bool node_operations::updateCourseMarks(node*& root, int rollNo, int courseId, float newMarks) {
    node* student = findStudent(root, rollNo);
    if (!student) return false;
    student->updateCourse(courseId, newMarks);
    return true;
}

bool node_operations::updateCourseId(node*& root, int rollNo, int courseId, int newCourseId) {
    node* student = findStudent(root, rollNo);
    if (!student) return false;
    for (int i = 0; i < student->getNumOfCourses(); i++) {
        if (student->getCourse()[i].getCourseId() == courseId) {
            student->getCourse()[i].setCourseId(newCourseId);
            return true;
        }
    }
    return false;
}

void node_operations::displayCGPA(node*& root, int upperlimit, int lowerlimit) {
    std::cout << "CGPA-based operations ignored since roll number is the key." << std::endl;
}

void node_operations::displayRoll(node*& root, int upperlimit, int lowerlimit) {
    if (!root) return;
    if (upperlimit == -1) {
        node* leftChild = root->getLeft();
        displayRoll(leftChild, upperlimit, lowerlimit);
        if (root->getRollNo() > lowerlimit) {
            std::cout << "Roll No: " << root->getRollNo() << std::endl;
            std::cout << "Name: " << root->getName() << std::endl;
            std::cout << "CGPA: " << root->getCgpa() << std::endl;
            std::cout << "Courses: " << std::endl;
            for (int i = 0; i < root->getNumOfCourses(); i++) {
                std::cout << root->getCourse()[i].getCourseId() << ": " << root->getCourse()[i].getMarks() << std::endl;
            }
            std::cout << std::endl;
            node* rightChild = root->getRight();
            displayRoll(rightChild, upperlimit, lowerlimit);
        }
    }
    else if (lowerlimit == -1) {
        node* leftChild = root->getLeft();
        displayRoll(leftChild, upperlimit, lowerlimit);
        if (root->getRollNo() < upperlimit) {
            std::cout << "Roll No: " << root->getRollNo() << std::endl;
            std::cout << "Name: " << root->getName() << std::endl;
            std::cout << "CGPA: " << root->getCgpa() << std::endl;
            std::cout << "Courses: " << std::endl;
            for (int i = 0; i < root->getNumOfCourses(); i++) {
                std::cout << root->getCourse()[i].getCourseId() << ": " << root->getCourse()[i].getMarks() << std::endl;
            }
            std::cout << std::endl;
        }
        node* rightChild = root->getRight();
        displayRoll(rightChild, upperlimit, lowerlimit);
    }
    else {
        node* leftChild = root->getLeft();
        displayRoll(leftChild, upperlimit, lowerlimit);
        if (root->getRollNo() > lowerlimit && root->getRollNo() < upperlimit) {
            std::cout << "Roll No: " << root->getRollNo() << std::endl;
            std::cout << "Name: " << root->getName() << std::endl;
            std::cout << "CGPA: " << root->getCgpa() << std::endl;
            std::cout << "Courses: " << std::endl;
            for (int i = 0; i < root->getNumOfCourses(); i++) {
                std::cout << root->getCourse()[i].getCourseId() << ": " << root->getCourse()[i].getMarks() << std::endl;
            }
            std::cout << std::endl;
        }
        node* rightChild = root->getRight();
        displayRoll(rightChild, upperlimit, lowerlimit);
    }
}