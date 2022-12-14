#include <iostream>
#include <vector>

class MyClass {
private:
    std::vector<std::string> words;
public:
    MyClass(int rows) : words(rows) {}

    void Input() {      // Введення
        for (int i = 0; i < words.size(); ++i) {
            std::cout << "Word: ";
            std::cin >> words[i];

            while (words[i].length() > 10) {    // Перевірка
                std::cout << "// Error\n";
                std::cout << "Word: ";
                std::cin >> words[i];
                std::cout << '\n';
            }
        }
        std::cout << '\n';
    }

    void Output() {     // Вивід
        std::cout << '\n';
        for (int i = 0; i < words.size(); ++i) { std::cout << "Word - " << words[i] << '\n'; }
        std::cout << '\n';
    }

    void AddWord() {    // Об'єднання
        std::string addWord = NewWord();
        int index = Index();

        words.insert(words.begin() + index, addWord);
    }

    int Index() {   // Індекс
        int enteredIndex;

        std::cout << "Select index: ";
        std::cin >> enteredIndex;

        while (enteredIndex < 0 || enteredIndex > words.size()) {   // Перевірка
            std::cout << "// Error\n";
            std::cout << "Select index: ";
            std::cin >> enteredIndex;
        }
        return enteredIndex;
    }

    std::string NewWord() {     // Нове слово
        std::string newWord;
        
        std::cout << "New word: ";
        std::cin >> newWord;
        
        while (newWord.length() > 10) {
            std::cout << "// Error\n";
            std::cout << "New word: ";
            std::cin >> newWord;
        }
        return newWord;
    }

    void Association() {    // Об'єднаня
        int index = Index();

        words[index] += NewWord();

        std::cout << "\nWord - " << words[index] << "\n\n";
    }

    int IsThere() {     // Перевірка наявність рядка
        std::string word = NewWord();

        for (int i = 0; i < words.size(); ++i) {
            // Є
            if (word == words[i]) { return i; }
        }
        return -1;  // Немає
    }
};

int main() {
    int size = 0;   // Кількість рядків

    std::cout << "Size: ";
    std::cin >> size;
    std::cout << '\n';

    MyClass works(size);

    works.Input();

    works.AddWord();

    works.Output();

    works.Association();

    std::cout << "\nIndex: " << works.IsThere() << '\n';
    return 0;
}