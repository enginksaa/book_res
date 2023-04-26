#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Book {
private:
    string title;
    string author;
    bool reserved;
public:
    Book(string t, string a) {
        title = t;
        author = a;
        reserved = false;
    }
    string getTitle() {
        return title;
    }
    string getAuthor() {
        return author;
    }
    bool isReserved() {
        return reserved;
    }
    void reserveBook() {
        reserved = true;
    }
    void unreserveBook() {
        reserved = false;
    }
};

class Library {
private:
    vector<Book> books;
public:
    void addBook(string title, string author) {
        Book newBook(title, author);
        books.push_back(newBook);
    }
    void reserveBook(int bookIndex) {
        if (books[bookIndex].isReserved()) {
            cout << "Sorry, this book is already reserved." << endl;
        }
        else {
            books[bookIndex].reserveBook();
            cout << "Book reserved successfully." << endl;
        }
    }
    void unreserveBook(int bookIndex) {
        if (!books[bookIndex].isReserved()) {
            cout << "This book is not currently reserved." << endl;
        }
        else {
            books[bookIndex].unreserveBook();
            cout << "Book unreserved successfully." << endl;
        }
    }
    void printBooks() {
        cout << "Book list:" << endl;
        for (int i = 0; i < books.size(); i++) {
            cout << i << ". " << books[i].getTitle() << " by " << books[i].getAuthor();
            if (books[i].isReserved()) {
                cout << " (reserved)";
            }
            cout << endl;
        }
    }
};

int main() {
    Library library;

    library.addBook("The Great Gatsby", "F. Scott Fitzgerald");
    library.addBook("To Kill a Mockingbird", "Harper Lee");
    library.addBook("1984", "George Orwell");

    bool exitProgram = false;

    while (!exitProgram) {
        cout << endl;
        cout << "Please choose an option:" << endl;
        cout << "1. List all books" << endl;
        cout << "2. Reserve a book" << endl;
        cout << "3. Unreserve a book" << endl;
        cout << "4. Exit program" << endl;

        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            library.printBooks();
            break;
        case 2: {
            cout << "Please enter the index of the book you want to reserve:" << endl;
            int bookIndex;
            cin >> bookIndex;
            library.reserveBook(bookIndex);
            break;
        }
        case 3: {
            cout << "Please enter the index of the book you want to unreserve:" << endl;
            int bookIndex;
            cin >> bookIndex;
            library.unreserveBook(bookIndex);
            break;
        }
        case 4:
            exitProgram = true;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    }

    return 0;
}
