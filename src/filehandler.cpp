#include "../Headers/filehandler.h"
#include <iostream>
#include <sstream>
#include <vector>

FileHandler::FileHandler(const std::string& filename) : root(nullptr) {
    inputFile.open(filename);
    if (!inputFile.is_open()) {
        std::cerr << "Error: Could not open input file '" << filename << "'.\n";
    }
}

FileHandler::~FileHandler() {
    if (inputFile.is_open()) {
        inputFile.close();
    }
}

void FileHandler::handleInsertStudent(std::ifstream& file, const std::string& line) {
    std::istringstream iss(line);
    int rollNo, numOfCourses;
    float cgpa;
    std::string name;
    char comma;

    if (!(iss >> rollNo >> comma) || comma != ',' || !std::getline(iss >> std::ws, name, ',') ||
        !(iss >> cgpa >> comma) || comma != ',' || !(iss >> numOfCourses)) {
        std::cerr << "Error: Invalid student format: '" << line << "'\n";
        return;
    }

    if (rollNo <= 0 || cgpa < 0.0 || cgpa > 10.0 || numOfCourses < 0) {
        std::cerr << "Error: Invalid student data (rollNo: " << rollNo << ", cgpa: " << cgpa
            << ", numOfCourses: " << numOfCourses << ")\n";
        return;
    }

    std::vector<courses> courseList;
    std::string courseLine;
    for (int i = 0; i < numOfCourses; ++i) {
        if (!std::getline(file, courseLine) || courseLine.empty()) {
            std::cerr << "Error: Missing course data for rollNo " << rollNo << "\n";
            return;
        }
        std::istringstream courseIss(courseLine);
        int courseId;
        float marks;
        char courseComma;
        if (!(courseIss >> courseId >> courseComma >> marks) || courseComma != ',') {
            std::cerr << "Error: Invalid course format: '" << courseLine << "'\n";
            return;
        }
        if (courseId <= 0 || marks < 0.0 || marks > 100.0) {
            std::cerr << "Error: Invalid course data (courseId: " << courseId << ", marks: " << marks << ")\n";
            return;
        }
        courseList.emplace_back(courseId, marks);
    }

    courses* courseArray = numOfCourses > 0 ? courseList.data() : nullptr;
    if (!node_operations::addStudent(root, rollNo, name, cgpa, numOfCourses, courseArray)) {
        std::cerr << "Error: Failed to add student with rollNo " << rollNo << " (possible duplicate)\n";
    }
}

void FileHandler::handleModifyCGPA(std::ifstream& file, const std::string& line) {
    std::istringstream iss(line);
    int rollNo;
    float newCgpa;
    char comma;
    if (!(iss >> rollNo >> comma >> newCgpa) || comma != ',') {
        std::cerr << "Error: Invalid modify CGPA format: '" << line << "'\n";
        return;
    }
    if (rollNo <= 0 || newCgpa < 0.0 || newCgpa > 10.0) {
        std::cerr << "Error: Invalid data (rollNo: " << rollNo << ", newCgpa: " << newCgpa << ")\n";
        return;
    }
    if (!node_operations::modifyStudentCGPA(root, rollNo, newCgpa)) {
        std::cerr << "Error: Student with rollNo " << rollNo << " not found\n";
    }
}

void FileHandler::handleAddCourse(std::ifstream& file, const std::string& line) {
    std::istringstream iss(line);
    int rollNo, courseId;
    float marks;
    char comma;
    if (!(iss >> rollNo >> comma >> courseId >> comma >> marks) || comma != ',') {
        std::cerr << "Error: Invalid add course format: '" << line << "'\n";
        return;
    }
    if (rollNo <= 0 || courseId <= 0 || marks < 0.0 || marks > 100.0) {
        std::cerr << "Error: Invalid data (rollNo: " << rollNo << ", courseId: " << courseId
            << ", marks: " << marks << ")\n";
        return;
    }
    if (!node_operations::addCourse(root, rollNo, courseId, marks)) {
        std::cerr << "Error: Failed to add course for rollNo " << rollNo << " (student not found)\n";
    }
}

void FileHandler::handleModifyCourseMarks(std::ifstream& file, const std::string& line) {
    std::istringstream iss(line);
    int rollNo, courseId;
    float newMarks;
    char comma;
    if (!(iss >> rollNo >> comma >> courseId >> comma >> newMarks) || comma != ',') {
        std::cerr << "Error: Invalid modify course marks format: '" << line << "'\n";
        return;
    }
    if (rollNo <= 0 || courseId <= 0 || newMarks < 0.0 || newMarks > 100.0) {
        std::cerr << "Error: Invalid data (rollNo: " << rollNo << ", courseId: " << courseId
            << ", newMarks: " << newMarks << ")\n";
        return;
    }
    if (!node_operations::updateCourseMarks(root, rollNo, courseId, newMarks)) {
        std::cerr << "Error: Failed to update marks for course " << courseId << " of rollNo " << rollNo << "\n";
    }
}

void FileHandler::handleDeleteCourse(std::ifstream& file, const std::string& line) {
    std::istringstream iss(line);
    int rollNo, courseId;
    char comma;
    if (!(iss >> rollNo >> comma >> courseId) || comma != ',') {
        std::cerr << "Error: Invalid delete course format: '" << line << "'\n";
        return;
    }
    if (rollNo <= 0 || courseId <= 0) {
        std::cerr << "Error: Invalid data (rollNo: " << rollNo << ", courseId: " << courseId << ")\n";
        return;
    }
    if (!node_operations::deleteCourse(root, rollNo, courseId)) {
        std::cerr << "Error: Failed to delete course " << courseId << " for rollNo " << rollNo << "\n";
    }
}

void FileHandler::handleDeleteStudent(std::ifstream& file, const std::string& line) {
    std::istringstream iss(line);
    int rollNo;
    if (!(iss >> rollNo)) {
        std::cerr << "Error: Invalid delete student format: '" << line << "'\n";
        return;
    }
    if (rollNo <= 0) {
        std::cerr << "Error: Invalid rollNo: " << rollNo << "\n";
        return;
    }
    if (!node_operations::deleteStudent(root, rollNo)) {
        std::cerr << "Error: Failed to delete student with rollNo " << rollNo << " (not found)\n";
    }
}

void FileHandler::handleRollGreater(std::ifstream& file, const std::string& line) {
    std::istringstream iss(line);
    int value;
    if (!(iss >> value)) {
        std::cerr << "Error: Invalid roll number greater than format: '" << line << "'\n";
        return;
    }
    if (value < 0) {
        std::cerr << "Error: Invalid roll number value: " << value << "\n";
        return;
    }
    node_operations::displayRoll(root, -1, value);
}

void FileHandler::handleRollLess(std::ifstream& file, const std::string& line) {
    std::istringstream iss(line);
    int value;
    if (!(iss >> value)) {
        std::cerr << "Error: Invalid roll number less than format: '" << line << "'\n";
        return;
    }
    if (value < 0) {
        std::cerr << "Error: Invalid roll number value: " << value << "\n";
        return;
    }
    node_operations::displayRoll(root, value, -1);
}

void FileHandler::handleRollBetween(std::ifstream& file, const std::string& line) {
    std::istringstream iss(line);
    int lower, upper;
    char comma;
    if (!(iss >> lower >> comma >> upper) || comma != ',') {
        std::cerr << "Error: Invalid roll number between format: '" << line << "'\n";
        return;
    }
    if (lower < 0 || upper < 0 || lower >= upper) {
        std::cerr << "Error: Invalid range (lower: " << lower << ", upper: " << upper << ")\n";
        return;
    }
    node_operations::displayRoll(root, upper, lower);
}

void FileHandler::handleCGPAGreater(std::ifstream& file, const std::string& line) {
    std::cerr << "Warning: CGPA greater than operation (#10) ignored since roll number is the key\n";
    node_operations::displayCGPA(root, -1, -1);
}

void FileHandler::handleCGPALess(std::ifstream& file, const std::string& line) {
    std::cerr << "Warning: CGPA less than operation (#11) ignored since roll number is the key\n";
    node_operations::displayCGPA(root, -1, -1);
}

void FileHandler::handleCGPABetween(std::ifstream& file, const std::string& line) {
    std::cerr << "Warning: CGPA between operation (#12) ignored since roll number is the key\n";
    node_operations::displayCGPA(root, -1, -1);
}

void FileHandler::processCommand(int operation, std::ifstream& file, const std::string& line) {
    std::string dataLine;
    std::getline(file, dataLine);
    if (dataLine.empty()) {
        std::cerr << "Error: No data provided for operation #" << operation << "\n";
        return;
    }
    switch (operation) {
    case 1: handleInsertStudent(file, dataLine); break;
    case 2: handleModifyCGPA(file, dataLine); break;
    case 3: handleAddCourse(file, dataLine); break;
    case 4: handleModifyCourseMarks(file, dataLine); break;
    case 5: handleDeleteCourse(file, dataLine); break;
    case 6: handleDeleteStudent(file, dataLine); break;
    case 7: handleRollGreater(file, dataLine); break;
    case 8: handleRollLess(file, dataLine); break;
    case 9: handleRollBetween(file, dataLine); break;
    case 10: handleCGPAGreater(file, dataLine); break;
    case 11: handleCGPALess(file, dataLine); break;
    case 12: handleCGPABetween(file, dataLine); break;
    default: std::cerr << "Error: Unknown operation #" << operation << "\n";
    }
}

void FileHandler::processFile() {
    if (!inputFile.is_open()) {
        std::cerr << "Error: No input file open for processing\n";
        return;
    }

    std::string line;
    int lineNumber = 0;
    while (std::getline(inputFile, line)) {
        lineNumber++;
        if (line.empty()) continue;
        if (line[0] == '#') {
            std::istringstream iss(line);
            char hashtag;
            int operation;
            iss >> hashtag >> operation;
            if (operation >= 1 && operation <= 12) {
                std::cout << "Processing operation #" << operation << " at line " << lineNumber << ":\n";
                processCommand(operation, inputFile, line);
                std::cout << "Tree state after operation #" << operation << ":\n";
                node_operations::displayStudents(root);
                std::cout << "------------------------\n";
            }
            else {
                std::cerr << "Error: Invalid operation number at line " << lineNumber << ": '" << line << "'\n";
            }
        }
    }
    std::cout << "File processing completed.\n";
}