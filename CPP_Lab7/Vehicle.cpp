#include<iostream>
#include "Vehicle.h"

using namespace std;

Vehicle::Vehicle() : Vehicle(4) {
}

Vehicle::Vehicle(int w) : Vehicle(w, 4) {
}

Vehicle::Vehicle(int w, int d) {
	numWheels = w;
	numDoors = d;
}

Vehicle:: ~Vehicle() {
	cout << "In Vehicle destructor" << endl;
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
void Vehicle::setParameters(int w, int d) {
	Vehicle::numDoors = d;
	Vehicle::numWheels = w;
}


