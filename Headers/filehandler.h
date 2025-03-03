#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include "node_operations.h"
#include <string>
#include <fstream>

class FileHandler {
private:
    node* root;
    std::ifstream inputFile;

    void handleInsertStudent(std::ifstream& file, const std::string& line);
    void handleModifyCGPA(std::ifstream& file, const std::string& line);
    void handleAddCourse(std::ifstream& file, const std::string& line);
    void handleModifyCourseMarks(std::ifstream& file, const std::string& line);
    void handleDeleteCourse(std::ifstream& file, const std::string& line);
    void handleDeleteStudent(std::ifstream& file, const std::string& line);
    void handleRollGreater(std::ifstream& file, const std::string& line);
    void handleRollLess(std::ifstream& file, const std::string& line);
    void handleRollBetween(std::ifstream& file, const std::string& line);
    void handleCGPAGreater(std::ifstream& file, const std::string& line);
    void handleCGPALess(std::ifstream& file, const std::string& line);
    void handleCGPABetween(std::ifstream& file, const std::string& line);
    void processCommand(int operation, std::ifstream& file, const std::string& line);

public:
    FileHandler(const std::string& filename);
    ~FileHandler();
    void processFile();
    node* getRoot() const { return root; }
};

#endif