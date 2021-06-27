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
		cout << "������� ����� ������" << endl
			<< "1 - ��������" << endl
			<< "2 - �����" << endl
			<< "3 - �����" << endl
			<< "4 - ��������������" << endl
			<< "5 - ���������� � ���� �������" << endl
			<< "6 - ���� � ���������� ������" << endl
			<< "7 - ���� � ���������� ����� � ����" << endl
			<< "8 - ��������� ��������� ����" << endl
			<< " - ����� ������ ������� �����" << endl;
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
				cout << "����� ������� ���� " << FindMostMassBody(bodies)->ToString();
			}
			else
			{
				cout << "� ��� ��� ��� ����������� ���" << endl;
			}
			break;
		case 7:
			if (bodies.size() > 0)
			{
				cout << "����� ������ ����, ����������� � ���� " << FindLessWaterWeightBody(bodies)->ToString();
			}
			else
			{
				cout << "� ��� ��� ��� ����������� ���" << endl;
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