#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

struct Discipline // Структура дисциплина
{
	string name; // Название дисциплины
	int grade;	 // Оценка
};

struct Student // Структура студент
{
	string fio;						// ФИО
	vector<Discipline> disciplines; // Массив дисциплин
};

int main(int argc, char *argv[])
{
	int n; // Число элементов массива
	cout << "n=";
	cin >> n;
	vector<Student> pS(n); // Используем вектор в качестве массива

	for (int i = 0; i < n; i++) // Цикл ввода данных с клавиатуры
	{
		cout << "Student N=" << i + 1;
		cout << endl
			 << "FIO: ";
		cin.ignore();
		getline(cin, pS[i].fio);

		int m; // Число дисциплин у студента
		do
		{
			cout << "The count of disciplines: ";
			cin >> m;
			if (m < 4)
				cout << "  Incorrect! The count of disciplines must be at least 4." << endl;
		} while (m < 4);
		pS[i].disciplines.resize(m);

		for (int j = 0; j < m; j++) // Цикл ввода дисциплин
		{
			cout << "  Disciplina N=" << j + 1 << endl;
			cout << "  Name: ";
			cin.ignore();
			getline(cin, pS[i].disciplines[j].name);
			do
			{
				cout << "  assessment (1..5): ";
				cin >> pS[i].disciplines[j].grade;
				if (pS[i].disciplines[j].grade < 1 || pS[i].disciplines[j].grade > 5)
					cout << "  Incorrect! The assessment should be from 1 to 5." << endl;
			} while (pS[i].disciplines[j].grade < 1 || pS[i].disciplines[j].grade > 5);
		}
	}

	for (int i = 0; i < n; i++) // Цикл печати введенных данных
	{
		cout << endl
			 << pS[i].fio;
		for (int j = 0; j < (int)pS[i].disciplines.size(); j++)
			cout << " | " << pS[i].disciplines[j].name
				 << " = " << pS[i].disciplines[j].grade;
	}

	string DiscName; // Название дисциплины для поиска
	cout << endl
		 << "Disciplina Name: ";
	cin.ignore();
	getline(cin, DiscName);

	double sum = 0;												// Сумма оценок по заданной дисциплине
	int k = 0;													// Количество найденных оценок
	for (int i = 0; i < n; i++)									// Просматриваем всех студентов
		for (int j = 0; j < (int)pS[i].disciplines.size(); j++) // Просматриваем все дисциплины
			if (DiscName == pS[i].disciplines[j].name)
			{
				sum += pS[i].disciplines[j].grade;
				k++;
			}
	if (k) // Если найдены оценки
		cout << fixed << setprecision(2)
			 << "average score = " << sum / k << " (k=" << k << ")" << endl;
	else
		cout << "Not found" << endl; 

	system("pause"); // Останавливаем программу, ждем нажатия любой клавиши
	return 0;
}
