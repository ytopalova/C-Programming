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
	cout << "In destructor" << endl;
}

void Vehicle::printVehicle() {
	cout << "Wheels: " << numWheels << " Doors: " << numDoors << endl;
}

Vehicle::Vehicle(Vehicle& copy) :Vehicle(copy.numWheels, copy.numDoors) {
	cout << "Copying from " << &copy << endl;
}

Vehicle::Vehicle(Vehicle *copy) : Vehicle (*copy){
	cout << "Copying from " << &copy << endl;
}

Vehicle Vehicle::operator=(const Vehicle& object) {
	numWheels = object.numWheels;
	numDoors = object.numDoors;
	return *this;
}

bool Vehicle::operator==(const Vehicle& object) {
	if (numWheels == object.numWheels && numDoors == object.numDoors) {
		return true;
	} else {
		return false;
	}
}

bool Vehicle::operator!=(const Vehicle& object) {
	if (numWheels != object.numWheels && numDoors != object.numDoors) {
		return true;
	} else {
		return false;
	}
}

Vehicle Vehicle::operator++() {
	++numWheels;          
	++numDoors;

	return Vehicle(numWheels, numDoors);
}

Vehicle Vehicle::operator++(int) {
	Vehicle copy(numWheels, numDoors);

	++numWheels;
	++numDoors;

	return copy;
}

Vehicle Vehicle::operator--() {
	--numWheels;
	--numDoors;

	return Vehicle(numWheels, numDoors);
}

Vehicle Vehicle::operator--(int) {
	Vehicle copy(numWheels, numDoors);

	--numWheels;
	--numDoors;

	return copy;
}

std::ostream& operator<<(ostream& out, const Vehicle& v){
	out << " Wheels: " << v.numWheels << " Doors: " << v.numDoors << endl;
	return out;
}


