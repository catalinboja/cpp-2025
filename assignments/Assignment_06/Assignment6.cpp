#pragma once
// Skeleton implementation for LibraryBooks assignment
#include <iostream>
#include <cstring>

// Borrower Class
class Borrower {
private:
    char* name;
    int borrowerId;

public:
    // Constructor: Initialize borrower with a name and unique ID
    Borrower(const char* name, int id) {}

    // Destructor: Free allocated memory for name
    ~Borrower() {}

    // Get the name of the borrower
    const char* getName() {
		return nullptr;
    }

    // Get the unique ID of the borrower
    int getId() {
		return 0;
    }
};

// Book Base Class
class Book {
protected:
    char* title;
    char* author;
    bool isBorrowed;

public:
    // Constructor: Initialize book with title and author
	Book(const char* title, const char* author) {}

    // Destructor: Free allocated memory for title and author
    virtual ~Book() {}

    // Get the type of the book (overridden in derived classes)
    virtual const char* getType() { return nullptr; }

    // Mark the book as borrowed
    void borrowBook() {}

    // Mark the book as returned
    void returnBook() {}

    // Get the title of the book
    const char* getTitle() { return nullptr; }

    // Get the author of the book
    const char* getAuthor() { return nullptr; };

    // Check if the book is currently borrowed
    bool getBorrowStatus() { return false; }
};

// TextBook Class
class TextBook : public Book {
private:
    char* subject;

public:
    // Constructor: Initialize textbook with title, author, and subject
	// Update the call to the base class constructor and pass values for title and author
    TextBook(const char* title, const char* author, const char* subject): Book(nullptr,nullptr) { }

    // Destructor: Free allocated memory for subject
    ~TextBook() {}

    // Get the type of the book (returns "TextBook")
    const char* getType() { 
        return nullptr;
    }
};

// Novel Class
class Novel : public Book {
private:
    char* genre;

public:
    // Constructor: Initialize novel with title, author, and genre
    // Update the call to the base class constructor and pass values for title and author
    Novel(const char* title, const char* author, const char* genre) : Book(nullptr, nullptr) {}

    // Destructor: Free allocated memory for genre
    ~Novel() {}

    // Get the type of the book (returns "Novel")
    const char* getType() { return nullptr; };
};

// Library Class
class Library {
private:
    Book* books[50];
    int bookCount;

public:
    // Constructor: Initialize library with an empty book collection
    Library() {}

    // Destructor: Free allocated memory for all books in the collection
    ~Library() {}

    // Add a book to the library (if space is available)
    void addBook(Book* book) {}

	// Search for books by a specific author and return an array of matching books pointers
    Book** searchByAuthor(const char* author, int& count) { return nullptr; }

    // Count the number of borrowed books in the library
	int countBorrowedBooks() { return 0; }
};
