#include <vector>
#include <string>
#include <iostream>
#include "Bodies.h"

using namespace std;

int main()
{
	bool reading = true;
	setlocale(LC_ALL, "Russian");
	vector<CBody*> bodies;
	int num;
	while (reading)
	{
		cout << "Введите номер фигуры" << endl
			<< "1 - Циллиндр" << endl
			<< "2 - Сфера" << endl
			<< "3 - Конус" << endl
			<< "4 - Параллелепипед" << endl
			<< "5 - Информация о всех фигурах" << endl
			<< "6 - Тело с наибольшей массой" << endl
			<< "7 - Тело с наименьшим весом в воде" << endl
			<< "8 - Составить составное тело" << endl
			<< " - любая другая клавиша выход" << endl;
		cin >> num;
		switch (num)
		{
		case 1:
			AddCyllinder(cin, bodies);
			break;
		case 2:
			AddSphere(cin, bodies);
			break;
		case 3:
			AddCone(cin, bodies);
			break;
		case 4:
			AddParallelepiped(cin, bodies);
			break;
		case 5:
			PrintAllInfo(cout, bodies);
			break;
		case 6:
			if (bodies.size() > 0)
			{
				cout << "Самое тяжелое тело " << FindMostMassBody(bodies)->ToString();
			}
			else
			{
				cout << "У вас еще нет добавленных тел" << endl;
			}
			break;
		case 7:
			if (bodies.size() > 0)
			{
				cout << "Самое легкое тело, погруженное в воду " << FindLessWaterWeightBody(bodies)->ToString();
			}
			else
			{
				cout << "У вас еще нет добавленных тел" << endl;
			}
			break;
		case 8:
			AddCompoundBody(bodies);
			break;
		default:
			reading = false;
			break;
		}
	}
	
}