#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#define CATCH_CONFIG_MAIN
#include "../../../catch2/catch.hpp"
#include "../car/Header.h"
#include "../car/Source1.cpp"
#include "../car/Car.h"
#include "../car/Car.cpp"

using namespace std;

SCENARIO("Some tests")
{
	WHEN("Turn on and then off engine")
	{
		Car car;
		REQUIRE(car.TurnOnEngine());
		REQUIRE(car.TurnOffEngine());
	}
	WHEN("Try turn on -1 gear while car is going straight")
	{
		Car car;
		REQUIRE(car.TurnOnEngine());
		REQUIRE(car.SetGear(1));
		REQUIRE(car.SetSpeed(20));
		REQUIRE(!car.SetGear(-1));
	}
	WHEN("Check back direction and try to off engine while going back")
	{
		Car car;
		REQUIRE(car.TurnOnEngine());
		REQUIRE(car.SetGear(-1));
		REQUIRE(car.SetSpeed(20));
		REQUIRE(!car.TurnOffEngine());
	}
	WHEN("Try set negative speed")
	{
		Car car;
		REQUIRE(car.TurnOnEngine());
		REQUIRE(!car.SetSpeed(-1));
		REQUIRE(car.SetGear(-1));
		REQUIRE(car.SetGear(1));
		REQUIRE(!car.SetSpeed(-10));
	}
	WHEN("Check negative speed while going straight")
	{
		Car car;
		REQUIRE(car.TurnOnEngine());
		REQUIRE(car.SetGear(1));
		REQUIRE(car.SetSpeed(20));
		REQUIRE(!car.SetSpeed(-1));
	}
	WHEN("Check all gears")
	{
		Car car;
		REQUIRE(car.TurnOnEngine());
		REQUIRE(car.SetGear(1));
		REQUIRE(car.SetSpeed(20));
		REQUIRE(car.SetGear(2));
		REQUIRE(car.SetSpeed(50));
		REQUIRE(car.SetGear(3));
		REQUIRE(car.SetSpeed(60));
		REQUIRE(car.SetGear(4));
		REQUIRE(car.SetSpeed(90));
		REQUIRE(car.SetGear(5));
		REQUIRE(car.SetSpeed(150));
		REQUIRE(!car.SetSpeed(152));
		REQUIRE(car.SetGear(0));
		REQUIRE(car.SetSpeed(0));
		REQUIRE(car.SetGear(-1));
		REQUIRE(!car.SetSpeed(-20));
	}
	WHEN("Try set uncorrect gear for current speed")
	{
		Car car;
		REQUIRE(car.TurnOnEngine());
		REQUIRE(car.SetGear(1));
		REQUIRE(car.SetSpeed(20));
		REQUIRE(!car.SetGear(-1));
		REQUIRE(!car.SetSpeed(50));
		REQUIRE(car.SetGear(2));
		REQUIRE(car.SetSpeed(50));
		REQUIRE(!car.SetGear(-1));
		REQUIRE(car.SetGear(4));
		REQUIRE(car.SetSpeed(90));
		REQUIRE(car.SetGear(5));
		REQUIRE(!car.SetGear(-1));
		REQUIRE(car.SetSpeed(150));
		REQUIRE(car.SetGear(0));
		REQUIRE(!car.SetGear(-1));
	}
	//cpp coverage 
	WHEN("Try to turn off engine on different gears and speed")
	{
		Car car;
		REQUIRE(car.TurnOnEngine());
		REQUIRE(car.SetGear(1));
		REQUIRE(car.SetSpeed(20));
		REQUIRE(!car.TurnOffEngine());
		REQUIRE(car.SetGear(2));
		REQUIRE(car.SetSpeed(50));
		REQUIRE(!car.TurnOffEngine());
		REQUIRE(car.SetGear(4));
		REQUIRE(car.SetSpeed(90));
		REQUIRE(car.SetGear(5));
		REQUIRE(!car.TurnOffEngine());
		REQUIRE(car.SetSpeed(150));
		REQUIRE(car.SetGear(0));
		REQUIRE(car.SetSpeed(0));
		REQUIRE(car.SetGear(-1));
		REQUIRE(!car.TurnOffEngine());
		REQUIRE(car.SetGear(0));
		REQUIRE(car.TurnOffEngine());
	}
}