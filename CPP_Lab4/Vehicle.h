#pragma once

class Vehicle {
public:
	int numWheels = 0;
	int numDoors = 0;

public:
	Vehicle();
	Vehicle(int w);
	Vehicle(int w, int d);
	~Vehicle();
	void printVehicle();
	Vehicle(Vehicle&);
	Vehicle(Vehicle*);

};