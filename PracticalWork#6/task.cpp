#include <iostream>
#include <iomanip>

class Train {
private:
    std::string station;    // Станція

    int numberTrain;    // Номер вагона
    // Час відправлення
    int departureTimeHours;     // Години
    int departureTimeMinutes;   // Хвилини
public:
    Train() {
        std::cout << "station: ";   // Станція
        std::cin >> station;

        std::cout << "number train: ";  // Номер вагона
        std::cin >> numberTrain;

        while (numberTrain < 1) {   // Превірка
            std::cout << "// Error\n";
            std::cout << "Number train: ";
            std::cin >> numberTrain;
        }
        std::cout << "departure time:\n"    // Час відправлення
                  << "\thours: ";             // Години
        std::cin >> departureTimeHours;

        while (departureTimeHours < 0 || departureTimeHours > 23) {     // Превірка
            std::cout << "// Error\n";
            std::cout << "\thours: ";
            std::cin >> departureTimeHours;
        }
        std::cout << "\tminutes: ";           // Хвилини
        std::cin >> departureTimeMinutes;

        while (departureTimeMinutes < 0 || departureTimeMinutes > 59) { // Превірка
            std::cout << "// Error\n";
            std::cout << "\tminutes: ";
            std::cin >> departureTimeMinutes;
        }
    }

    static void SortingThree(Train* train, int size) {  // Сортування за пунктом призначення та часом
        for (int j = 0; j < size; ++j) {    // Сортування
            int min = j;

            for (int i = j; i < size; ++i) {    // Сортування
                if (train[min].station > train[i].station) { min = i; } // Сортування станцій
                else if (train[min].station == train[i].station) {
                    if (train[min].departureTimeHours > train[i].departureTimeHours) { min = i; }   // Сортування за годинами
                    else if (train[min].departureTimeHours == train[i].departureTimeHours) {
                        if (train[min].departureTimeMinutes > train[i].departureTimeMinutes) { min = i; }   // Сортування за хвилинами
                    }
                }
            }
            std::swap(train[min], train[j]);
        }
        // Вивід
        std::cout << std::setiosflags(std::ios::left);
        std::cout << std::setw(15) << "station"
                  << std::setw(15) << "number train"
                  << std::setw(20) << "departure time" << '\n';

        for (int i = 0; i < size; ++i) {
            std::cout << std::setw(15) << train[i].station
                      << std::setw(15) << train[i].numberTrain;

            if (train[i].departureTimeHours < 10) {
                std::cout << '0' << train[i].departureTimeHours << ':';

                if (train[i].departureTimeMinutes < 10)
                { std::cout << '0' << train[i].departureTimeMinutes << '\n'; }
                else { std::cout << train[i].departureTimeMinutes << '\n'; }
            } else { std::cout << train[i].departureTimeHours << ':';

                if (train[i].departureTimeMinutes < 10)
                { std::cout << '0' << train[i].departureTimeMinutes << '\n'; }
                else { std::cout << train[i].departureTimeMinutes << '\n'; }
            }
        }
    }

    static void SortingTwo(Train* train, int size) {    // Пошук номер вагона
        int infoTrain;
        
        std::cout << "enter number train: ";    // Шукаю вагон
        std::cin >> infoTrain;

        while (infoTrain < 1) {     // Превірка
            std::cout << "// Error\n";
            std::cout << "enter number train: ";
            std::cin >> infoTrain;
        }

        bool haveTrain = false;

        for (int i = 0; i < size; ++i) {    // Якщо є номер вагона - виводжу
            if (train[i].numberTrain == infoTrain) { haveTrain = true; }
        }

        // Якщо немає номера вагона "невиводжу"
        if (!haveTrain) { std::cout << "Not have this number train.\n"; 
                          return; }

        // Якщо є номер вагона - виводжу інформацію
        std::cout << std::setiosflags(std::ios::left);
        std::cout << std::setw(15) << "station"
                  << std::setw(15) << "number train"
                  << std::setw(20) << "departure time" << '\n';

        for (int i = 0; i < size; ++i) {
            if (train[i].numberTrain == infoTrain) {
                std::cout << std::setw(15) << train[i].station
                          << std::setw(15) << train[i].numberTrain;

                if (train[i].departureTimeHours < 10) {
                    std::cout << '0' << train[i].departureTimeHours << ':';

                    if (train[i].departureTimeMinutes < 10)
                    { std::cout << '0' << train[i].departureTimeMinutes << '\n'; }
                    else { std::cout << train[i].departureTimeMinutes << '\n'; }
                } else { std::cout << train[i].departureTimeHours << ':';

                    if (train[i].departureTimeMinutes < 10)
                    { std::cout << '0' << train[i].departureTimeMinutes << '\n'; }
                    else { std::cout << train[i].departureTimeMinutes << '\n'; }
                }
            }
        }
    }

    static void SortingOne(Train* train,  int size) {   // Сортування номерів вагонів
        std::cout << "Before:\n";   // Вивід до
        for (int i = 0; i < size; ++i) { std::cout << train[i].numberTrain << ' '; }
        std::cout << '\n';

        for (int j = 0; j < size; ++j) {    // Сортування номерів вагонів
            int min = j;
            
            for (int i = j; i < size; ++i) {
                if (train[min].numberTrain > train[i].numberTrain) { min = i; }
            }
            std::swap(train[min], train[j]);
        }

        std::cout << "After:\n";    // Вивід після
        for (int i = 0; i < size; ++i) { std::cout << train[i].numberTrain << ' '; }
        std::cout << '\n';
    }
};

int main() {
    const int size = 1;

    Train train[size];

    std::cout << '\n';

    Train::SortingOne(train, size);

    std::cout << '\n';

    Train::SortingTwo(train, size);

    std::cout << '\n';

    Train::SortingThree(train, size);
    return 0;
}