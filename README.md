# 🎓 Student Grade Management System

A console-based **C++** application for managing student records and grades.
Built as the **CSC1060 (C++ Programming) – Module 5 Final Project**.

**Author:** Abdul Moqtadir  **Date:** April 30, 2025

---

## 📋 Overview

This program helps students and teachers keep track of grades. It loads student
records from a text file, lets you add students and grades through a simple menu,
calculates averages automatically, shows who is passing or failing, and saves
everything back to the file when you quit.

## ✨ Features

| # | Menu Option        | Description                                                        |
|---|--------------------|--------------------------------------------------------------------|
| 1 | See all students   | Shows each student's name, ID, grades, average, and PASS/FAIL status |
| 2 | Add a student      | Adds a new student by name and ID                                  |
| 3 | Give a grade       | Adds a grade to an existing student and recalculates the average   |
| 4 | Who's passing?     | Lists students with an average of **70% or higher**                |
| 5 | Who's failing?     | Lists students with an average **below 70%**                       |
| 6 | Save and quit      | Writes all data back to `students.txt` and exits                   |

### Limits
- Up to **25** students (`MAX`)
- Up to **5** grades per student (`MAXG`)
- Passing grade: **70**

## 🗂️ Project Structure

```
CSC1060_Abdul Muh Final Project/
├── CSC1060_Abdul Muh Final Project.sln        # Visual Studio solution
├── README.md
└── CSC1060_Abdul Muh Final Project/
    ├── CSC1060_Abdul Muh Final Project.cpp    # Main source code
    ├── CSC1060_Abdul Muh Final Project.vcxproj # Visual Studio project file
    └── students.txt                           # Student data file
```

## 📄 Data File Format

`students.txt` stores one student per line in comma-separated format:

```
Name, ID, Grade1, Grade2, Grade3, ...
```

Example:
```
karim boba, 100, 85,92,78,88
najila quiam, 1002, 95, 89,91,94
jhon jacob, 1003, 65, 70, 68, 72
```

## 🛠️ How It Works

- **Arrays** store names, IDs, grades (2D array), grade counts, and averages.
- `readStuff()` – parses `students.txt` at startup using `getline`, `find`, `substr`, `stoi`, and `stof`.
- `getAvg()` – computes the average of a student's grades.
- `passed()` – returns `true` if the average is ≥ 70.
- `showAll()` – prints a formatted report of all students.
- `save()` – writes all records back to `students.txt`.
- Input validation handles non-numeric grade entries.

## ▶️ How to Run

### Visual Studio (Windows)
1. Open `CSC1060_Abdul Muh Final Project.sln`.
2. Press **Ctrl + F5** to build and run.

### g++ / clang (macOS / Linux)
```bash
cd "CSC1060_Abdul Muh Final Project"
g++ -std=c++11 "CSC1060_Abdul Muh Final Project.cpp" -o grade_manager
./grade_manager
```

> **Note:** Run the program from the folder containing `students.txt` so the file can be found.

## 💻 Sample Output

```
~~~ Grade Manager ~~~
1) See all students
2) Add a student
3) Give a grades
4) Who's passing?
5) Who's failing?
6) Save and quit
choose one: 4

Passing Students:
karim boba - 85.75%
najila quiam - 92.25%
sayer karimier - 81.25%
```

## 📚 Concepts Used

- File I/O (`ifstream`, `ofstream`)
- Arrays & 2D arrays
- Functions
- String parsing
- Loops and conditionals
- Input validation
