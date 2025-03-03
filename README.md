# Student Records Management System with AVL Tree

Welcome to the Student Records Management System—a project born out of late-night coffee sessions, lots of debugging, and a passion for data structures! This is my third adventure into managing student records, and this time, I teamed up with an AVL Tree to keep things balanced (pun intended). Built for the Data Structures and Algorithms Lab at NIT Warangal, this C++ project handles student data with operations like adding students, modifying grades, and querying roll numbers—all while ensuring the tree stays balanced for efficiency. Let’s dive into how we got here and how you can explore it yourself!

## About the Project

This project is the third in a series of student record systems I’ve built for our DSA lab. The first two used linked lists—simple, linear, and straightforward. But for this term project, our professor threw us a curveball: use an AVL Tree instead. Why? Because AVL Trees self-balance, keeping operations like insertion and deletion at O(log n) time, unlike the O(n) slog of linked lists for some tasks. It’s like upgrading from a bicycle to a scooter—faster and smoother!

The system reads commands from an `input.txt` file, processes them (think adding students or tweaking course marks), and displays the AVL Tree’s state after each operation. It’s modular, with separate files for the tree logic, file handling, and student data, making it easy to tweak or extend.

### Features
- **AVL Tree Core**: Stores student records (roll number, name, CGPA, courses) with automatic balancing.
- **Operations**: Supports 12 operations (insert student, modify CGPA, add/delete courses, roll number queries, etc.).
- **File Input**: Reads multi-line commands from `input.txt` (e.g., `# 1` for adding a student).
- **Error Handling**: Catches invalid formats or data ranges with clear messages.
- **Display**: Shows the tree state after every operation, in-order traversal style.

## How We Built It

### The Journey
Starting with the linked list projects gave me a solid foundation—handling student data was familiar territory. But switching to an AVL Tree? That was a leap! I began by sketching out the basics: a `node` class for student info (roll number, name, CGPA, courses, height, pointers), and a `node_operations` class for tree logic (rotations, balancing, CRUD operations).

The first challenge was the AVL Tree itself. Linked lists were easy—just point to the next node. Here, I had to master left and right rotations, balance factors, and height updates. I spent hours with pen and paper, drawing trees, inserting nodes like `246` or `105`, and rotating them until the balance clicked. Debugging crashes from unbalanced trees was a rite of passage!

Next came the file handling. The `input.txt` format—`# 1` followed by student data and courses—was tricky. My initial `filehandler.cpp` tried parsing everything on one line, but the multi-line structure (e.g., courses on separate lines) tripped me up. I iterated through several versions, tweaking `processOperation` to grab data after `# <number>`, and adjusting `handleInsertStudent` to read course lines from the file stream. Lots of `cout` debugging later, I got it to work—seeing `Roll No: 246` pop up felt like a victory lap!

Integration was the final hurdle. Linking `node_operations` with `filehandler` meant ensuring operations like `addStudent` and `deleteCourse` played nice with the file input. I hit snags with pointer references (`node*&` vs `node*`) and course array updates, but after some trial-and-error (and a few too many compiler errors), it all came together.

### Compared to Previous Projects
Unlike the linked list versions, this project demanded tree balancing—think `leftRotate` and `rightRotate` instead of just `next` pointers. The file handling stayed similar, but the AVL Tree’s efficiency shines for larger datasets. Where linked lists chugged through linear searches, the AVL Tree zips along with logarithmic performance. It’s a trade-off: more complexity upfront, but better scalability.

## Project Structure

- **`main.cpp`**: The entry point—reads `input.txt` and kicks off processing.
- **`node.h` / `node.cpp`**: Defines the AVL Tree node with student data and course management methods.
- **`node_operations.h` / `node_operations.cpp`**: Handles AVL Tree operations (insert, delete, rotate, balance).
- **`courseinfo.h` / `courseinfo.cpp`**: Manages course data (ID and marks).
- **`filehandler.h` / `filehandler.cpp`**: Parses `input.txt` and executes commands.
- **`makefile`**: Builds and runs the project with simple commands.

## Getting Started

### Prerequisites
- **C++ Compiler**: GCC (I used `g++` on WSL).
- **Make**: For the `makefile` to work.
- **OS**: Tested on WSL (Ubuntu on Windows), but should run on Linux/macOS too.

### Installation
1. Clone the repo:
   ```bash
   git clone https://github.com/yourusername/student-records-avl.git
   cd student-records-avl
