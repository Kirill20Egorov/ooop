#define CATCH_CONFIG_MAIN
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include "../../catch2/catch.hpp"
#include "../lab4/Bodies.h"
#include "../lab4/Bodies.cpp"

using namespace std;

SCENARIO("Check methods of bodies")
{
	WHEN("Check methods of Parallelipiped")
	{
		auto parallelepiped = new CParallelepiped(1, 10, 5, 4);
		REQUIRE(parallelepiped->GetDensity() == 1);
		REQUIRE(parallelepiped->GetHeight() == 5);
		REQUIRE(parallelepiped->GetWidth() == 10);
		REQUIRE(parallelepiped->GetDepth() == 4);
		REQUIRE(parallelepiped->GetVolume() == 200);
		REQUIRE(parallelepiped->GetMass() == 200);
	}

	WHEN("Check methods of Sphere")
	{
		auto sphere = new CSphere(2, 10);
		REQUIRE(sphere->GetDensity() == 2);
		REQUIRE(sphere->GetRadius() == 10);
		REQUIRE(sphere->GetVolume() == Approx(4188.7902047864));
		REQUIRE(sphere->GetMass() == Approx(8377.5804095728));
	}

	WHEN("Check methods of Cone")
	{
		auto cone = new CCone(50, 10, 2);
		REQUIRE(cone->GetDensity() == 50.0);
		REQUIRE(cone->GetHeight() == 2);
		REQUIRE(cone->GetRadius() == 10);
		REQUIRE(cone->GetVolume() == Approx(209.4395102393));
		REQUIRE(cone->GetMass() == Approx(10471.975511966));
	}

	WHEN("Check methods of Cylinder")
	{
		auto cylinder = new CCylinder(3, 10, 5);
		REQUIRE(cylinder->GetDensity() == 3);
		REQUIRE(cylinder->GetRadius() == 10);
		REQUIRE(cylinder->GetHeight() == 5);
		REQUIRE(cylinder->GetVolume() == Approx(1570.7963267949));
		REQUIRE(cylinder->GetMass() == Approx(4712.3889803847));
	}
}

SCENARIO("Check functions of program")
{
	vector<CBody*> bodies;
	setlocale(LC_ALL, "Russian");
	WHEN("Try to push Parallelipipedq with invalid data")
	{
		istringstream inp1("1.0 0.0 3.0 4.0");
		istringstream inp2("1.0 1.0 -2.0 4.0");
		istringstream inp3("-1 0.0 3.0 4.0");
		istringstream inp4("1.0 0.0 3.0 0.0");
		REQUIRE(AddParallelepiped(inp1, bodies) == false);
		REQUIRE(AddParallelepiped(inp2, bodies) == false);
		REQUIRE(AddParallelepiped(inp3, bodies) == false);
		REQUIRE(AddParallelepiped(inp4, bodies) == false);
	}
	WHEN("Try to push Cone with invalid data")
	{
		istringstream inp1("2 1 -5");
		istringstream inp2("0 3 5");
		istringstream inp3("5 -5 5");
		REQUIRE(AddCone(inp1, bodies) != true);
		REQUIRE(AddCone(inp2, bodies) != true);
		REQUIRE(AddCone(inp3, bodies) != true);
	}
	WHEN("Try to push Cylinder with invalid data")
	{
		istringstream inp1("-1 -3 5");
		istringstream inp2("1 -3 5");
		istringstream inp3("1 2 -5");
		REQUIRE(AddCyllinder(inp1, bodies) != true);
		REQUIRE(AddCyllinder(inp2, bodies) != true);
		REQUIRE(AddCyllinder(inp3, bodies) != true);
	}
	WHEN("Try to push Sphere with invalid data")
	{
		istringstream inp1("-1 3");
		istringstream inp2("-1 0");
		istringstream inp3("0 -3");
		REQUIRE(AddSphere(inp1, bodies) != true);
		REQUIRE(AddSphere(inp2, bodies) != true);
		REQUIRE(AddSphere(inp3, bodies) != true);
	}
	REQUIRE(bodies.size() == 0);
	WHEN("Try to get body with the most mass in empty vector")
	{
		REQUIRE(FindMostMassBody(bodies) == nullptr);
	}
	WHEN("Try to get body with the less weight in water in empty vector")
	{
		REQUIRE(FindLessWaterWeightBody(bodies) == nullptr);
	}
	WHEN("Try to get info about bodies in empty vector")
	{
		ostringstream output;
		PrintAllInfo(output, bodies);
		REQUIRE(output.str() == "");
	}
	WHEN("Try to push correct data")
	{
		istringstream inp1("1.0 2.0 3.0 80.0");
		REQUIRE(AddParallelepiped(inp1, bodies) == true);
		istringstream inp2("1 3 5");
		REQUIRE(AddCyllinder(inp2, bodies) == true);
		istringstream inp3("5 3 5");
		REQUIRE(AddCone(inp3, bodies) == true);
		istringstream inp4("2 4");
		istringstream inp5("2 4");
		REQUIRE(AddSphere(inp4, bodies) == true);
		REQUIRE(bodies.size() != 0);
		WHEN("Try to get body with the most mass")
		{
			ostringstream output;
			output << "Параллелепипед" << ":" << endl
				<< "\tdensity = " << 80 << endl
				<< "\tvolume = " << 6 << endl
				<< "\tmass = " << 480 << endl;
			REQUIRE("Параллелепипед" == FindMostMassBody(bodies)->GetType());
		}
		WHEN("Try to get body with the less weight in water")
		{
			REQUIRE(FindLessWaterWeightBody(bodies) != nullptr);
			ostringstream output;
			output << "Конус" << ":" << endl
				<< "\tdensity = " << 5 << endl
				<< "\tvolume = " << 78.5398 << endl
				<< "\tmass = " << 392.699 << endl;
			REQUIRE("Конус" == FindLessWaterWeightBody(bodies)->GetType());
		}
	}
}
