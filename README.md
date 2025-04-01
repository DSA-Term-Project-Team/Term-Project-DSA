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
