#include <iostream>

class Reader {
private:
    std::string surname;        // Прізвище
    std::string name;           // Ім'я
    std::string middleName;     // По батькові

    int readerTicketNumber;     // Номер читацького квитка
    int dateBorn;               // Дата народження

    std::string numberPhone;    // Телефон
public:
    class Book {
    private:
        std::string nameBook;       // Назва книжки
        std::string authorsName;    // Ім'я автора
    public:
        Book(std::string nameBook, std::string authorsName) :
        nameBook(nameBook), authorsName(authorsName) {}

        std::string GetNameBook() { return nameBook; }
        std::string GetAuthorsName() { return authorsName; }
    };

    Reader() {
        std::cout << "Surname: ";
        std::cin >> surname;      // Призвіща

        while (surname < "A" || surname > "Z") {          // Перевірка
            std::cout << "\n// Error: surname writes this BIG word!\n";
            std::cout << "Surname: ";
            std::cin >> surname;
        }
        std::cout << "Name: ";
        std::cin >> name;         // Ім'я

        while (name < "A" || name > "Z") {                // Перевірка
            std::cout << "\n// Error: name writes this BIG word!\n";
            std::cout << "Name: ";
            std::cin >> name;
        }
        std::cout << "Middle name: ";
        std::cin >> middleName;   // По батькові

        while (middleName < "A" || middleName > "Z") {    // Перевірка
            std::cout << "\n// Error: Middle name writes this BIG word!\n";
            std::cout << "Middle name: ";
            std::cin >> middleName;
        }
    }

    void ReturnBook(Book* books, const int size) {
        std::cout << surname << ' ' << name[0] << ". " << middleName[0] << ". return books: ";

        for (int i = 0; i < size; ++i) {
            std::cout << books[i].GetNameBook();

            if (i == size - 1) { std::cout << ".\n"; }
            else { std::cout << ", "; }
        }
    }

    void ReturnBook(std::string* books, const int size) {
        std::cout << surname << ' ' << name[0] << ". " << middleName[0] << ". return books: ";

        for (int i = 0; i < size; ++i) {
            std::cout << books[i]; 

            if (i == size - 1) { std::cout << ".\n"; }
            else { std::cout << ", "; }
        }
    }

    void ReturnBook(int book) {
        std::cout << surname << ' ' << name[0] << ". " << middleName[0] << ". return " << book << " books.\n";
    }

    void TakeBook(Book* books, const int size) {
        std::cout << surname << ' ' << name[0] << ". " << middleName[0] << ". took books: ";

        for (int i = 0; i < size; ++i) {
            std::cout << books[i].GetNameBook();

            if (i == size - 1) { std::cout << ".\n"; }
            else { std::cout << ", "; }
        }
    }

    void TakeBook(std::string* books, const int size) {
        std::cout << surname << ' ' << name[0] << ". " << middleName[0] << ". took books: ";

        for (int i = 0; i < size; ++i) {
            std::cout << books[i]; 

            if (i == size - 1) { std::cout << ".\n"; }
            else { std::cout << ", "; }
        }
    }

    void TakeBook(int book) {
        std::cout << surname << ' ' << name[0] << ". " << middleName[0] << ". took " << book << " books.\n";
    }
};

int main() {
    Reader reader;

    const int numberOfBooks = 3;

    std::cout << '\n';

    reader.TakeBook(numberOfBooks);

    std::cout << '\n';

    std::string nameBooks[numberOfBooks] = { "Adventures",
                                             "Vocabulary",
                                             "Encyclopedia" };

    reader.TakeBook(nameBooks, numberOfBooks);

    std::cout << '\n';

    Reader::Book book[numberOfBooks] = { { "No name", "No name" },
                                         { "No name", "No name" },
                                         { "No name", "No name" } };

    reader.TakeBook(book, numberOfBooks);

    std::cout << '\n';

    reader.ReturnBook(numberOfBooks);

    std::cout << '\n';

    std::string nameBooks[numberOfBooks] = { "Adventures",
                                             "Vocabulary",
                                             "Encyclopedia" };

    reader.ReturnBook(nameBooks, numberOfBooks);

    std::cout << '\n';

    Reader::Book book[numberOfBooks] = { { "No name", "No name" },
                                         { "No name", "No name" },
                                         { "No name", "No name" } };

    reader.ReturnBook(book, numberOfBooks);
    return 0;
}