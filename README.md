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
