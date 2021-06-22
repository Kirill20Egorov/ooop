#pragma once
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include "Car.h"
#include <clocale>

using namespace std;

void SetSpeedOfCar(Car& car, int speed);
void SetGearOfCar(Car& car, int gear);
void TurnOffEngineOfCar(Car& car);
void TurnOnEngineOfCar(Car& car);
void PrintGearOfCar(const int& gear);
void PrintDirectionOfCar(const Direction& dir);
void PrintEngineStateOfCar(const Car& car);
void PrintStateOfCar(Car& car);