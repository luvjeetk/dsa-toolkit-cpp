# DSA Toolkit C++

An interactive command-line application designed to help you explore and understand classic Data Structures and Algorithms in C++.

## Features

This toolkit currently includes the following modules:
1. **Array**: Basic array operations (Insert, Delete, Search, Display)
2. **Linked List**: Singly linked list (Insert at End, Delete by Value, Search, Display)
3. **Stack**: Last-In-First-Out (LIFO) data structure (Push, Pop, Top, Display, Size)
4. **Queue**: First-In-First-Out (FIFO) data structure using `std::deque` (Enqueue, Dequeue, Front, Display, Size)
5. **Binary Search Tree (BST)**: Node-based binary tree data structure (Insert, Inorder Traversal)

## Prerequisites

To compile and run this application, you must have a C++ compiler installed on your system (e.g., GCC/MinGW on Windows, Clang on macOS, or GCC on Linux).

## Building from Source

1. Clone the repository and negative to the `src` directory:
   ```bash
   cd src
   ```

2. Compile all the `.cpp` files together into an executable named `toolkit`:
   ```bash
   g++ array.cpp bst.cpp linkedlist.cpp main.cpp queue.cpp stack.cpp -o toolkit.exe
   ```

## Running the Toolkit

Once compiled, run the executable:

**On Windows:**
```bash
.\toolkit.exe
```

**On Linux/macOS:**
```bash
./toolkit
```

## Usage

When you run the toolkit, you will be greeted by the `DSA TOOLKIT` main menu. Enter the module's corresponding number to enter its specific submenu. Each submenu provides interactive choices allowing you to interact with the chosen data structure in real-time. Follow the on-screen prompts to perform various operations!