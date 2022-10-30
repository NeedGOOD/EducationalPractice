#include <iostream>
#include <iomanip>
#include <string>

class Phone {
private:
    std::string number;     // Номер
    std::string model;      // Модель
    
    int weight;             // Вага
public:
    Phone(std::string number, std::string model, int weight) :
    number(number), model(model), weight(weight) {}

    /* Phone(std::string number, std::string model) :
    number(number), model(model), weight(250) {} */

    Phone(std::string number, std::string model) : Phone(number, model, 250) {}

    Phone() {
        std::cout << "Number phone: ";
        std::cin >> number;                 // Номер телефону

        std::cin.get();
        std::cout << "Model: ";
        getline(std::cin, model);           // Модель

        std::cout << "Weight in grams: ";
        std::cin >> weight;                 // Вага в грамах

        while (weight < 50 || weight > 300) {    // Перевірка
            std::cout << "// Error: ";
            std::cout << "Weight in grams: ";
            std::cin >> weight;
        }
    }

    void Result() {     // Вивід
        std::cout << std::setiosflags(std::ios::left);
        std::cout << std::setw(15) << "Number"
                  << std::setw(20) << "Model"
                  << std::setw(10) << "Weight" << '\n';
        std::cout << std::setw(15) << number
                  << std::setw(20) << model
                  << std::setw(10) << weight << '\n';
    }

    void ReceiveCall(std::string name) { std::cout << "Calling " << name << '\n'; }

    void ReceiveCall(std::string phoneName, std::string phoneNumber) {
        std::cout << "Calling " << phoneName << '\n'
                  << "Number " << phoneNumber << '\n';
    }

    std::string GetNumber() {
        return number;
    }

    void SendMessage(std::string numbers[], const int size) {
        std::cout << "Number" << '\n';

        for (int i = 0; i < size; ++i) { std::cout << numbers[i] << '\n'; }
    }
};

int main() {
    Phone phoneFirst;
    Phone phoneSecond;
    Phone phoneThird;

    std::cout << '\n';
    
    phoneFirst.Result();
    phoneSecond.Result();
    phoneThird.Result();

    std::cout << '\n';

    phoneFirst.ReceiveCall("Slavik");
    phoneSecond.ReceiveCall("Vladislav");
    phoneThird.ReceiveCall("Oleksandr");

    phoneFirst.GetNumber();
    phoneSecond.GetNumber();
    phoneThird.GetNumber();

    std::cout << '\n';

    phoneFirst.ReceiveCall("Vladislav", "+380999999999");
    phoneSecond.ReceiveCall("Oleksandr", "+380988888888");
    phoneThird.ReceiveCall("Anna", "+380977777777");

    std::cout << '\n';

    const int size = 3;

    std::string numbers[size] = { "+380955555555",
                                  "+380666666666",
                                  "+380533333333" };

    phoneFirst.SendMessage(numbers, size);
    phoneSecond.SendMessage(numbers, size);
    phoneThird.SendMessage(numbers, size);
    return 0;
}