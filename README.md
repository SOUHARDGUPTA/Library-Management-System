# 📚 Library Management System

A simple, menu-driven **Library Management System** built using C++. This project allows users to manage books through a command-line interface and store book records in a text file for persistence.

## ✨ Features

- 📖 Display all available books
- ➕ Add new books to the library
- 🔍 Search for books by ID
- 🗑️ Delete books by ID
- 🛡️ Prevent duplicate Book IDs
- 💾 Save book records to a file
- 🔄 Load saved books when the program starts
- ✅ Basic input validation

## 🛠️ Technologies Used

- **Language:** C++
- **Compiler:** GCC (MinGW)
- **Concepts:** Classes, Objects, Vectors, Functions, File Handling, Loops and Conditional Statements
- **Version Control:** Git and GitHub

## 📁 Project Structure

```text
Library-Management-System/
├── src/
│   └── main.cpp
├── data/
│   └── books.txt
├── README.md
└── .gitignore
```

## ⚙️ Requirements

- A C++ compiler such as GCC (MinGW)
- Visual Studio Code or another code editor
- Git (optional, for version control)

## 🚀 How to Run

**1. Clone the repository**

```bash
git clone https://github.com/SOUHARDGUPTA/Library-Management-System.git
```

**2. Open the project folder**

```bash
cd Library-Management-System
```

**3. Compile the program**

```bash
g++ src/main.cpp -o library
```

**4. Run the program on Windows PowerShell**

```powershell
.\library.exe
```

Run the program from the project root directory so it can find `data/books.txt`.

## 📋 Menu Options

| Option | Function |
|---|---|
| 1 | Display all books |
| 2 | Add a new book |
| 3 | Search book by ID |
| 4 | Delete book by ID |
| 5 | Exit the program |

## 💾 Data Storage

Book records are stored in `data/books.txt`. Each book uses three lines:

1. Book ID
2. Book title
3. Author name

The program loads saved records at startup and saves changes when books are added or deleted.

## 🎯 Learning Objectives

This project helped me practise:

- Object-oriented programming in C++
- Managing collections with `vector`
- Creating reusable functions
- Reading and writing files
- Using Git and GitHub to manage a project

## 👨‍💻 Author

**Souhard Gupta**

GitHub: [@SOUHARDGUPTA](https://github.com/SOUHARDGUPTA)
