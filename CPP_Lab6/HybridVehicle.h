#pragma once
#include "GasolineVehicle.h"
#include "ElectricVehicle.h"
#include "Vehicle.h"

class HybridVehicle : public ElectricVehicle, public GasolineVehicle {
public:

	HybridVehicle(float maximumGasoline, float gasolineEfficiency, float maximumCharge, float electricEfficiency);
	
	float calculateRange();
	float percentEnergyRemaining();
	void drive(float km);

	virtual ~HybridVehicle();

};