#include "pch.h"

#include "gtest/gtest.h"
#include "Assignment6.cpp" // Include the skeleton implementation

TEST(BorrowerTests, BorrowerInitialization) {
    Borrower borrower("Alice", 101);
    EXPECT_STREQ(borrower.getName(), "Alice");
    EXPECT_EQ(borrower.getId(), 101);
}

TEST(BookTests, BorrowingAndReturningBook) {
    TextBook book("Physics 101", "Isaac Newton", "Physics");
    EXPECT_FALSE(book.getBorrowStatus());

    book.borrowBook();
    EXPECT_TRUE(book.getBorrowStatus());

    book.returnBook();
    EXPECT_FALSE(book.getBorrowStatus());
}

TEST(BookTests, VirtualTypeCheck) {
    TextBook textbook("Algebra", "John Doe", "Math");
    Novel novel("Mystery of Life", "Jane Doe", "Mystery");

    EXPECT_STREQ(textbook.getType(), "TextBook");
    EXPECT_STREQ(novel.getType(), "Novel");
}

TEST(LibraryTests, AddBookAndCount) {
    Library library;
    EXPECT_EQ(library.countBorrowedBooks(), 0);

    library.addBook(new TextBook("Chemistry 101", "Marie Curie", "Chemistry"));
    library.addBook(new Novel("The Great Gatsby", "F. Scott Fitzgerald", "Fiction"));
    EXPECT_EQ(library.countBorrowedBooks(), 0);
}

TEST(LibraryTests, BorrowBookUpdatesCount) {
    Library library;

    TextBook* book1 = new TextBook("Physics 101", "Isaac Newton", "Physics");
    Novel* book2 = new Novel("Mystery Novel", "Arthur Conan Doyle", "Mystery");

    library.addBook(book1);
    library.addBook(book2);

    EXPECT_EQ(library.countBorrowedBooks(), 0);

    book1->borrowBook();
    EXPECT_EQ(library.countBorrowedBooks(), 1);

    book2->borrowBook();
    EXPECT_EQ(library.countBorrowedBooks(), 2);

    book1->returnBook();
    EXPECT_EQ(library.countBorrowedBooks(), 1);
}

TEST(LibraryTests, SearchByAuthorReturnsCorrectBooks) {
    Library library;

    library.addBook(new TextBook("Algebra", "John Doe", "Math"));
    library.addBook(new Novel("Mystery of Life", "John Doe", "Mystery"));
    library.addBook(new TextBook("Biology 101", "Jane Doe", "Science"));

    int count = 0;
    Book** results = library.searchByAuthor("John Doe", count);

    ASSERT_EQ(count, 2); // Expect 2 books by John Doe
    EXPECT_STREQ(results[0]->getTitle(), "Algebra");
    EXPECT_STREQ(results[1]->getTitle(), "Mystery of Life");

    // Clean up manually allocated array
    delete[] results;
}

TEST(LibraryTests, SearchByAuthorNoResults) {
    Library library;

    library.addBook(new TextBook("Algebra", "John Doe", "Math"));
    library.addBook(new TextBook("Biology 101", "Jane Doe", "Science"));

    int count = 0;
    Book** results = library.searchByAuthor("Isaac Newton", count);

    EXPECT_EQ(count, 0);
    EXPECT_EQ(results, nullptr);

    // No need to clean up since results should be nullptr
}
