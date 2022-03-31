#pragma once
#include "GasolineVehicle.h"
#include "ElectricVehicle.h"
#include "Vehicle.h"
using namespace std;

template <class T>
class HybridVehicle : public ElectricVehicle<T>, public GasolineVehicle<T> {

public:
	HybridVehicle() : GasolineVehicle(), ElectricVehicle() {}
	
	HybridVehicle(float maximumGasoline, float gasolineEfficiency, float maximumCharge, float electricEfficiency) : ElectricVehicle(maximumCharge, electricEfficiency), GasolineVehicle(maximumGasoline, gasolineEfficiency) {}
	
	inline float calculateRange() {
		return currentCharge * 100 / ElectricVehicle::engineEfficiency + currentGasoline * 100 / GasolineVehicle::engineEfficiency;

	}
	inline  float percentEnergyRemaining() {
		return ((currentCharge / maximumCharge * 100) + (currentGasoline / maximumGasoline * 100)) / 2;
	}
	inline void drive(float km) {
		if (km > ElectricVehicle::calculateRange()) {
			km -= ElectricVehicle::calculateRange();
			currentCharge = 0;
		}
		if (currentCharge > 0) {
			currentCharge -= (km / 100) * ElectricVehicle::engineEfficiency;
		}
		else {
			currentGasoline -= (km / 100) * GasolineVehicle::engineEfficiency;
			if (currentGasoline < 0) {
				cout << "Your car has run out of energy!" << endl;
			}
		}
	}

	~HybridVehicle() {
		cout << "In HybridVehicle Destructor" << endl;
	}
};