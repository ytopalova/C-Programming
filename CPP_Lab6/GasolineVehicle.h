#pragma once
#include "Vehicle.h"

class GasolineVehicle : public Vehicle {
public:
	float currentGasoline;
	float maximumGasoline;

	GasolineVehicle(float maximumGasoline, float gasolineEfficiency);
	
	float calculateRange();
	float percentEnergyRemaining();
	void drive(float km);
	
	virtual ~GasolineVehicle();

};
