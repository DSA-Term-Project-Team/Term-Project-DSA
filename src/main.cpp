#include "../Headers/filehandler.h"
#include <iostream>
#include <string>
int main(int argc, char* argv[]) {
    std::string inputFileName = "input.txt";  
        inputFileName = argv[1];  
    
    FileHandler fileHandler(inputFileName);
    if (!fileHandler.getRoot() && !inputFileName.empty()) {
        fileHandler.processFile();
    }
    else {
        std::cerr << "Error: Unable to proceed with file processing. Check if '"
            << inputFileName << "' exists and is readable.\n";
        return 1;
    }
    return 0; 
}