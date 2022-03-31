#pragma once
#include "Vehicle.h"
using namespace std;

template <class T>
class GasolineVehicle : public Vehicle {
public:
	float currentGasoline;
	float maximumGasoline;

	inline GasolineVehicle(float _maximumGasoline, float _gasolineEfficiency) {
		maximumGasoline = _maximumGasoline;
		currentGasoline = _maximumGasoline;
		engineEfficiency = _gasolineEfficiency;
	}

	inline float calculateRange() {
		return currentGasoline * 100 / engineEfficiency;

	}
	inline float percentEnergyRemaining() {
		return currentGasoline * 100.0f / maximumGasoline;

	}
	inline void drive(float km) {
		currentGasoline -= (km / 100) * engineEfficiency;
	}

	inline ~GasolineVehicle() {
		cout << "In GasolineVehicle Destructor" << endl;
	}
};
