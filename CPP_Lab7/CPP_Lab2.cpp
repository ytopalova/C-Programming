#include "HybridVehicle.h"
#include<iostream>
#include <vector>

namespace Helper {
	template<class T>
	T min(T a, T b) {
		if (a < b) { //If a is smaller, return a
			return a;
		}
		else if (b < a) { //If b is smaller, return b
			return b;
		}
		else { //Otherwise, they're equal so return one of them
			return a;
		}
	}
	template<class T>
	T max(T a, T b) {
		if (a > b) { //If a is bigger, return a
			return a;
		}
		else if (b > a) { //If b is bigger, return b
			return b;
		}
		else { //Otherwise, they're equal so return one of them
			return a;
		}
	}
}

using namespace std;

template<class T>
T testVehicle(T pVehicle, const char* vehicleName)
{
	cout << vehicleName << "’s range is: " << pVehicle->calculateRange() << endl;
	pVehicle->drive(150); //drive 150 km
	cout << vehicleName << "’s energy left is: " << pVehicle->percentEnergyRemaining() << endl;
	cout << vehicleName << "’s range is now: " << pVehicle->calculateRange() << endl;

	return pVehicle;
}

void testTemplateLibrary() {
	vector<float> vec = { 5.0f, 4.0f, 3.0f, 2.0f, 1.0f };

	for (int i = 0; i < vec.size(); i++) {
		cout << vec.at(i) << endl;
	}
	while (!vec.empty())
	{
		cout << "Last Element : " << vec.back(); //print the last element
		vec.pop_back(); // remove the last element
	}

}

int main()
{					//50L of gas, 7.1 L/100km
	delete  testVehicle(new GasolineVehicle<float>(50, 7.1), "Corolla");

	//42 L of gas, 4.3 L/100km, 8.8kWh, 22 kWh/100km
	delete testVehicle(new HybridVehicle<double>(42, 4.3, 8.8, 22.0), "Prius");

	//75 kWh, 16 kWh/100km
	delete testVehicle(new ElectricVehicle<int>(75, 16), "Tesla 3");

	cout << "min of 5 and 7 is:" << Helper::min(5, 7) << endl;
	cout << "max of 5 and 7 is:" << Helper::max(5, 7) << endl;

	cout << "min of A and B is:" << Helper::min('A', 'B') << endl;
	cout << "max of A and B is:" << Helper::max('A', 'B') << endl;

	cout << "min of string(Hello) and string(world) is:" << Helper::min(string("Hello"), string("World")) << endl;
	cout << "max of string(Hello) and string(world) is:" << Helper::max(string("Hello"), string("World")) << endl;
	testTemplateLibrary();
	return 0;
}

