#include <iostream>
#include <iomanip>

class Train {
private:
    std::string station;

    int numberTrain;
    int departureTime;
public:
    Train() {
        std::cout << "station: ";
        std::cin >> station;

        std::cout << "number train: ";
        std::cin >> numberTrain;

        while (numberTrain < 1) {
            std::cout << "// Error\n";
            std::cout << "Number train: ";
            std::cin >> numberTrain;
        }
        std::cout << "departure time (hours): ";
        std::cin >> departureTime;

        while (departureTime < 1) {
            std::cout << "// Error\n";
            std::cout << "departure time (hours): ";
            std::cin >> departureTime;
        }
    }

    std::string GetStation() { return station; }
    int GetNumberTrain() { return numberTrain; }
    int GetDepartureTime() { return departureTime; }    
};

void SortingThree(Train* train, int size) {
    for (int j = 0; j < size; ++j) {
        int min = j;

        for (int i = j; i < size; ++i) {
            if (train[min].GetStation() > train[i].GetStation()) { min = i; }
            else if (train[min].GetStation() == train[i].GetStation()) {
                if (train[min].GetDepartureTime() > train[i].GetDepartureTime()) { min = i; }
            }
        }
        std::swap(train[min], train[j]);
    }

    //for (int j = 0; j < size; ++j) {
        //int min = j;

        //for (int i = j; i < size; ++i) {
            //if (train[min].GetDepartureTime() > train[i].GetDepartureTime()) { min = i; }
        //}
        //std::swap(train[min], train[j]);
    //}

    std::cout << std::setiosflags(std::ios::left);
    std::cout << std::setw(15) << "station" << std::setw(15) << "number train"
              << std::setw(20) << "departure time" << '\n';

    for (int i = 0; i < size; ++i) {
        std::cout << std::setw(15) << train[i].GetStation() << std::setw(15) << train[i].GetNumberTrain()
                  << std::setw(20) << train[i].GetDepartureTime() << '\n';
    }
}

void SortingTwo(Train* train, int size) {
        int infoTrain;
        
        std::cout << "enter number train: ";
        std::cin >> infoTrain;

        while (infoTrain < 1) {
            std::cout << "// Error\n";
            std::cout << "enter number train: ";
            std::cin >> infoTrain;
        }

        bool haveTrain = false;

        for (int i = 0; i < size; ++i) {
            if (train[i].GetNumberTrain() == infoTrain) {
                std::cout << std::setiosflags(std::ios::left);
                std::cout << std::setw(15) << "station" << std::setw(15) << "number train"
                          << std::setw(20) << "departure time" << '\n';
                std::cout << std::setw(15) << train[i].GetStation() << std::setw(15) << train[i].GetNumberTrain()
                          << std::setw(20) << train[i].GetDepartureTime() << '\n';
                haveTrain = true;
            }
        }

        if (!haveTrain) { std::cout << "Not have this number train.\n"; }
}

void SortingOne(Train* train, int size) {
    std::cout << "Before:\n";
    for (int i = 0; i < size; ++i) { std::cout << train[i].GetNumberTrain() << ' '; }
    std::cout << '\n';

    for (int j = 0; j < size; ++j) {
        int min = j;
        
        for (int i = j; i < size; ++i) {
            if (train[min].GetNumberTrain() > train[i].GetNumberTrain()) { min = i; }
        }
        std::swap(train[min], train[j]);
    }

    std::cout << "After:\n";
    for (int i = 0; i < size; ++i) { std::cout << train[i].GetNumberTrain() << ' '; }
    std::cout << '\n';
}

int main() {
    const int size = 3;

    Train train[size];

    std::cout << '\n';

    SortingOne(train, size);

    std::cout << '\n';

    SortingTwo(train, size);

    std::cout << '\n';

    SortingThree(train, size);
    return 0;
}
