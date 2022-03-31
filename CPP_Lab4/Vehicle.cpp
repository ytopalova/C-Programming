#include<iostream>
#include "Vehicle.h"

using namespace std;

Vehicle::Vehicle() : Vehicle(4) {
	cout << "In constructor with 0 parameters" << endl;
}

Vehicle::Vehicle(int w) : Vehicle(w, 4) {
	cout << "In constructor with 1 parameters, wheels = " << w << endl;
}

Vehicle::Vehicle(int w, int d) {
	numWheels = w;
	numDoors = d;
	cout << "In constructor with 2 parameters" << endl;
}

Vehicle:: ~Vehicle() {
	cout << "in destructor" << endl;
}
void Vehicle::printVehicle() {
	cout << "Wheels: " << numWheels << " Doors: " << numDoors << endl;
}
Vehicle::Vehicle(Vehicle &copy) {
}

Vehicle::Vehicle(Vehicle *copy) : Vehicle (*copy){
}
