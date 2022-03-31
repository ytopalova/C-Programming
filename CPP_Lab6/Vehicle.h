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
	virtual ~Vehicle();
	void printVehicle();
	Vehicle(Vehicle&);
	Vehicle(Vehicle*);

	/*Vehicle operator=(const Vehicle&);
	bool operator==(const Vehicle&);
	bool operator!=(const Vehicle&);

	Vehicle operator++();
	Vehicle operator++(int);
	Vehicle operator--();
	Vehicle operator--(int);*/
	
	friend std::ostream& operator<<(ostream&, const Vehicle&);

	virtual float calculateRange() =0;
	virtual float percentEnergyRemaining() = 0;
	virtual void drive(float km) = 0;

};