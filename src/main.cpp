
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

class Book {
public:
    int id;
    string title;
    string author;

    void display() const {
        cout << "Book ID: " << id << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "------------------------------" << endl;
    }
};

// Save all books to file
void saveBooks(const vector<Book>& books) {
    ofstream file("data/books.txt");

    if (!file.is_open()) {
        cout << "Error: Could not save books!" << endl;
        return;
    }

    for (int i = 0; i < static_cast<int>(books.size()); i++) {
        file << books[i].id << endl;
        file << books[i].title << endl;
        file << books[i].author << endl;
    }

    file.close();
    cout << "Books saved successfully!" << endl;
}

// Load books from file
void loadBooks(vector<Book>& books) {
    ifstream file("data/books.txt");

    if (!file.is_open()) {
        cout << "No saved books file found. Starting fresh." << endl;
        return;
    }

    Book book;

    while (file >> book.id) {
        file.ignore(numeric_limits<streamsize>::max(), '\n');

        if (!getline(file, book.title)) {
            cout << "Warning: Incomplete book record found." << endl;
            break;
        }

        if (!getline(file, book.author)) {
            cout << "Warning: Incomplete book record found." << endl;
            break;
        }

        books.push_back(book);
    }

    file.close();

    cout << "Books loaded: " << books.size() << endl;
}

// Display all books
void displayBooks(const vector<Book>& books) {
    if (books.empty()) {
        cout << "No books available in the library." << endl;
        return;
    }

    cout << "\nTotal books: " << books.size() << endl;

    for (int i = 0; i < static_cast<int>(books.size()); i++) {
        books[i].display();
    }
}

// Add a new book
void addBook(vector<Book>& books) {
    Book newBook;

    cout << "Enter Book ID: ";

    if (!(cin >> newBook.id)) {
        cout << "Invalid input! Please enter a numeric ID." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    if (newBook.id <= 0) {
        cout << "Book ID must be a positive number." << endl;
        return;
    }

    for (int i = 0; i < static_cast<int>(books.size()); i++) {
        if (books[i].id == newBook.id) {
            cout << "Error: This Book ID already exists!" << endl;
            return;
        }
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter Book Title: ";
    getline(cin, newBook.title);

    cout << "Enter Author Name: ";
    getline(cin, newBook.author);

    if (newBook.title.empty() || newBook.author.empty()) {
        cout << "Title and author cannot be empty." << endl;
        return;
    }

    books.push_back(newBook);
    saveBooks(books);

    cout << "Book added successfully!" << endl;
}

// Search for a book
void searchBook(const vector<Book>& books) {
    int searchId;

    cout << "Enter Book ID to search: ";

    if (!(cin >> searchId)) {
        cout << "Invalid ID!" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    for (int i = 0; i < static_cast<int>(books.size()); i++) {
        if (books[i].id == searchId) {
            cout << "\nBook found!" << endl;
            books[i].display();
            return;
        }
    }

    cout << "Book not found!" << endl;
}

// Delete a book
void deleteBook(vector<Book>& books) {
    int deleteId;

    cout << "Enter Book ID to delete: ";

    if (!(cin >> deleteId)) {
        cout << "Invalid ID!" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    for (int i = 0; i < static_cast<int>(books.size()); i++) {
        if (books[i].id == deleteId) {
            books.erase(books.begin() + i);
            saveBooks(books);

            cout << "Book deleted successfully!" << endl;
            return;
        }
    }

    cout << "Book not found!" << endl;
}

int main() {
    vector<Book> books;

    // Load saved books when the program starts
    loadBooks(books);

    int choice;

    do {
        cout << "\n==================================" << endl;
        cout << "     LIBRARY MANAGEMENT SYSTEM" << endl;
        cout << "==================================" << endl;
        cout << "1. Display All Books" << endl;
        cout << "2. Add New Book" << endl;
        cout << "3. Search Book by ID" << endl;
        cout << "4. Delete Book by ID" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input! Please enter a number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1:
                displayBooks(books);
                break;

            case 2:
                addBook(books);
                break;

            case 3:
                searchBook(books);
                break;

            case 4:
                deleteBook(books);
                break;

            case 5:
                saveBooks(books);
                cout << "Exiting Library System. Goodbye!" << endl;
                break;

            default:
                cout << "Invalid choice! Please select 1 to 5." << endl;
        }

    } while (choice != 5);

    return 0;
}

