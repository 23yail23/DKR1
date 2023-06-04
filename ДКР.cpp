#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

class Book {
private:
    int id; // Унікальний ідентифікатор книги
    string title; // Заголовок книги
    string author; // Автор книги
    string publisher; // Видавництво книги
    int year; // Рік видання книги
    int pageCount; // Кількість сторінок у книзі
    double priceUSD; // Змінна ціни в доларах

public:
    Book(int id, const string& title, const string& author, const string& publisher, int year,
         int pageCount, double priceUSD)
        : id(id), title(title), author(author), publisher(publisher), year(year),
          pageCount(pageCount), priceUSD(priceUSD) {}

    // Методи доступу до приватних полів

    // Getter для отримання ідентифікатора книги
    int getId() const { return id; }

    // Getter для отримання заголовка книги
    string getTitle() const { return title; }

    // Getter для отримання автора книги
    string getAuthor() const { return author; }

    // Getter для отримання видавництва книги
    string getPublisher() const { return publisher; }

    // Getter для отримання року видання книги
    int getYear() const { return year; }

    // Getter для отримання кількості сторінок у книзі
    int getPageCount() const { return pageCount; }

    // Getter для отримання ціни книги в доларах
    double getPriceUSD() const { return priceUSD; }

    // Метод для отримання рядкового представлення об'єкту книги
    string toString() const {
        return "ID: " + to_string(id) + "\n"
               + "Title: " + title + "\n"
               + "Author: " + author + "\n"
               + "Publisher: " + publisher + "\n"
               + "Year: " + to_string(year) + "\n"
               + "Page Count: " + to_string(pageCount) + "\n"
               + "Price: $" + to_string(priceUSD) + "\n";
    }
};

int main() {
    // Створення вектора об'єктів Book, які представляють книги
    vector<Book> books = {
        Book(1, "The Da Vinci Code", "Dan Brown", "Family Leisure Club", 2003, 478, 10.99),
        Book(2, "Angels and Demons", "Dan Brown", "Family Leisure Club", 2000, 541, 11.99),
        Book(3, "Inferno", "Dan Brown", "Family Leisure Club", 2013, 606, 13.99),
        Book(4, "The Lost Symbol", "Dan Brown", "Family Leisure Club", 2009, 606, 12.99)
    };

    string yearInput;
    int yearToSearch;

    while (true) {
        // Запитуємо користувача рік для пошуку книг
        cout << "Enter the year to search: ";
        getline(cin, yearInput);

        try {
            // Конвертуємо введений рік у ціле число
            yearToSearch = stoi(yearInput);
            bool booksFound = false;

            cout << "Books published after " << yearToSearch << ":" << endl;
            for (const Book& book : books) {
                // Перевіряємо, чи була книга видана після введеного року
                if (book.getYear() >= yearToSearch) {
                    // Виводимо заголовок та рік видання книги
                    cout << "Title: " << book.getTitle() << ", Year: " << book.getYear() << endl;
                    booksFound = true;
                }
            }

            if (booksFound) {
                // Якщо знайдено книги, виходимо з циклу
                break;
            } else {
                cout << "No books found, please try again." << endl;
            }
        } catch (const std::invalid_argument& e) {
            cout << "Invalid input. Please enter a valid year." << endl;
        }
    }

    string authorInput;
    cout << "Enter the author's name to search: ";
    getline(cin, authorInput);

    cout << "Books by author " << authorInput << ":" << endl;
    for (const Book& book : books) {
        // Перевіряємо, чи книга має заданого автора
        if (book.getAuthor() == authorInput) {
            // Виводимо заголовок, ціну та рік видання книги
            cout << "Title: " << book.getTitle() << ", Price: $" << book.getPriceUSD() << ", Year: " << book.getYear() << endl;
        }
    }

    cout << "Books published by Family Leisure Club:" << endl;
    bool danBrownBooksFound = false;
    for (const Book& book : books) {
        // Перевіряємо, чи книга була видана видавництвом Family Leisure Club
        if (book.getPublisher() == "Family Leisure Club") {
            if (!danBrownBooksFound) {
                cout << "All of Dan Brown's books were published by Family Leisure Club:" << endl;
                danBrownBooksFound = true;
            }
            // Виводимо заголовок та ціну книги
            cout << "Title: " << book.getTitle() << ", Price: $" << book.getPriceUSD() << endl;
        }
    }

    return 0;
}
