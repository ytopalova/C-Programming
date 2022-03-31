#pragma once
#include "Vehicle.h"
using namespace std;

template <class T>
class ElectricVehicle : public Vehicle {
public:
	float currentCharge;
	float maximumCharge;

	inline ElectricVehicle(float _maximumCharge, float _electricEfficiency) {
		maximumCharge = _maximumCharge;
		currentCharge = _maximumCharge;
		engineEfficiency = _electricEfficiency;
	}

	inline float calculateRange() {
		return currentCharge * 100 / engineEfficiency;

	}
	inline float percentEnergyRemaining() {
		return currentCharge * 100.0f / maximumCharge;

	}
	inline void drive(float km) {
		currentCharge -= (km / 100) * engineEfficiency;


	}
	inline ~ElectricVehicle() {
		cout << "In ElectricVehicle Destructor" << endl;
	}
};


