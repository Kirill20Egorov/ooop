#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include "Car.h"
#include "Header.h"
#include <clocale>

void SetGearOfCar(Car &car, int gear)
{
	if (car.SetGear(gear))
	{
		cout << gear << "-�� �������� ������� ��������" << endl;
	}
	else
	{
		cout << "���������� �������� ������ ��������" << endl;
	}
}

void SetSpeedOfCar(Car &car, int speed)
{
	if (car.SetSpeed(speed))
	{
		cout << "��������� ��������: " << speed << endl;
	}
	else
	{
		cout << "������ ������� ������ �������� �� ������� ��������" << endl;
	}
}

void TurnOffEngineOfCar(Car &car)
{
	if (car.TurnOffEngine())
	{
		cout << "��������� ������� ��������" << endl;
	}
	else
	{
		cout << "������� ������������ � ��������� ����� ��� � ����������� ���������" << endl;
	}
}

void TurnOnEngineOfCar(Car &car)
{
	if (car.TurnOnEngine())
	{
		cout << "��������� �������" << endl;
	}
	else
	{
		cout << "��������� ��� �������" << endl;
	}
}	

void PrintGearOfCar(const int& gear)
{
	if (gear > 0)
	{
		cout << "������� ��������: " << gear << endl;
	}
	else
	{
		if (gear == -1)
		{
			cout << "�������� ������ ��������" << endl;
		}
		else
		{
			cout << "����� ��� � ����������� ���������" << endl;
		}
	}
}

void PrintDirectionOfCar(const Direction& dir)
{
	cout << "������� �����������: ";
	if (dir == Direction::Straight)
	{
		cout << "�������� ������" << endl;
	}
	else
	{
		if (dir == Direction::OnPlace)
		{
			cout << "����� �� �����" << endl;
		}
		else
		{
			cout << "�������� �����" << endl;
		}
	}
}

void PrintEngineStateOfCar(Car &car)
{
	cout << "���������";
	if (car.GetEngineState())
	{
		cout << " ������" << endl;
	}
	else
	{
		cout << " ��������" << endl;
	}
}

void PrintStateOfCar(Car &car)
{
	PrintEngineStateOfCar(car);
	PrintDirectionOfCar(car.GetDirection());
	cout << "������� ��������: " << car.GetSpeed() << endl;
	PrintGearOfCar(car.GetGear());
}