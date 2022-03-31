#pragma once
#include "Vehicle.h"

class ElectricVehicle : public Vehicle {
public:
	float currentCharge;
	float maximumCharge;

	ElectricVehicle(float maximumCharge, float electricEfficiency);

	float calculateRange();
	float percentEnergyRemaining();
	void drive(float km);

	virtual ~ElectricVehicle();
};


