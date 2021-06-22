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
		cout << gear << "-ая передача успешно включена" << endl;
	}
	else
	{
		cout << "Невозможно включить данную передачу" << endl;
	}
}

void SetSpeedOfCar(Car &car, int speed)
{
	if (car.SetSpeed(speed))
	{
		cout << "Набранная скорость: " << speed << endl;
	}
	else
	{
		cout << "Нельзя набрать данную скорость на текущей передаче" << endl;
	}
}

void TurnOffEngineOfCar(Car &car)
{
	if (car.TurnOffEngine())
	{
		cout << "Двигатель успешно заглушен" << endl;
	}
	else
	{
		cout << "Сначала остановитесь и поставьте рычаг КПП в нейтральное положении" << endl;
	}
}

void TurnOnEngineOfCar(Car &car)
{
	if (car.TurnOnEngine())
	{
		cout << "Двигатель завелся" << endl;
	}
	else
	{
		cout << "Двигатель уже заведен" << endl;
	}
}	

void PrintGearOfCar(const int& gear)
{
	if (gear > 0)
	{
		cout << "текущая передача: " << gear << endl;
	}
	else
	{
		if (gear == -1)
		{
			cout << "включена задняя передача" << endl;
		}
		else
		{
			cout << "рычаг КПП в нейтральном положении" << endl;
		}
	}
}

void PrintDirectionOfCar(const Direction& dir)
{
	cout << "текущее направление: ";
	if (dir == Direction::Straight)
	{
		cout << "Движение вперед" << endl;
	}
	else
	{
		if (dir == Direction::OnPlace)
		{
			cout << "Стоим на месте" << endl;
		}
		else
		{
			cout << "Движение назад" << endl;
		}
	}
}

void PrintEngineStateOfCar(Car &car)
{
	cout << "Двигатель";
	if (car.GetEngineState())
	{
		cout << " заведён" << endl;
	}
	else
	{
		cout << " заглушен" << endl;
	}
}

void PrintStateOfCar(Car &car)
{
	PrintEngineStateOfCar(car);
	PrintDirectionOfCar(car.GetDirection());
	cout << "текущая скорость: " << car.GetSpeed() << endl;
	PrintGearOfCar(car.GetGear());
}