#include "CBody.h"
#include "Parallelepiped.h"
#include "Sphere.h"
#include "Cylinder.h"
#include "Cone.h"
#include "Compound.h"
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

bool AddCyllinder(istream& input, vector<CBody*>& bodies)
{
	cout << "Введите радиус" << endl;
	double radius;
	input >> radius;
	if (radius == -1)
		return false;
	cout << "Введите высоту" << endl;
	double height;
	input >> height;
	if (height == -1)
		return false;
	cout << "Введите плотность" << endl;
	double density;
	input >> density;
	if (density == -1)
		return false;
	if (radius > 0 && height > 0 && density > 0)
	{
		auto cylinder = new CCylinder(density, radius, height);
		bodies.push_back(cylinder);
		return true;
	}
	return false;
}

bool AddSphere(istream& cin, vector<CBody*>& bodies)
{
	cout << "Введите радиус" << endl;
	double radius;
	cin >> radius;
	if (radius == -1)
		return false;
	cout << "Введите плотность" << endl;
	double density;
	cin >> density;
	if (density == -1)
		return false;
	if (radius > 0 && density > 0)
	{
		auto sphere = new CSphere(density, radius);
		bodies.push_back(sphere);
		return true;
	}
	return false;
}

bool AddCone(istream& cin, vector<CBody*>& bodies)
{
	cout << "Введите радиус" << endl;
	double radius;
	cin >> radius;
	if (radius == -1)
		return false;
	cout << "Введите высоту" << endl;
	double height;
	cin >> height;
	if (height == -1)
		return false;
	cout << "Введите плотность" << endl;
	double density;
	cin >> density;
	if (density == -1)
		return false;
	if (radius > 0 && height > 0 && density > 0)
	{
		auto cone = new CCone(density, radius, height);
		bodies.push_back(cone);
		return true;
	}
	return false;
}

bool AddParallelepiped(istream& input, vector<CBody*>& bodies)
{
	cout << "Введите ширину" << endl;
	double width;
	input >> width;
	if (width == -1)
		return false;
	cout << "Введите высоту" << endl;
	double height;
	input >> height;
	if (height == -1)
		return false;
	cout << "Введите глубину" << endl;
	double depth;
	input >> depth;
	if (depth == -1)
		return false;
	cout << "Введите плотность" << endl;
	double density;
	input >> density;
	if (density == -1)
		return false;
	if (width > 0 && height > 0 && depth > 0 && density > 0)
	{
		auto parallelepiped = new CParallelepiped(density, width, height, depth);
		bodies.push_back(parallelepiped);
		return true;
	}
	return false;
}
CBody* FindMostMassBody(const vector<CBody*>& bodies)
{
	if (bodies.size() > 0)
	{
		CBody* ptr = bodies[0];
		double maxMass = bodies[0]->GetMass();
		for (unsigned int i = 0; i < bodies.size(); i++)
		{
			if (maxMass < bodies[i]->GetMass())
			{
				maxMass = bodies[i]->GetMass();
				ptr = bodies[i];
			}
		}
		return ptr;
	}
	return nullptr;

}
CBody* FindLessWaterWeightBody(const vector<CBody*>& bodies)
{
	if (bodies.size() > 0)
	{
		CBody* ptr = bodies[0];
		double lessWaterWeight = 0;
		int n = 0;
		for (unsigned int i = 0; i < bodies.size(); i++)
		{
			if (lessWaterWeight > ((bodies[i]->GetDensity() - 1000) * 10 * bodies[i]->GetVolume()))
			{
				lessWaterWeight = (bodies[i]->GetDensity() - 1000) * 10 * bodies[i]->GetVolume();
				ptr = bodies[i];
			}
		}
		return ptr;
	}
	return nullptr;
}

void PrintAllInfo(ostream& output, const vector<CBody*>& bodies)
{
	if (!bodies.empty())
	{
		output << "Count: " << bodies.size() << endl;
		for (unsigned int i = 0; i < bodies.size(); i++)
		{
			output << bodies[i]->ToString() << endl;
		}
	}
}

bool AddCompoundBody(vector<CBody*>& bodies)
{
	int num;
	bool isAdded = false;
	vector<CBody*> compoundBody;
	bool activeCompound = true;
	while (activeCompound)
	{
		cout << "Введите номер фигуры, которую хотите добавить" << endl
			<< "1 - Циллиндр" << endl
			<< "2 - Сфера" << endl
			<< "3 - Конус" << endl
			<< "4 - Параллелипипед" << endl
			<< "5 - Составное" << endl
			<< "6 - Выйти из меню составления составного тела" << endl;
		cin >> num;
		switch (num)
		{
		case 1:
			isAdded = AddCyllinder(cin, compoundBody);
			break;
		case 2:
			isAdded = AddSphere(cin, compoundBody);
			break;
		case 3:
			isAdded = AddCone(cin, compoundBody);
			break;
		case 4:
			isAdded = AddParallelepiped(cin, compoundBody);
			break;
		case 5:
			isAdded = AddCompoundBody(compoundBody);
			break;
		default:
			activeCompound = false;
			break;
		}
	}
	if (isAdded)
	{
		auto compBody = new CCompound(compoundBody);
		bodies.push_back(compBody);
	}
	return isAdded;
}