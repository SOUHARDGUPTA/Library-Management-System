#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Book {
public:
    int id;
    string title;
    string author;

    void display() {
        cout << "Book ID: " << id << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "------------------------" << endl;
    }
};

void saveBooks(vector<Book>& books) {
    ofstream file("data/books.txt");

    for (int i = 0; i < books.size(); i++) {
        file << books[i].id << endl;
        file << books[i].title << endl;
        file << books[i].author << endl;
    }

    file.close();

    cout << "Books saved successfully!" << endl;
}

int main() {
    vector<Book> books;

    Book book1;
    book1.id = 101;
    book1.title = "The Alchemist";
    book1.author = "Paulo Coelho";
    books.push_back(book1);

    Book book2;
    book2.id = 102;
    book2.title = "Atomic Habits";
    book2.author = "James Clear";
    books.push_back(book2);

    int choice;

    do {
        cout << "\n===== LIBRARY MANAGEMENT =====" << endl;
        cout << "1. Display All Books" << endl;
        cout << "2. Add New Book" << endl;
        cout<< "3. Search Book by ID" << endl;
        cout<<"4. Delete Book By ID"<<endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "\nTotal books: " << books.size() << endl;

            for (int i = 0; i < books.size(); i++) {
                books[i].display();
            }
        }

        else if (choice == 2)
        {
            Book newBook;
            bool idExists = false;

            cout << "Enter Book ID: ";
            cin >> newBook.id;

            for (int i = 0; i < books.size(); i++)
            {
                if (books[i].id == newBook.id)
                {
                    idExists = true;
                    break;
                }
            }

            if (idExists)
            {
                cout << "Error: This Book ID already exists!" << endl;
            }
            else
            {
                cin.ignore();

                cout << "Enter Book Title: ";
                getline(cin, newBook.title);

                cout << "Enter Author Name: ";
                getline(cin, newBook.author);

                books.push_back(newBook);

                cout << "Book added successfully!" << endl;
            }
        }
        else if (choice == 3) {
            int searchId;
            bool found = false;

            cout << "Enter Book ID to search: ";
            cin >> searchId;

            for (int i = 0; i < books.size(); i++)
            {
                if (books[i].id == searchId)
                {
                    cout << "\nBook Found!\n";
                    books[i].display();
                    found = true;
                    break;
                }
            }

            if (!found)
            {
                cout << "Book not found!" << endl;
            }
        }
        else if (choice == 4) {
            int deleteId;
            bool found = false;

            cout << "Enter Book ID to delete: ";
            cin >> deleteId;

            for (int i = 0; i < books.size(); i++)
            {
                if (books[i].id == deleteId)
                {
                    books.erase(books.begin() + i);
                    found = true;
                    cout << "Book deleted successfully!" << endl;
                    break;
                }
            }

            if (!found)
            {
                cout << "Book not found!" << endl;
            }
        }
        else if (choice == 5) {
            saveBooks(books);
            cout << "Exiting Library System. Goodbye!" << endl;
        }
        else {
            cout << "Invalid choice! Please try again." << endl;
        }

    } while (choice != 5);

    return 0;
}
