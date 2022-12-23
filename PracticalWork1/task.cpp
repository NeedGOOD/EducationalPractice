#include <iostream>
#include <iomanip>

struct Info {
    std::string surname;        // Прізвище
    std::string name;           // Ім'я
    std::string middleName;     // По батькові

    int salaryType;     // Вибір зарплати

    int shouldDays;     // Має відпрацювати в місяць
    int workedDays;     // Відпрацював в місяць
    int month;          // Місяць

    double salaryInMonth = 15000.0;     // Зарплата в місяць
    double salary = 0.0;                // Скільки заробив
    double premium = 0.0;               // Премія
    double tax = 0.0;                   // Податок

    int workedHours;                // Відпрацював годин

    double hourlyPay;               // Ставка в годину

    double profitReceived;          // Отриманий прибуток
    double myPercentage;            // Мій відсоток
    
    double issueAmount = 0.0;       // Сума до видачі
};

void InterestOnProfits(int size, Info* people) {    // Відсотки від прибутку
    for (int i = 0; i < size; ++i) {
        if (people[i].salaryType == 3) {
            people[i].salary = people[i].profitReceived * (people[i].myPercentage / 100.0);       // Прибуток від відсотока
            people[i].tax = people[i].salary * (19.5 / 100.0);                                  // Податок
            people[i].issueAmount = people[i].salary - people[i].tax;                           // Сума до видачі за день
        }
    }
}

void TimeWorked(int size, Info* people) {   // Відпрацьований час
    for (int i = 0; i < size; ++i) {
        if (people[i].salaryType == 2) {
            people[i].salary = people[i].workedHours * people[i].hourlyPay;     // Зарплата за день
            people[i].tax = people[i].salary * (19.5 / 100.0);                  // Податок
            people[i].issueAmount = people[i].salary - people[i].tax;           // Сума до видачі за день
        }
    }
}

void Salaries(int size, Info* people) {     // Посадовий оклад
    for (int i = 0; i < size; ++i) {
        if (people[i].salaryType == 1) {
            people[i].salary = people[i].salaryInMonth / people[i].shouldDays * people[i].workedDays;   // Головна зарплата

            // Премія 25% за всі відпрацьовані дні
            if (people[i].shouldDays == people[i].workedDays) { people[i].premium = people[i].salary * (25.0 / 100.0); }
            // Просто премія 10%
            else if (people[i].shouldDays != people[i].workedDays) { people[i].premium = people[i].salary * (10.0 / 100.0); }

            people[i].tax = (people[i].salary + people[i].premium) * (19.5 / 100.0);        // Податок
            people[i].issueAmount = people[i].salary + people[i].premium - people[i].tax;   // Сума до видачі за місяць
        }
    }
}

void Result(int size, Info* people) {   // Вивід результату
    system("cls");
    std::cout << std::setiosflags(std::ios::left);
    std::cout << std::setw(5) << '#'
              << std::setw(13) << "Salary type"
              << std::setw(15) << "Surname"
              << std::setw(15) << "Name"
              << std::setw(17) << "Middle name"
              << std::setw(15) << "Salary" << '\n';
    
    for (int i = 0; i < size; ++i) {
        std::cout << std::setw(5) << i + 1
                  << std::setw(13) << people[i].salaryType
                  << std::setw(15) << people[i].surname
                  << std::setw(15) << people[i].name
                  << std::setw(17) << people[i].middleName;

        if (people[i].salaryType == 1) { std::cout << std::setw(15) << people[i].issueAmount; }
        if (people[i].salaryType == 2) { std::cout << std::setw(15) << people[i].issueAmount; }
        if (people[i].salaryType == 3) { std::cout << std::setw(15) << people[i].issueAmount; }
        std::cout << '\n';
    }
    std::cout << '\n';
}

int main() {        // Введення інформації
    const int size = 10;     // Кількість робітників

    Info people[size];

    std::cout << "Select salary:\n"
              << "1 - Salaries;\n"
              << "2 - Time worked;\n"
              << "3 - Interest from the profit received.\n\n";

    for (int i = 0; i < size; ++i) {
        std::cout << "Salary selection: ";
        std::cin >> people[i].salaryType;      // Вибір зарплати

        while (people[i].salaryType < 1 || people[i].salaryType > 3) {    // Перевірка
            std::cout << "\n// Error: you not right choice!\n";
            std::cout << "Salary selection: ";
            std::cin >> people[i].salaryType;
        }
        std::cout << "Surname: ";
        std::cin >> people[i].surname;      // Призвіща

        while (people[i].surname < "A" || people[i].surname > "Z") {          // Перевірка
            std::cout << "\n// Error: surname writes this BIG word!\n";
            std::cout << "Surname: ";
            std::cin >> people[i].surname;
        }
        std::cout << "Name: ";
        std::cin >> people[i].name;         // Ім'я

        while (people[i].name < "A" || people[i].name > "Z") {                // Перевірка
            std::cout << "\n// Error: name writes this BIG word!\n";
            std::cout << "Name: ";
            std::cin >> people[i].name;
        }
        std::cout << "Middle name: ";
        std::cin >> people[i].middleName;   // По батькові

        while (people[i].middleName < "A" || people[i].middleName > "Z") {    // Перевірка
            std::cout << "\n// Error: Middle name writes this BIG word!\n";
            std::cout << "Middle name: ";
            std::cin >> people[i].middleName;
        }

        if (people[i].salaryType == 1) {            // Зарплата в місяць
            std::cout << "Choose month:\n"          // Вибір місяця
                      << "\t1 - January;\n"
                      << "\t2 - February;\n"
                      << "\t3 - March;\n"
                      << "\t4 - April;\n"
                      << "\t5 - May;\n"
                      << "\t6 - June;\n"
                      << "\t7 - July;\n"
                      << "\t8 - August;\n"
                      << "\t9 - September;\n"
                      << "\t10 - October;\n"
                      << "\t11 - November;\n"
                      << "\t12 - December.\n";
            std::cout << "In what month: ";
            std::cin >> people[i].month;            // За який місяць
            
            while (people[i].month < 1 || people[i].month > 12) {               // Перевірка
                std::cout << "\n// Error: year have a from 1 to 12 months!\n";
                std::cout << "In what month: ";
                std::cin >> people[i].month;
            }
            
            if (people[i].month == 1) {             // Січень
                std::cout << "How many days do you have to work in a month: ";
                std::cin >> people[i].shouldDays;       // Повиний відпрацювати
                
                while (people[i].shouldDays < 1 || people[i].shouldDays > 31) {         // Перевірка
                    std::cout << "\n// Error: this month have a from 1 to 31 days!\n";
                    std::cout << "How many days do you have to work in a month: ";
                    std::cin >> people[i].shouldDays;
                }
            } else if (people[i].month == 2) {      // Лютий
                std::cout << "How many days do you have to work in a month: ";
                std::cin >> people[i].shouldDays;       // Повиний відпрацювати
                
                while (people[i].shouldDays < 1 || people[i].shouldDays > 29) {         // Перевірка
                    std::cout << "\n// Error: this month have a from 1 to 29 days!\n";
                    std::cout << "How many days do you have to work in a month: ";
                    std::cin >> people[i].shouldDays;
                }
            } else if (people[i].month == 3) {      // Березень
                std::cout << "How many days do you have to work in a month: ";
                std::cin >> people[i].shouldDays;       // Повиний відпрацювати
            
                while (people[i].shouldDays < 1 || people[i].shouldDays > 31) {         // Перевірка
                    std::cout << "\n// Error: this month have a from 1 to 31 days!\n";
                    std::cout << "How many days do you have to work in a month: ";
                    std::cin >> people[i].shouldDays;
                }
            } else if (people[i].month == 4) {      // Квітень
                std::cout << "How many days do you have to work in a month: ";
                std::cin >> people[i].shouldDays;       // Повиний відпрацювати
            
                while (people[i].shouldDays < 1 || people[i].shouldDays > 30) {         // Перевірка
                    std::cout << "\n// Error: this month have a from 1 to 30 days!\n";
                    std::cout << "How many days do you have to work in a month: ";
                    std::cin >> people[i].shouldDays;
                }
            } else if (people[i].month == 5) {      // Травень
                std::cout << "How many days do you have to work in a month: ";
                std::cin >> people[i].shouldDays;       // Повиний відпрацювати
            
                while (people[i].shouldDays < 1 || people[i].shouldDays > 31) {         // Перевірка
                    std::cout << "\n// Error: this month have a from 1 to 31 days!\n";
                    std::cout << "How many days do you have to work in a month: ";
                    std::cin >> people[i].shouldDays;
                }
            } else if (people[i].month == 6) {      // Червень
                std::cout << "How many days do you have to work in a month: ";
                std::cin >> people[i].shouldDays;       // Повиний відпрацювати
            
                while (people[i].shouldDays < 1 || people[i].shouldDays > 30) {         // Перевірка
                    std::cout << "\n// Error: this month have a from 1 to 30 days!\n";
                    std::cout << "How many days do you have to work in a month: ";
                    std::cin >> people[i].shouldDays;
                }
            } else if (people[i].month == 7) {      // Липень
                std::cout << "How many days do you have to work in a month: ";
                std::cin >> people[i].shouldDays;       // Повиний відпрацювати
            
                while (people[i].shouldDays < 1 || people[i].shouldDays > 31) {         // Перевірка
                    std::cout << "\n// Error: this month have a from 1 to 31 days!\n";
                    std::cout << "How many days do you have to work in a month: ";
                    std::cin >> people[i].shouldDays;
                }
            } else if (people[i].month == 8) {      // Серпень
                std::cout << "How many days do you have to work in a month: ";
                std::cin >> people[i].shouldDays;       // Повиний відпрацювати
            
                while (people[i].shouldDays < 1 || people[i].shouldDays > 31) {         // Перевірка
                    std::cout << "\n// Error: this month have a from 1 to 31 days!\n";
                    std::cout << "How many days do you have to work in a month: ";
                    std::cin >> people[i].shouldDays;
                }
            } else if (people[i].month == 9) {      // Вересень
                std::cout << "How many days do you have to work in a month: ";
                std::cin >> people[i].shouldDays;       // Повиний відпрацювати
            
                while (people[i].shouldDays < 1 || people[i].shouldDays > 30) {         // Перевірка
                    std::cout << "\n// Error: this month have a from 1 to 30 days!\n";
                    std::cout << "How many days do you have to work in a month: ";
                    std::cin >> people[i].shouldDays;
                }
            } else if (people[i].month == 10) {     // Жовтень
                std::cout << "How many days do you have to work in a month: ";
                std::cin >> people[i].shouldDays;       // Повиний відпрацювати
            
                while (people[i].shouldDays < 1 || people[i].shouldDays > 31) {         // Перевірка
                    std::cout << "\n// Error: this month have a from 1 to 31 days!\n";
                    std::cout << "How many days do you have to work in a month: ";
                    std::cin >> people[i].shouldDays;
                }
            } else if (people[i].month == 11) {     // Листопад
                std::cout << "How many days do you have to work in a month: ";
                std::cin >> people[i].shouldDays;       // Повиний відпрацювати
            
                while (people[i].shouldDays < 1 || people[i].shouldDays > 30) {         // Перевірка
                    std::cout << "\n// Error: this month have a from 1 to 30 days!\n";
                    std::cout << "How many days do you have to work in a month: ";
                    std::cin >> people[i].shouldDays;
                }
            } else if (people[i].month == 12) {     // Грудень
                std::cout << "How many days do you have to work in a month: ";
                std::cin >> people[i].shouldDays;       // Повиний відпрацювати
            
                while (people[i].shouldDays < 1 || people[i].shouldDays > 31) {         // Перевірка
                    std::cout << "\n// Error: this month have a from 1 to 31 days!\n";
                    std::cout << "How many days do you have to work in a month: ";
                    std::cin >> people[i].shouldDays;
                }
            }
            std::cout << "How many days did you work in a month: ";
            std::cin >> people[i].workedDays;       // Відпрацював на ділі
            
            while (people[i].workedDays < 0 || people[i].workedDays > people[i].shouldDays) {       // Перевірка
                std::cout << "\n// Error: enter a number from 0 to " << people[i].shouldDays << "!\n";
                std::cout << "How many days did you work in a month: ";
                std::cin >> people[i].workedDays;
            }
        }
        
        if (people[i].salaryType == 2) {     // Зарплата за день
            std::cout << "How much you worked today: ";
            std::cin >> people[i].workedHours;      // Відпрацював годин

            while (people[i].workedHours < 1 || people[i].workedHours > 24) {         // Перевірка
                std::cout << "\nError: day have a from 0 to 24 hours!\n";
                std::cout << "How much you worked hours today: ";
                std::cin >> people[i].workedHours;
            }
            std::cout << "Your hourly rate: ";
            std::cin >> people[i].hourlyPay;        // Погодинна оплата

            while (people[i].hourlyPay < 0) {
                std::cout << "\n// Error: do you owe someone?\n";
                std::cout << "Your hourly rate: ";
                std::cin >> people[i].hourlyPay;
            }
        }
        
        if (people[i].salaryType == 3) {     // Відсотки від прибутку
            std::cout << "How your got profit many: ";
            std::cin >> people[i].profitReceived;   // Прибуток

            std::cout << "How much your interest: ";
            std::cin >> people[i].myPercentage;     // Відсоток

            while (people[i].myPercentage < 0 || people[i].myPercentage > 100) {    // Перевірка
                std::cout << "\nError: interest have a from 0 to 100 number!\n";
                std::cout << "How much your interest: ";
                std::cin >> people[i].myPercentage;
            }
        }
        std::cout << '\n';
    }
    Salaries(size, people);
    TimeWorked(size, people);
    InterestOnProfits(size, people);
    Result(size, people);
    return 0;
}