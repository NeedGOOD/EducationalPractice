#include <iostream>

struct Point {
    double x = 0.0;     // Точка x
    double y = 0.0;     // Точка y
};

class EquilateralTrapezium {
private:
    // Координати
    Point A;
    Point B;
    Point C;
    Point D;

    // Сторони
    double AB = 0.0;
    double BC = 0.0;
    double CD = 0.0;
    double DA = 0.0;

    // Сторони
    double a = 0.0;
    double b = 0.0;
    double c = 0.0;
    double d = 0.0;

    double perimeter = 0.0;     // Периметр

    double h = 0.0;             // Висота

    double area = 0.0;          // Площа
public:
    EquilateralTrapezium(Point pointA, Point pointB, Point pointC, Point pointD) {
        A = pointA;
        B = pointB;
        C = pointC;
        D = pointD;
    }

    void Calculation() {    // Розрахунки
        AB = sqrt(pow(B.x - A.x, 2) + pow(B.y - A.y, 2));
        BC = sqrt(pow(C.x - B.x, 2) + pow(C.y - B.y, 2));
        CD = sqrt(pow(D.x - C.x, 2) + pow(D.y - C.y, 2));
        DA = sqrt(pow(A.x - D.x, 2) + pow(A.y - D.y, 2));

        a = DA;
        b = BC;
        c = AB;
        d = CD;

        std::cout << "Sides:\n"     // Сторони
                  << "a = " << a << '\n'
                  << "b = " << b << '\n'
                  << "c = " << c << '\n'
                  << "d = " << d << '\n';

        perimeter = a + b + c + d;      // Периметр

        std::cout << "Perimeter = " << perimeter << '\n';

        h = (1.0 / 2.0) * sqrt(4.0 * pow(c, 2) - pow(a - b, 2));    // Висота

        area = ((a + b) / 2.0) * h;     // Площа
        
        std::cout << "Area = " << area << '\n';
    }

    double GetArea() { return area; }

    void Result() {     // Перевірка чи є вона рівнобічною
        double AC = sqrt(pow(C.x - A.x, 2) + pow(C.y - A.y, 2));
        double BD = sqrt(pow(D.x - B.x, 2) + pow(D.y - B.y, 2));

        if (AC == BD) { std::cout << "The figure is an equilateral trapezoid.\n"; } // Так
        else { std::cout << "The figure is not an isosceles trapezoid.\n"; }    // Ні
    }
};

int main() {
    const int size = 2;

    EquilateralTrapezium trapeze[size] = {
        {{-5.5, -3}, {-3, 3}, {3, 3}, {5.5, -3}},
        {{-5, 3}, {6, -2}, {5, -9}, {2, 0}}
    };
    
    std::cout << "First:\n";
    trapeze[0].Result();
    trapeze[0].Calculation();

    std::cout << "\nSecond:\n";
    trapeze[1].Result();
    trapeze[1].Calculation();

    std::cout << '\n';

    double average = 0.0;   // Середнє

    for (int i = 0; i < size; ++i) { average += trapeze[i].GetArea(); }
    
    average /= size;

    int bigAverage = 0;

    for (int i = 0; i < size; ++i) {
        if (average < trapeze[i].GetArea()) { ++bigAverage; }
    }
    std::cout << "Have average: " << bigAverage << '\n';
    return 0;
}