#include <iostream>
#include <string>

class Book {
private:
    static int nextId;
    int id;
    std::string title;
    int* chapterPageCounts;
    int chapterCount;

public:
    // Constructors and destructor
    Book();
    Book(const std::string& title, const int* chapterPageCounts, int chapterCount);
    Book(const Book& other);
    ~Book();

    // Getters
    int getId() const;
    std::string getTitle() const;
    int getChapterCount() const;
    int getChapterPages(int index) const;
    int getTotalPages() const;
    double getAverageChapterPages() const;

    // Setters
    void setTitle(const std::string& title);
    void setChapterPageCounts(const int* chapterPageCounts, int chapterCount);

    // Processing methods
    bool hasShortChapter(int maxPages) const;
    int getIndexOfFirstChapterWithPages(int pages) const;

    // Extra processing methods
    bool isLongerThan(const Book& other) const;
    int getNumberOfChaptersWithinInterval(int minPages, int maxPages) const;
    bool canBeReadInDays(int days, int maxPagesPerDay) const;

    // Static method
    static int getNumberOfBooksCreated();

private:
    void copyChapters(const int* chapterPageCounts, int chapterCount);
};

// Initialize static member
int Book::nextId = 0;

// ======================
// Method definitions
// ======================

Book::Book() {
    // TODO: implement default constructor
}

Book::Book(const std::string& title, const int* chapterPageCounts, int chapterCount) {
    // TODO: implement parameterized constructor
}

Book::Book(const Book& other) {
    // TODO: implement copy constructor (deep copy)
}

Book::~Book() {
    // TODO: implement destructor (free dynamic memory)
}

int Book::getId() const {
    // TODO: return id
    return 0;
}

std::string Book::getTitle() const {
    // TODO: return title
    return "";
}

int Book::getChapterCount() const {
    // TODO: return chapterCount
    return 0;
}

int Book::getChapterPages(int index) const {
    // TODO: return pages at index or -1 if invalid
    return 0;
}

int Book::getTotalPages() const {
    // TODO: compute and return total pages
    return 0;
}

double Book::getAverageChapterPages() const {
    // TODO: compute and return average pages (0 if no chapters)
    return 0.0;
}

void Book::setTitle(const std::string& title) {
    // TODO: set title
}

void Book::setChapterPageCounts(const int* chapterPageCounts, int chapterCount) {
    // TODO: deep copy new chapter page data
}

bool Book::hasShortChapter(int maxPages) const {
    // TODO: check if any chapter has pages <= maxPages
    return false;
}

int Book::getIndexOfFirstChapterWithPages(int pages) const {
    // TODO: find first chapter with exactly 'pages' pages, or -1
    return -1;
}

bool Book::isLongerThan(const Book& other) const {
    // TODO: compare total pages of *this with other
    return false;
}

int Book::getNumberOfChaptersWithinInterval(int minPages, int maxPages) const {
    // TODO: count chapters with pages in [minPages, maxPages]
    return 0;
}

bool Book::canBeReadInDays(int days, int maxPagesPerDay) const {
    // TODO: check if total pages <= days * maxPagesPerDay
    return false;
}

int Book::getNumberOfBooksCreated() {
    // TODO: return number of created books (nextId)
    return 0;
}

void Book::copyChapters(const int* chapterPageCounts, int chapterCount) {
    // TODO: helper for deep copying the dynamic array
}
