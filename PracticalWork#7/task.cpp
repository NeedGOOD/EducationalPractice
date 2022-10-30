#include <iostream>
#include <iomanip>

class Trucks {
private:
    double massCargo;               // Маса вантажу
    double transportationRange;     // Дальність перевезення

    int typeCargo;                  // Тип вантажу

    std::string stringTypeCargo() {
        switch (typeCargo) {
        case 1: return "Usual";         // Звичайний
        case 2: return "Oversized";     // Негабаритні
        case 3: return "Flammable";     // Вогненебезпечні
        default: return "???";          // ???
        }
    }
public:
    Trucks() {
        std::cout << "Mass of cargo(tons): "; //  Маса вантажу
        std::cin >> massCargo;

        while (massCargo <= 0) {         // Перевірка
            std::cout << "// Error\n";
            std::cout << "Mass of cargo(tons): ";
            std::cin >> massCargo;
        }
        std::cout << "Transportation range(km): ";  // Дальність перевезення
        std::cin >> transportationRange;

        while (transportationRange <= 0) {   // Перевірка
            std::cout << "// Error\n";
            std::cout << "Transportation range(km): ";
            std::cin >> transportationRange;
        }
        std::cout << "Type of cargo:\n"     // Тип вантажу
                  << "\t1 - Usual;\n"         // Звичайний
                  << "\t2 - Oversized;\n"     // Негабаритні
                  << "\t3 - Flammable.\n";    // Вогненебезпечні
        std::cout << "~ ";
        std::cin >> typeCargo;

        while (typeCargo < 1 || typeCargo > 3) {    // Перевірка
            std::cout << "// Error\n";
            std::cout << "Type of cargo:\n"
                  << "\t1 - Usual;\n"           // Звичайний
                  << "\t2 - Oversized;\n"       // Негабаритні
                  << "\t3 - Flammable.\n";      // Вогненебезпечні
            std::cout << "~ ";
            std::cin >> typeCargo;
        }
    }

    static void BigMass(Trucks* trucks, int size) { // Виведення більше маси
        int enterMass;

        std::cout << "Enter mass: ";
        std::cin >> enterMass;

        while (enterMass < 0) {     // Перевірка
            std::cout << "// Error\n";
            std::cout << "Enter mass: ";
            std::cin >> enterMass;
        }
        std::cout << '\n';
        // Вивід
        std::cout << std::setiosflags(std::ios::left);
        std::cout << std::setw(20) << "Mass of cargo"
                  << std::setw(25) << "Transportation range"
                  << std::setw(15) << "Type of cargo" << '\n';

        for (int i = 0; i < size; ++i) {
            if (trucks[i].massCargo > enterMass) {
                std::cout << std::setw(20) << trucks[i].massCargo
                          << std::setw(25) << trucks[i].transportationRange
                          << std::setw(15) << trucks[i].stringTypeCargo() << '\n';
            }
        }
    }

    static void SortingRange(Trucks* trucks, int size) {    // Сортування дальності перевезення
        for (int j = 0; j < size; ++j) {    // Сортування
            int min = j;
            
            for (int i = j; i < size; ++i) {
                if (trucks[min].transportationRange > trucks[i].transportationRange) { min = i; }
            }
            std::swap(trucks[min], trucks[j]);
        }
        // Вивід
        std::cout << std::setiosflags(std::ios::left);
        std::cout << std::setw(20) << "Mass of cargo"
                  << std::setw(25) << "Transportation range"
                  << std::setw(15) << "Type of cargo" << '\n';

        for (int i = 0; i < size; ++i) {
            std::cout << std::setw(20) << trucks[i].massCargo
                      << std::setw(25) << trucks[i].transportationRange
                      << std::setw(15) << trucks[i].stringTypeCargo() << '\n';
        }
    }

    static void Result(Trucks* trucks, int size) {  // Певний тип вантажу
        int enterTypeCargo;

        std::cout << "Enter type cargo:\n"
                  << "\t1 - Usual;\n"           // Звичайний
                  << "\t2 - Oversized;\n"       // Негабаритні
                  << "\t3 - Flammable.\n";      // Вогненебезпечні
        std::cout << "~ ";
        std::cin >> enterTypeCargo;

        while (enterTypeCargo < 1 || enterTypeCargo > 3) {  // Перевірка
            std::cout << "// Error\n";
            std::cout << "Enter type cargo:\n"
                      << "\t1 - Usual;\n"           // Звичайний
                      << "\t2 - Oversized;\n"       // Негабаритні
                      << "\t3 - Flammable.\n";      // Вогненебезпечні
            std::cout << "~ ";
            std::cin >> enterTypeCargo;
        }
        std::cout << '\n';

        bool haveTypeCargo = false;

        for (int i = 0; i < size; ++i) {
            if (trucks[i].typeCargo == enterTypeCargo) { haveTypeCargo = true; }
        }
        // Вивід, якщо немає
        if (!haveTypeCargo) { std::cout << "Not have this type cargo.\n";
                              return; }
        // Вивід, якщо є
        std::cout << std::setiosflags(std::ios::left);
        std::cout << std::setw(20) << "Mass of cargo"
                  << std::setw(25) << "Transportation range"
                  << std::setw(15) << "Type of cargo" << '\n';

        for (int i = 0; i < size; ++i) {
            if (trucks[i].typeCargo == enterTypeCargo)
            { std::cout << std::setw(20) << trucks[i].massCargo
                        << std::setw(25) << trucks[i].transportationRange
                        << std::setw(15) << trucks[i].stringTypeCargo() << '\n'; }
        }
    }
};

int main() {
    const int size = 2;

    Trucks trucks[size];

    std::cout << '\n';

    Trucks::Result(trucks, size);

    std::cout << '\n';

    Trucks::SortingRange(trucks, size);

    std::cout << '\n';
    
    Trucks::BigMass(trucks, size);
    return 0;
}