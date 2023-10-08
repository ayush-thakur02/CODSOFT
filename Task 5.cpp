// Task 5 (LIBRARY MANAGEMENT SYSTEM)
// Write the C++ code to Develop a system to manage books, borrowers, and transactions in a library.
// Book Database: Store book information (title, author, ISBN) in a database.
// Book Search: Allow users to search for books based on title, author, or
// ISBN.
// Book Checkout: Enable librarians to check out books to borrowers.
// Book Return: Record book returns and update availability status.
// Fine Calculation: Implement a fine calculation system for overdue
// books.
// User Interface: Design a user-friendly interface for easy interaction.


#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

// Define the Book class
class Book {
public:
    string title;
    string author;
    string ISBN;
    bool isAvailable;

    Book(string title, string author, string ISBN)
        : title(title), author(author), ISBN(ISBN), isAvailable(true) {}
};

// Function to calculate fines for overdue books
double calculateFine(int daysLate);

// Global vector to store books
vector<Book> bookDatabase;

// Function to search for books by title, author, or ISBN
void searchBooks(string searchTerm) {
    cout << "Search Results:\n";
    for (const Book& book : bookDatabase) {
        if (book.title.find(searchTerm) != string::npos ||
            book.author.find(searchTerm) != string::npos ||
            book.ISBN.find(searchTerm) != string::npos) {
            cout << "Title: " << book.title << endl;
            cout << "Author: " << book.author << endl;
            cout << "ISBN: " << book.ISBN << endl;
            cout << "Available: " << (book.isAvailable ? "Yes" : "No") << endl;
            cout << "-------------------\n";
        }
    }
}

// Function to check out a book
void checkoutBook(string ISBN, string borrowerID) {
    for (Book& book : bookDatabase) {
        if (book.ISBN == ISBN && book.isAvailable) {
            book.isAvailable = false;
            cout << "Book with ISBN " << ISBN << " has been checked out to borrower " << borrowerID << endl;
            return;
        }
    }
    cout << "Book not found or already checked out." << endl;
}

// Function to return a book
void returnBook(string ISBN, string borrowerID, int daysLate) {
    for (Book& book : bookDatabase) {
        if (book.ISBN == ISBN && !book.isAvailable) {
            book.isAvailable = true;
            double fine = calculateFine(daysLate);
            if (fine > 0) {
                cout << "Book with ISBN " << ISBN << " has been returned by borrower " << borrowerID << " with a fine of $" << fine << endl;
            } else {
                cout << "Book with ISBN " << ISBN << " has been returned by borrower " << borrowerID << " on time." << endl;
            }
            return;
        }
    }
    cout << "Book not found or not checked out by borrower " << borrowerID << endl;
}

// Function to calculate fines for overdue books
double calculateFine(int daysLate) {
    const double fineRate = 0.25; // Adjust the fine rate as needed
    if (daysLate <= 0) {
        return 0.0;
    } else {
        return daysLate * fineRate;
    }
}

int main() {
    // Populate the book database with sample books
    bookDatabase.push_back(Book("The Great Gatsby", "F. Scott Fitzgerald", "978-0743273565"));
    bookDatabase.push_back(Book("To Kill a Mockingbird", "Harper Lee", "978-0061120084"));
    bookDatabase.push_back(Book("1984", "George Orwell", "978-0451524935"));
    bookDatabase.push_back(Book("Pride and Prejudice", "Jane Austen", "978-0141439518"));
    bookDatabase.push_back(Book("The Catcher in the Rye", "J.D. Salinger", "978-0316769174"));
    bookDatabase.push_back(Book("The Hobbit", "J.R.R. Tolkien", "978-0345534835"));


    while (true) {
        cout << "Library Management System Menu:\n";
        cout << "1. Search Books\n";
        cout << "2. Checkout Book\n";
        cout << "3. Return Book\n";
        cout << "4. Exit\n";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                {
                    cout << "Enter search term: ";
                    string searchTerm;
                    cin.ignore();
                    getline(cin, searchTerm);
                    searchBooks(searchTerm);
                }
                break;
            case 2:
                {
                    cout << "Enter ISBN: ";
                    string ISBN;
                    cin >> ISBN;
                    cout << "Enter borrower ID: ";
                    string borrowerID;
                    cin >> borrowerID;
                    checkoutBook(ISBN, borrowerID);
                }
                break;
            case 3:
                {
                    cout << "Enter ISBN: ";
                    string ISBN;
                    cin >> ISBN;
                    cout << "Enter borrower ID: ";
                    string borrowerID;
                    cin >> borrowerID;
                    cout << "Enter days late: ";
                    int daysLate;
                    cin >> daysLate;
                    returnBook(ISBN, borrowerID, daysLate);
                }
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
