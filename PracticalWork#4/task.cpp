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
        std::cout << "Amount = " << GetAmount() << '\n';
        std::cout << "Height = " << height << '\n';
        std::cout << "Number of faces = " << numberOfFaces << '\n';
        std::cout << "Leghth of sides = " << lengthOfSides << '\n';
        std::cout << "Base area = " << baseArea << '\n';
    }
};

int main() {
    double height;  // Висота

    std::cout << "Height: ";
    std::cin >> height;

    double length;  // Довжина

    std::cout << "Lenght: ";
    std::cin >> length;

    double numberOfFace;    // Грані

    std::cout << "Number of face: ";
    std::cin >> numberOfFace;

    double area;        // Площа

    std::cout << "Area: ";
    std::cin >> area;
    std::cout << '\n';

    Prism prism(height, numberOfFace, length, area);

    prism.Result();
    return 0;
}