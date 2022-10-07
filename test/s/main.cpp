#include <iostream>
#include <iomanip>
#include <string>


struct Info {
	std::string surname;	//�������
	std::string name;		//���
	std::string middleName;	//��������
	
	int workedFirst;	//��������� ����
	int workedSecond;	//��������� �����
	int workedThird;	//��������� �������
	
	int workingMonth;	//������� ���� ������
	int workingTime;	//������� ����� � �����
	int workingPercent;	//������� �� �������
	
	int ID;				//ID
	
	float salaryMonth = 10000.0;	//����������� ����� 10.000 ���
	float salaryTime = 62.5;		//������ �� ��� 62.5 ���
	float salaryPercent;			//�������
	
	float taxMonth = 0.0;			//����� �� �����
	float taxTime = 0.0;			//����� �� �����
	float taxPercent = 0.0;			//����� �� �������
	
	float wageMonth = 0.0;			//���������� �����
	float wageTime = 0.0;			//������������ �����
	float wagePercent = 0.0;		//���������� �� �������
	
	float prize = 0.0;				//������
	
	float sumMonth = 0.0;			//����� �� �����
	float sumTime = 0.0;			//����� �� �����
	float sumPercent = 0.0;			//����� �� �������
};

void OS(Info* info, int size) {	//����������� �����
	for (int i = 0; i < size; ++i) {
		if (info[i].ID == 1) {
			info[i].wageMonth = info[i].salaryMonth / info[i].workingMonth * info[i].workedFirst;	//���������� �����
			
			if (info[i].workingMonth == info[i].workedSecond) {		//��������� ��� ��� � ������� �� 25% ������
				info[i].prize = info[i].wageMonth / 100 * 25;
			} else if (info[i].workingMonth > info[i].workedSecond) {	//��������� �� ��� ��� � ������� �� 10% ������
				info[i].prize = info[i].wageMonth / 100 * 10;
			}
			info[i].taxMonth = info[i].wageMonth * 19.5 / 100;							//�����
			info[i].sumMonth = info[i].wageMonth + info[i].prize - info[i].taxMonth;	//����� � ������
		}
	}
}

void TW(Info* info, int size) {	//������������ �����
	for (int i = 0; i < size; ++i) {
		if (info[i].ID == 2) {
			info[i].wageTime = info[i].workedSecond * info[i].salaryTime;	//���������� ����� �� �����
			info[i].taxTime = info[i].wageTime * 19.5 / 100;				//�����
			info[i].sumTime = info[i].wageTime - info[i].taxTime;			//����� � ������
		}
	}
}

void IP(Info* info, int size) {	//������������ �� �������
	for (int i = 0; i < size; ++i) {
		if (info[i].ID == 3) {
			info[i].wagePercent = info[i].workedThird / 100 * info[i].workingPercent;	//���������� ����� �� �������
			info[i].taxPercent = info[i].wagePercent * 19.5 / 100;						//�����
			info[i].sumPercent = info[i].wagePercent - info[i].taxPercent;				//����� � ������
		}
	}
}

void result(Info* info, int size) {	//����� ����������
	system("cls");	//������� �������
	std::cout << std::setiosflags(std::ios::left);
	std::cout << std::setw(3) << "ID" << std::setw(15) << "Surname" << std::setw(15) << "Name";
	std::cout << std::setw(15) << "Middle name" << std::setw(15) << "Salary" << '\n';
	
	for (int i = 0; i < size; ++i) {
		std::cout << std::setw(3) << info[i].ID << std::setw(15) << info[i].surname;
		std::cout << std::setw(15) << info[i].name << std::setw(15) << info[i].middleName;
		
		if (info[i].ID == 1) {	//����������� �����
			std::cout << std::setw(15) << info[i].sumMonth;
		}
		
		if (info[i].ID == 2) {	//������������ �����
			std::cout << std::setw(15) << info[i].sumTime;
		}
		
		if (info[i].ID == 3) {	//������������ �� �������
			std::cout << std::setw(15) << info[i].sumPercent;
		}
		std::cout << '\n';
	}
}

int main(int argc, char** argv) {
	std::cout << "\t\t<Practical Work 30-31.1>\n\n";
	std::cout << "ID:\n";
	std::cout << "1 - Salary;\n";					//����������� �����
	std::cout << "2 - Time worked;\n";				//������������ �����
	std::cout << "3 - Interest on profits.\n\n";	//�������� �� ���������� �������
	
	const int size = 1;	//���������� �������
	
	Info people[size];	//������
	
	for (int i = 0; i < size; ++i) {
		std::cout << "ID: ";			//����� ID
		std::cin >> people[i].ID;
		
		std::cin.get();	//��������� Enter
		
		if (people[i].ID < 1 || people[i].ID > 3) {	//������
			system("cls");	//������� �������
			std::cout << "Error: Restart Application.\n";
			return 0;
		}
		std::cout << "Surname: ";		//����� �������
		getline(std::cin, people[i].surname);
		
		std::cout << "Name: ";			//����� ���
		getline(std::cin, people[i].name);
		
		std::cout << "Middle name: ";	//����� ��������
		getline(std::cin, people[i].middleName);
		
		if (people[i].ID == 1) {
			//����� ���������� ���� ������� ����� ���������� � �����
			std::cout << "You need to work a month: ";
			std::cin >> people[i].workingMonth;
			
			if (people[i].workingMonth < 1 || people[i].workingMonth > 31) {	//������
				system("cls");	//������� �������
				std::cout << "Error: Restart Application.\n";
				return 0;
			}
			//����� ���������� ���� ������� ���������
			std::cout << "You have worked: ";
			std::cin >> people[i].workedFirst;
			
			if (people[i].workedFirst < 1 || people[i].workedFirst > people[i].workingMonth) {	//������
				system("cls");	//������� �������
				std::cout << "Error: Restart Application.\n";
				return 0;
			}
		}
		
		if (people[i].ID == 2) {
			//����� ���������� ����� ������� ����� ���������� � �����
			std::cout << "You need to work hours a month: ";
			std::cin >> people[i].workingTime;
			
			if (people[i].workingTime < 0 || people[i].workingTime > 248) {	//������
				system("cls");	//������� �������
				std::cout << "Error: Restart Application.\n";
				return 0;
			}
			//����� ���������� ����� ������� ���������
			std::cout << "You have worked: ";
			std::cin >> people[i].workedSecond;
			
			if (people[i].workedSecond < 0 || people[i].workedSecond > people[i].workingTime) {	//������
				system("cls");	//������� �������
				std::cout << "Error: Restart Application.\n";
				return 0;
			}
		}
		
		if (people[i].ID == 3) {
			//����� ���������� ��������� �� ���������
			std::cout << "Interest under the contract (5-10%): ";
			std::cin >> people[i].workingPercent;
			
			if (people[i].workingPercent < 5 || people[i].workingPercent > 10) {	//������
				system("cls");	//������� �������
				std::cout << "Error: Restart Application.\n";
				return 0;
			}
			//����� ����������� �����
			std::cout << "Amount earned: ";
			std::cin >> people[i].workedThird;
			
			if (people[i].workedThird < 0) {	//������
				system("cls");	//������� �������
				std::cout << "Error: Restart Application.\n";
				return 0;
			}
		}
		std::cout << '\n';
	}
	OS(people, size);		//������� ���������� ���� ������
	TW(people, size);		//������� ���������� ���� ������
	IP(people, size);		//������� ���������� ���� ������
	result(people, size);	//������� ���������� ���� ������
	return 0;
}
