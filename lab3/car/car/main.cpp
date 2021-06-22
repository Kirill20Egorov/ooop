#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include "Car.h"
#include <clocale>
#include "Header.h"

using namespace std;

int main()
{
	string command;	
	setlocale(LC_ALL, "Russian");
	int gear, speed;
	Car car;
	while (cin >> command)
	{
		if (command == "Info")
		{
			PrintStateOfCar(car);
		}
		if (command == "EngineOn")
		{
			TurnOnEngineOfCar(car);
		}
		if (command == "EngineOff")
		{
			TurnOffEngineOfCar(car);
		}
		if (command == "SetGear")
		{
			cin >> gear;
			SetGearOfCar(car, gear);
		}
		if (command == "SetSpeed")
		{
			cin >> speed;
			SetSpeedOfCar(car, speed);
		}
	}
}

