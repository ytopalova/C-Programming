#pragma once
#include<iostream>

using namespace std;

class Vehicle {
public:
	int numWheels = 0;
	int numDoors = 0;
	float engineEfficiency;

public:
	Vehicle();
	Vehicle(int w);
	Vehicle(int w, int d);
	~Vehicle();
	
	void printVehicle();
	Vehicle(Vehicle&);
	Vehicle(Vehicle*);
	
	void setParameters(int w, int d);
	

};