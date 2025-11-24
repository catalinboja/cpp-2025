#include "pch.h"
#include "Assignment4.cpp"

TEST(BookTests, DefaultConstructorInitializesFields) {
    Book b;

    EXPECT_EQ("Unknown", b.getTitle());
    EXPECT_EQ(0, b.getChapterCount());
    EXPECT_EQ(0, b.getTotalPages());
}

TEST(BookTests, ParameterizedConstructorCopiesDataDeeply) {
    int pages[3] = { 10, 20, 30 };
    Book b("Test Book", pages, 3);

    EXPECT_EQ("Test Book", b.getTitle());
    EXPECT_EQ(3, b.getChapterCount());
    EXPECT_EQ(10, b.getChapterPages(0));
    EXPECT_EQ(20, b.getChapterPages(1));
    EXPECT_EQ(30, b.getChapterPages(2));
    EXPECT_EQ(60, b.getTotalPages());
    EXPECT_DOUBLE_EQ(20.0, b.getAverageChapterPages());

    // Modify source array; Book should not change (deep copy)
    pages[0] = 999;
    EXPECT_EQ(10, b.getChapterPages(0));
}

TEST(BookTests, SetChapterPageCountsPerformsDeepCopy) {
    int pages1[2] = { 50, 60 };
    Book b("Another Book", pages1, 2);

    int pages2[3] = { 5, 15, 25 };
    b.setChapterPageCounts(pages2, 3);

    EXPECT_EQ(3, b.getChapterCount());
    EXPECT_EQ(5, b.getChapterPages(0));
    EXPECT_EQ(15, b.getChapterPages(1));
    EXPECT_EQ(25, b.getChapterPages(2));

    // Change source array; object must not change
    pages2[1] = 999;
    EXPECT_EQ(15, b.getChapterPages(1));
}

TEST(BookTests, CopyConstructorIsDeepCopy) {
    int pages[3] = { 12, 34, 56 };
    Book original("Original", pages, 3);
    Book copy = original;  // copy constructor

    EXPECT_EQ(original.getTitle(), copy.getTitle());
    EXPECT_EQ(original.getChapterCount(), copy.getChapterCount());
    EXPECT_EQ(original.getTotalPages(), copy.getTotalPages());

    // Changing original's chapters must not affect copy
    int newPages[3] = { 1, 2, 3 };
    original.setChapterPageCounts(newPages, 3);

    EXPECT_EQ(12, copy.getChapterPages(0));
    EXPECT_EQ(34, copy.getChapterPages(1));
    EXPECT_EQ(56, copy.getChapterPages(2));
}

TEST(BookTests, UniqueIdsAndStaticCounter) {
    int initialCount = Book::getNumberOfBooksCreated();

    Book b1;
    Book b2;

    EXPECT_NE(b1.getId(), b2.getId());
    EXPECT_EQ(initialCount + 2, Book::getNumberOfBooksCreated());
}

TEST(BookTests, HasShortChapterWorks) {
    int pages[4] = { 10, 50, 100, 5 };
    Book b("Short Chapter Test", pages, 4);

    EXPECT_TRUE(b.hasShortChapter(10));  // has chapters with 10 and 5
    EXPECT_TRUE(b.hasShortChapter(6));   // has chapter with 5 pages
    EXPECT_FALSE(b.hasShortChapter(4));  // none <= 4
}

TEST(BookTests, GetIndexOfFirstChapterWithPagesWorks) {
    int pages[5] = { 30, 40, 30, 20, 10 };
    Book b("Index Test", pages, 5);

    EXPECT_EQ(0, b.getIndexOfFirstChapterWithPages(30));
    EXPECT_EQ(1, b.getIndexOfFirstChapterWithPages(40));
    EXPECT_EQ(4, b.getIndexOfFirstChapterWithPages(10));
    EXPECT_EQ(-1, b.getIndexOfFirstChapterWithPages(999));
}

TEST(BookTests, GetChapterPagesReturnsMinusOneForInvalidIndex) {
    int pages[2] = { 10, 20 };
    Book b("Invalid Index Test", pages, 2);

    EXPECT_EQ(-1, b.getChapterPages(-1));
    EXPECT_EQ(-1, b.getChapterPages(2));
    EXPECT_EQ(-1, b.getChapterPages(100));
}


TEST(BookTests, IsLongerThanComparesTotalPagesCorrectly) {
    int pages1[3] = { 10, 20, 30 };   // total = 60
    int pages2[2] = { 40, 15 };       // total = 55

    Book b1("Book 1", pages1, 3);
    Book b2("Book 2", pages2, 2);

    EXPECT_TRUE(b1.isLongerThan(b2));
    EXPECT_FALSE(b2.isLongerThan(b1));
    EXPECT_FALSE(b1.isLongerThan(b1));  // equal -> false
}

TEST(BookTests, GetNumberOfChaptersWithinIntervalWorks) {
    int pages[5] = { 5, 10, 15, 20, 25 };
    Book b("Interval Test", pages, 5);

    EXPECT_EQ(3, b.getNumberOfChaptersWithinInterval(10, 20));   // 10, 15, 20
    EXPECT_EQ(0, b.getNumberOfChaptersWithinInterval(30, 40));   // none
    EXPECT_EQ(0, b.getNumberOfChaptersWithinInterval(20, 10));   // invalid interval
    EXPECT_EQ(5, b.getNumberOfChaptersWithinInterval(5, 25));    // all
}

TEST(BookTests, CanBeReadInDaysUsesTotalPagesAndConstraints) {
    int pages[3] = { 50, 60, 40 };    // total = 150
    Book b("Reading Plan", pages, 3);

    // 3 days * 60 pages/day = 180 -> enough
    EXPECT_TRUE(b.canBeReadInDays(3, 60));

    // 2 days * 70 pages/day = 140 -> not enough
    EXPECT_FALSE(b.canBeReadInDays(2, 70));

    // Invalid parameters
    EXPECT_FALSE(b.canBeReadInDays(0, 50));
    EXPECT_FALSE(b.canBeReadInDays(3, 0));
    EXPECT_FALSE(b.canBeReadInDays(-1, 50));
}

