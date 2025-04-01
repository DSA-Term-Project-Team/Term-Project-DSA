# Student Records Management System with AVL Tree

Hey there! Welcome to our Student Records Management System—a labor of love crafted for the Data Structures and Algorithms Lab at NIT Warangal. This project marks our third dive into managing student records, and this time, we’ve leveled up from linked lists to the balanced world of AVL Trees. Picture this: a team of us huddled around laptops, fueled by coffee and determination, turning a pile of code into a sleek system that handles student data with finesse. Let’s walk you through how we built it, what it does, and how you can give it a spin!

## About the Project

This is the third installment in our series of student record systems for the DSA lab. Our first two projects leaned on linked lists—simple, linear, and a bit like organizing a playlist. For this term project, though, our professor challenged us to swap that out for an AVL Tree. Why? Because AVL Trees keep themselves balanced, ensuring operations stay snappy at O(log n) time, unlike the O(n) crawl of linked lists for some tasks. It’s like trading a skateboard for a zippy electric scooter—more complexity, but oh-so-worth-it for efficiency!

Built in C++, this system reads commands from an `input.txt` file, processes them (think adding students, tweaking grades, or querying roll numbers), and prints the AVL Tree’s state after each step. It’s split into neat modules—tree operations, file handling, and data structures—so we could wrangle the complexity without losing our minds.

### Features
- **AVL Tree Backbone**: Stores student records (roll number, name, CGPA, courses) with self-balancing magic.
- **Operations Galore**: Handles 12 operations—inserting students, modifying CGPA/courses, deleting records, and roll number range queries.
- **File-Driven**: Parses multi-line commands from `input.txt` (e.g., `# 1` to add a student).
- **Error Checking**: Catches bad formats or out-of-range values with friendly messages.
- **Tree Display**: Shows the tree’s current state after every operation, in-order style.

## Our Journey

### From Linked Lists to AVL Trees
Having tackled two linked list projects before, we were comfy with pointers and linear traversal. But AVL Trees? That was uncharted territory! We started by sketching out the `node` class—roll number, name, CGPA, a course array, plus height and left/right pointers for the tree. The `node_operations` class came next, packed with AVL goodies like rotations, balancing, and operations to add or tweak student data.

The AVL Tree was our first big hurdle. Linked lists were a breeze—just hook up the next node. Here, we had to wrap our heads around balance factors, left/right rotations, and height updates. We doodled trees on paper, inserted nodes like `246` or `105`, and rotated them until the logic clicked. Early attempts crashed hard—unbalanced trees are unforgiving—but after some late-night debugging, we got the rotations humming.

File handling was the next beast. The `input.txt` format—`# 1` followed by student data and course lines—threw us for a loop. Our first stab at `filehandler.cpp` tried parsing everything on one line, but the multi-line reality (e.g., courses on separate lines) stumped us. We iterated, tweaking how we read lines after `# <number>`, and leaned on `cout` to peek at what we were parsing. It took a few rounds of trial-and-error (and a lot of error messages), but we finally nailed it—seeing `Roll No: 246` with its course pop up was a fist-pump moment!

Tying it all together was the finale. Linking `node_operations` with `filehandler` meant wrestling with pointer references (`node*&` vs `node*`) and course array updates. We hit snags—like forgetting to read the next line for data—but after hammering out the bugs, the system clicked into place. Running it with the full `input.txt` and watching the tree grow and balance was pure satisfaction.

### How It Differs from Before
Compared to our linked list projects, this one’s a leap forward. Linked lists were all about `next` pointers and linear searches—fine for small datasets but sluggish for big ones. The AVL Tree brings logarithmic performance, trading simplicity for speed. File parsing stayed similar, but the tree’s balancing act (hello, `leftRotate` and `rightRotate`!) makes this version shine for scalability.

## Project Structure

- **`src/main.cpp`**: The starting line—reads `input.txt` and fires up the system.
- **`src/node.h` / `src/node.cpp`**: Defines the AVL Tree node, juggling student data and courses.
- **`src/node_operations.h` / `src/node_operations.cpp`**: Runs the AVL Tree show—insertions, deletions, rotations, and more.
- **`src/courseinfo.h` / `src/courseinfo.cpp`**: Keeps course data (ID, marks) in check.
- **`src/filehandler.h` / `src/filehandler.cpp`**: Reads `input.txt` and turns commands into action.
- **`src/makefile`**: Our build buddy—compiles and runs everything with a few commands.

## Getting Started

### What You’ll Need
- **C++ Compiler**: We used `g++` (tested on WSL’s Ubuntu).
- **Make**: To wield the `makefile`.
- **OS**: Built on WSL (Windows Subsystem for Linux), but should vibe on Linux or macOS too.

### Setup
1. Clone the repo:
   ```bash
   git clone https://github.com/DSA-Term-Project-Team/Term-Project-DSA.git
   cd Term-Project-DSA/src
# Term Project DSA - Individual Contributions

This project was a collaborative effort between Hardik Prajapati and Rayi Charan Harsha. The detailed contributions of each member are outlined below.

## Teamwork

This project was completed through the teamwork of Hardik Prajapati and Rayi Charan Harsha.

## Hardik Prajapati (24CSB1A19)

* **Project Structuring and File Organization:**
    * Established the modular project structure with distinct header (`.h`) and source (`.cpp`) files.
    * Collaborated with Rayi Charan Harsha in defining the file organization.
    * **Relevant Files:** `Term Project DSA/Headers/filehandler.h`, `Term Project DSA/Headers/node_operations.h`, `Term Project DSA/Headers/node.h`, `Term Project DSA/Headers/courseinfo.h`, `Term Project DSA/src/filehandler.cpp`, `Term Project DSA/src/node_operations.cpp`, `Term Project DSA/src/node.cpp`, `Term Project DSA/src/courseinfo.cpp`

* **File Handling Implementation (`Filehandler.h`, `Filehandler.cpp`):**
    * Implemented the `FileHandler` class for reading and processing data from an input file (`input.txt`).
    * Utilized `std::ifstream` for file input.
    * The constructor attempts to open the specified input file.
    * `processFile()` reads the file line by line, identifies command lines (starting with `#`), extracts the operation code, and calls `processCommand()`.
    * `processCommand()` uses a `switch` statement to delegate actions based on the operation code to specific handler functions.
    * Handler functions parse comma-separated data from subsequent lines using `std::istringstream` and call corresponding static methods in `node_operations`.
    * `handleInsertStudent` specifically reads multiple lines for course data.
    * **Relevant Files:** `Term Project DSA/Headers/filehandler.h`, `Term Project DSA/src/filehandler.cpp`, `Term Project DSA/src/input.txt`

    * **Error Handling:**
        * Checked if the input file could be opened in the constructor.
        * `processFile()` validates command line format and uses a `try-catch` block for `std::stoi` to handle invalid operation codes, ensuring they are within the valid range (1-12).
        * Handler functions rigorously check the success of each `std::istringstream` extraction and verify comma delimiters.
        * Extracted data is validated against logical constraints (e.g., valid roll number, CGPA range, marks range).
        * Ensured the presence of required subsequent lines (e.g., course data for student insertion).
        * Checked the boolean return values from `node_operations` functions to detect operational failures (e.g., duplicate student ID, student not found).
        * Specific and informative error messages are printed to `std::cerr` upon detecting any validation or operational failure.
        * CGPA range queries are explicitly noted as ignored via `std::cerr`.

* **AVL Tree Node Operations (Collaboration):**
    * Collaborated with Rayi Charan Harsha on implementing core AVL tree balancing functions in `node_operations.cpp`.
    * Contributed to the implementation of `rightRotate`, `leftRotate` (pointer manipulations for tree restructuring), `updateHeight` (calculating node height), and `updateTree` (checking balance factor using `isBalanced` and applying necessary rotations).
    * **Relevant File:** `Term Project DSA/src/node_operations.cpp`

## Rayi Charan Harsha (24CSB1A54)

* **AVL Tree Node Operations (`Node_operations.h`, `Node_operations.cpp`):**
    * The AVL tree implementation was also done in collaboration with Hardik Prajapati.
    * Led the implementation of static methods for AVL tree manipulation.
    * **`addStudent(...)`:** Implemented recursively. Creates a new node as the base case. Recursively navigates left or right based on `rollNo`. Calls `updateTree()` after insertion for balancing.
    * **`deleteStudent(...)`:** Implemented recursively. Finds the node by `rollNo`. Handles deletion for nodes with 0 or 1 child by returning the non-null child. For nodes with 2 children, it finds the in-order successor using `firstStudent()`, copies the successor's data, and recursively deletes the successor. Calls `updateTree()` after deletion for balancing.
    * **`findStudent(...)`:** Implemented a standard recursive Binary Search Tree lookup based on `rollNo`.
    * **Modification Functions (`modifyStudentCGPA`, `addCourse`, etc.):** Utilize `findStudent()` to locate the node and then call the corresponding public member function of the `node` object.
    * **Display Functions (`displayStudents`, `displayRoll`):** Use recursive in-order traversal. `displayRoll` includes conditional checks to display students within a specified roll number range.
    * **Balancing Functions (`rightRotate`, `leftRotate`, `updateHeight`, `isBalanced`, `updateTree`):** Implemented standard AVL rotation and height update logic. `updateTree()` calculates the balance factor and applies single (LL, RR) or double (LR, RL) rotations as needed.
    * **Relevant Files:** `Term Project DSA/Headers/node_operations.h`, `Term Project DSA/src/node_operations.cpp`

    * **Error Handling:**
        * **Duplicate Prevention:** `addStudent()` checks for existing students with the same `rollNo` and returns `false`.
        * **Not Found Handling:** `deleteStudent()` returns `false` if the student to be deleted is not found. Modification functions also return `false` if the target student is not found using `findStudent()`.
        * **Structural Integrity:** The AVL balancing logic implemented in `updateTree()` automatically maintains the balance of the tree after insertions and deletions, ensuring O(log n) operation complexity.

* **Course Information (`Courseinfo.h`, `Courseinfo.cpp`):**
    * Defined the `courses` class with `courseId` and `marks` attributes.
    * Implemented basic constructor, getter methods (`getCourseId`, `getMarks`), and setter methods (`setCourseId`, `setMarks`).
    * **Relevant File:** `Term Project DSA/Headers/courseinfo.h`, `Term Project DSA/src/courseinfo.cpp`

    * **Error Handling:**
        * Setter methods (`setCourseId`, `setMarks`) include input validation to ensure `courseId` is positive and `marks` are within the valid range (0-100). Errors are reported to `std::cerr` if validation fails.

* **Project Structuring (Assistance):**
    * Assisted Hardik Prajapati in defining the overall file structure and content of header files.

* **Assistance to Pawan Tej Kasoju:**
    * Provided help with the implementation details of `Courseinfo.cpp`.

## Kasoju Pavan Tej (24CSB1A27)

* **Node Structure (`Node.h`, `Node.cpp`):**
    * Implemented the `node` class representing a student in the AVL tree.
    * The constructor dynamically allocates an array of `courses` based on the initial number of courses provided.
    * The destructor `~node()` correctly deallocates the dynamically allocated `courses` array to prevent memory leaks.
    * Implemented various getter methods (e.g., `getRollNo`, `getName`, `getCgpa`) and setter methods (e.g., `setName`, `setCgpa`, `setHeight`).
    * **Course Management:**
        * **`addCourse(id, marks)`:** Creates a new, larger `courses` array, copies existing course data, adds the new course, deletes the old array, and updates the pointer and count of courses.
        * **`deleteCourse(id)`:** Finds the index of the course to be deleted, creates a smaller array, copies the remaining courses, deletes the old array, and updates the pointer and count.
        * **`updateCourse(id, marks)`:** Finds the course by its ID and calls the `setMarks()` method of the corresponding `courses` object.
        * **`displayCourses()`:** Iterates through the `courses` array and displays the details of each course.
    * **Relevant Files:** `Term Project DSA/Headers/node.h`, `Term Project DSA/src/node.cpp`

    * **Error Handling:**
        * **Memory Management:** Ensured proper allocation and deallocation of the dynamic `courses` array in the constructor, destructor, `addCourse`, and `deleteCourse` methods. Checks for null pointers before deletion.
        * **Course Not Found:** `deleteCourse()` and `updateCourse()` check if the specified course ID exists. If not found, they return without making changes, preventing potential errors.
        * **Data Validation:** Relies on the input validation implemented within the `courses::setMarks()` method when `updateCourse()` is called.

* **Course Information (`Courseinfo.cpp`):**
    * Contributed to the implementation of the `Courseinfo.cpp` file, with assistance from Rayi Charan Harsha.
    * **Relevant File:** `Term Project DSA/src/courseinfo.cpp`
# Student Records Management System using AVL Tree

## Project Description

This project delivers a robust and efficient Student Records Management System, meticulously engineered to handle student data with optimal performance and scalability. The system's core component is the AVL tree data structure, a self-balancing binary search tree that ensures logarithmic time complexity for crucial operations. This design choice guarantees that as the number of student records grows, the system maintains its speed and responsiveness, a critical factor for real-world applications. The system provides a comprehensive suite of functionalities, encompassing the creation of new student entries, modification of existing student details, deletion of student records, and versatile display mechanisms to present student information based on various user-defined criteria. The implementation prioritizes data integrity, operational efficiency, and user adaptability.

## Project Structure

The project's codebase is meticulously structured into several distinct files, each serving a specific purpose and contributing to the overall functionality of the system. These files are logically grouped into header files, CPP implementation files, a data input file, and a build automation file, promoting modularity and maintainability.

### Header Files

* `Courseinfo.h`:
    * This header file plays a foundational role by defining the structure and interface for the `courses` class.
    * The `courses` class is designed to represent a single course taken by a student within the academic context.
    * It encapsulates all the relevant data pertaining to a specific course, including `courseld`, which serves as the unique identifier for the course, and `marks`, which represent the marks or grades obtained by the student in that particular course.
    * The header file also declares a set of getter and setter functions. These functions are crucial for providing controlled access to the `courseld` and `marks` attributes. Getters enable the retrieval of course information, while setters allow for the modification of course information in a structured and controlled manner, ensuring data integrity and preventing direct, uncontrolled manipulation of the class's internal state.
* `Node.h`:
    * This header file is essential as it defines the structure and interface for the `node` class.
    * The `node` class is fundamental to the AVL tree implementation, serving as the building block of the tree and representing a single student within the student records management system.
    * Each `node` stores a comprehensive and rich set of data associated with a student, capturing all the relevant information. This includes:
        * `rollNo`: The student's roll number, which serves as a unique identifier for each student within the system.
        * `name`: The student's name, providing a human-readable identification.
        * `CGPA`: The student's Cumulative Grade Point Average, a crucial metric for academic performance evaluation.
        * `numberOfCourses`: The total number of courses the student has taken, providing context for the student's academic workload.
        * Course information: Detailed information about each course taken by the student, likely using an array or other data structure of `courses` objects.
        * `height`: The height of the node within the AVL tree. This attribute is absolutely crucial for the AVL tree's self-balancing mechanism, enabling the tree to maintain its logarithmic time complexity for operations.
    * The header file also declares a comprehensive suite of getter and setter functions. These functions are critical for providing controlled access to each of the data members within the `node` class. Getters allow for retrieving student information, while setters enable the modification of student information in a structured and validated way, ensuring data integrity and preventing unintended corruption of the data.
    * Furthermore, this header file declares functions specifically designed for managing a student's courses. These functions include `addCourse`, which allows adding a new course to a student's academic record; `updateCourse`, which facilitates modifying existing course information; `displayCourses`, which enables viewing the courses a student has taken; and `deleteCourse`, which removes a course from a student's record. These functions collectively provide the functionality to effectively manage and update a student's course-related information.
* `Node_operations.h`:
    * This header file is dedicated to declaring the class that implements the core AVL tree operations, which are fundamental to the system's efficiency.
    * This class encapsulates the functions necessary to construct and modify the AVL tree structure, ensuring its balanced state.
    * Key functions declared here include `rightRotate` and `leftRotate`. These functions are the fundamental tree rotation operations that are essential for maintaining the AVL tree's balance property. AVL trees rely on rotations to restructure themselves after insertions or deletions to ensure that the height difference between the left and right subtrees of any node is at most one.
    * The header also declares a function named `isBalanced`, the purpose of which is to check the balance of the AVL tree. This function uses the height information of each node to determine if the tree adheres to the AVL tree's balance criteria.
    * The `updateTree` function is declared, and its primary responsibility is to rebalance the AVL tree if it is found to be unbalanced after operations that have the potential to disrupt its balance, such as insertions or deletions. This function uses rotations to restore the AVL tree's balance.
    * The `updateHeight` function is declared, and it plays a crucial role in maintaining the AVL tree's integrity. This function recalculates and updates the height of nodes after rotations or other modifications to ensure that the height information is accurate and consistent. Accurate height information is essential for the AVL tree's balancing algorithms to function correctly.
    * In addition to the balancing operations, this header file also declares functions that facilitate the modification, addition, and removal of node data (which corresponds to student information). These functions enable the system to manage student records effectively. Furthermore, functions for displaying the updated tree data are also declared, allowing for viewing the current state of the student database.
* `Filehandler.h`:
    * This header file declares the `FileHandler` class.
    * The `FileHandler` class is a crucial component of the system, responsible for the critical task of managing the input file. This includes the processes of reading data from the file and processing the commands specified within the file.

### CPP Files

* `Courseinfo.cpp`:
    * This file provides the complete implementation for the `courses` class, which was previously declared in the `Courseinfo.h` header file. It contains the actual code that defines the behavior of the `courses` class and its associated functions.
* `Node.cpp`:
    * This file provides the complete implementation for the `node` class, which was declared in the `Node.h` header file. It contains the actual code that defines the behavior of the `node` class and its associated functions for managing student data and course information.
* `Node_operations.cpp`:
    * This file provides the complete implementation for the AVL tree operations that were declared in the `Node_operations.h` header file. It contains the code that implements the AVL tree balancing, rotation, and node manipulation algorithms.
* `Filehandler.cpp`:
    * This file provides the implementation for the `FileHandler` class, which was declared in the `Filehandler.h` header file.
    * This file is crucial for handling file input and processing.
    * This file leverages the power of the `fstream` (file stream) and `sstream` (string stream) Standard Template Libraries (STL). These libraries provide the necessary tools to efficiently read data from the input file and process it effectively.
    * The constructor of the `FileHandler` class is implemented to handle the crucial task of opening the input file. This implementation includes robust error handling mechanisms to gracefully handle potential errors that might occur during the file opening process, such as the file not being found or permissions issues.
    * This file also implements the core logic for inserting student records into the system. This implementation includes comprehensive error handling routines to validate the input format and ensure the validity and consistency of the student data being inserted. It checks for various potential issues, such as incorrect input formats, which could lead to data corruption, and invalid values for student data, such as negative CGPAs or invalid roll numbers.
    * When the input format is determined to be correct and the data is validated, the class uses integer string streams to parse the input line. This involves converting strings representing numerical data into integer values.
    * It employs comma (`,`) as a delimiter to separate the data into the corresponding fields. This is a common practice for separating data elements in a text-based input file. Examples of fields include `rollNo`, `name`, and other relevant student attributes.
    * Finally, after parsing and validation, it calls the `addStudent` function to add the student record to the AVL tree, effectively storing the new student's information within the system.
    * The file also implements similar functions to handle other input commands, providing a comprehensive set of operations. These commands include:
        * `addCourse`: Adds a course to a student's academic record.
        * `deleteCourse`: Removes or deletes a course from a student's academic record.
        * `delete Student`: Removes or deletes an entire student record from the system.
        * `modifyCGPA`: Modifies or updates a student's Cumulative Grade Point Average (CGPA).
        * `modify CourseMarks`: Modifies or updates the marks or grades for a specific course taken by a student.
        * Handling roll number and CGPA filtering: Implements the logic to retrieve or display student records based on specified criteria, such as students with roll numbers or CGPAs that are less than a certain value, greater than a certain value, or within a specified range.
    * These various functions are invoked by the `processCommand` function.
    * The `processCommand` function uses a `switch` case statement, a control flow mechanism, to determine which of these specific functions should be invoked based on the command that was read from the input file. This allows for flexible and command-driven operation of the system.
    * The `processFile` function is responsible for calling the `processCommand` function.
    * `processFile` is called after reading a command line from the input file and performing initial error handling and command recognition. This function acts as an intermediary, ensuring that commands are correctly identified and passed on for further processing.
* `Main.cpp`:
    * This file contains the `main` function.
    * The `main` function serves as the entry point of the program's execution. It is the first function that is executed when the program is run.
    * The `filehanler` (an instance of the `FileHandler` class) is called within the `main` function to initiate the entire file processing and student record management operations. This is where the program begins its core functionality.
    * This call to the `FileHandler` is made after performing initial error handling. This is a crucial step to ensure that the program starts correctly and handles potential startup issues.

### TXT Files

* `Input.txt`:
    * This file plays a critical role as the input data source for the program.
    * It contains the data that is used by the program to perform various student record management operations. The format and content of this file are crucial for the program to function correctly.

### Others

* `Makefile`:
    * This file is a build automation tool.
    * It is commonly used in Linux environments to streamline the process of compiling and building the project's executable. It automates the compilation process, making it easier and more efficient to build the program.

## Functionality

The project delivers a comprehensive and feature-rich suite of functionalities designed to effectively manage student records within the system, leveraging the power and efficiency of the AVL tree data structure:

* **Data Storage:**
    * The system is capable of storing student data in a structured and organized manner.
    * It stores crucial student information, including roll number (a unique identifier), name, Cumulative Grade Point Average (CGPA), and detailed information about the courses each student has taken.
    * The system employs the AVL tree data structure as the underlying storage mechanism. This choice of data structure is deliberate and strategic, as AVL trees provide efficient organization and retrieval of student records. The self-balancing nature of AVL trees ensures that search, insertion, and deletion operations are performed with logarithmic time complexity, which is significantly faster than linear time complexity, especially when dealing with large datasets.
* **AVL Tree Management:**
    * The system implements all the necessary AVL tree operations to maintain the tree's balance and ensure optimal performance.
    * This includes:
        * `rightRotate` and `leftRotate` operations: These are fundamental tree rotation operations. They are essential for rebalancing the AVL tree after insertions or deletions. These rotations are performed to maintain the AVL tree's balance property, which dictates that the height difference between the left and right subtrees of any node is at most one.
        * `isBalanced` function: This function plays a crucial role in maintaining the AVL tree's integrity. It checks the balance factor of nodes to determine if the tree is balanced according to the AVL tree's rules.
        * `updateTree` function: This function is responsible for performing the necessary rotations to rebalance the AVL tree if it is found to be unbalanced after operations that have the potential to disrupt its balance, such as insertions or deletions.
        * `updateHeight` function: This function is essential for maintaining the AVL tree's correctness. It recalculates and updates the height of nodes after rotations or other modifications. Accurate height information is critical for the AVL tree's balancing algorithms to function correctly and efficiently.
* **File Input and Processing:**
    * The system is designed to handle the reading and processing of input data from a text file.
    * The `fstream` (file stream) and `sstream` (string stream) libraries are utilized to facilitate these file operations. These libraries provide powerful tools for working with files and strings in C++.
    * The system includes functionality to:
        * Open the input file and handle potential errors that might occur during the file opening process. This includes robust error handling to address situations such as the file not being found, permission issues preventing access to the file, or other file-related problems.
        * Parse the input file, which involves extracting commands from the file and separating the data into its constituent parts. This parsing process is crucial for the system to understand the instructions provided in the input file and to extract the relevant data for processing.
* **Student Record Management:**
    * The system provides a comprehensive set of functions to manage student records effectively:
        * Adding new student records to the system: This functionality allows users to input information about new students and add them to the database.
        * Deleting existing student records from the system: This functionality allows users to remove student records from the database when necessary.
        * Modifying student data: This functionality enables users to update various aspects of a student's information, such as updating a student's Cumulative Grade Point Average (CGPA) or modifying the marks or grades for a specific course taken by a student.
        * Displaying student information: This functionality allows users to view student records and retrieve information from the database.
* **Data Access and Retrieval:**
    * The system is designed to provide flexible data access and retrieval capabilities.
    * Student data can be accessed using either the student's CGPA or their roll number as a key. This provides users with multiple ways to query and retrieve student information from the database, increasing the system's usability and versatility.
* **Error Handling:**
    * The system incorporates robust and comprehensive error handling mechanisms throughout its design and implementation.
    * Error handling is implemented in various aspects of the system to ensure its reliability and prevent unexpected errors or program crashes.
    * Error handling is present in:
        * File operations: This includes handling errors related to opening, reading, and writing files.
        * Data parsing: This involves validating the format of the input data to ensure it conforms to the expected structure.
        * Data validation: This includes checking for the validity of data values, such as ensuring that CGPAs are within a valid range and that roll numbers are in the correct format.

## Highlights

* **Comprehensive and Robust Error Handling:** The project places a significant emphasis on thorough and robust error handling across all functions and modules. This meticulous approach to error handling ensures that the system produces accurate and reliable output and effectively prevents unexpected errors or program crashes during its operation. The system is designed to anticipate and handle potential issues gracefully, making it more resilient and dependable.
* **Flexible and Versatile Data Access:** The system provides users with flexible and versatile ways to access and retrieve student data. Users can access student information using either the student's CGPA or their roll number, offering a range of data retrieval options. This flexibility enhances the system's usability and allows users to query the database in a way that best suits their needs.
* **Efficient Performance for Large Datasets:** The use of the AVL tree data structure as the underlying storage mechanism is a key design choice that ensures efficient performance, particularly when the system is used to manage large student databases. The AVL tree's self-balancing nature guarantees O(log n) time complexity for most operations, including search, insertion, and deletion. This logarithmic time complexity is significantly more efficient than linear time complexity (O(n)), which would result in slower performance as the dataset grows. This efficiency is crucial for maintaining the system's responsiveness and scalability.
* **Adaptability and Reusability:** The program is designed to be adaptable and reusable in different contexts. The system can be easily adapted to manage different student databases by simply modifying the input file. This design choice makes it a versatile and practical solution for various student record management needs, as it can be applied to different institutions or organizations with minimal code changes.

## Compilation and Execution

The project is designed to be compiled and executed in a Linux environment. The provided `Makefile` simplifies and automates the compilation and execution process, making it easier for users to build and run the program.

## Team Members

* Hardik Prajapati (24CSB1A19)
* Kasoju Pavan Tej (24CSB1A27)
* Rayi Charan Harsha (24CSB1A54)

###Thank you###
