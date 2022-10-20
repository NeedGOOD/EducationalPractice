#include <iostream>

class Prism {
private:
    double height = 0.0;            // Висота
    double numberOfFaces = 0.0;     // Грані
    double lengthOfSides = 0.0;     // Довжина
    double baseArea = 0.0;          // Площа
public:
    Prism(double height, double numberOfFaces, double lengthOfSides, double baseArea) :
    height(height), numberOfFaces(numberOfFaces), lengthOfSides(lengthOfSides), baseArea(baseArea) {}

    double GetAmount() { return height * baseArea; }
    double GetHeight() { return height; }
    double GetNumberOfFaces() { return numberOfFaces; }
    double GetLengthOfSides() { return lengthOfSides; }
    double GetBaseArea() { return baseArea; }

    void SetHeight(double newValue) { height = newValue; }
    void SetNumberOfFaces(double newValue) { numberOfFaces = newValue; }
    void SetLengthOfSides(double newValue) { lengthOfSides = newValue; }
    void SetBaseArea(double newValue) { baseArea = newValue; }

    void Result() {     // Вивід
        std::cout << "amount = " << GetAmount() << '\n';
        std::cout << "height = " << height << '\n';
        std::cout << "number of faces = " << numberOfFaces << '\n';
        std::cout << "leghth of sides = " << lengthOfSides << '\n';
        std::cout << "base area = " << baseArea << '\n';
    }
};

int main() {
    double height;  // Висота

    std::cout << "height: ";
    std::cin >> height;

    double length;  // Довжина

    std::cout << "lenght: ";
    std::cin >> length;

    double numberOfFace;    // Грані

    std::cout << "number of face: ";
    std::cin >> numberOfFace;

    double area;        // Площа

    std::cout << "area: ";
    std::cin >> area;
    std::cout << '\n';

    Prism prism(height, numberOfFace, length, area);

    prism.Result();
    return 0;
}