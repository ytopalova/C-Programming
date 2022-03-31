#include "HybridVehicle.h"
#include "Vehicle.h"
#include<iostream>

HybridVehicle::HybridVehicle(float maximumGasoline, float gasolineEfficiency, float maximumCharge, float electricEfficiency) : ElectricVehicle(maximumCharge, electricEfficiency), GasolineVehicle(maximumGasoline, gasolineEfficiency) {

}

float HybridVehicle::calculateRange() {
	return currentCharge * 100 / ElectricVehicle::engineEfficiency + currentGasoline * 100 / GasolineVehicle::engineEfficiency;

}
float HybridVehicle::percentEnergyRemaining() {
	return ((currentCharge / maximumCharge * 100) + (currentGasoline / maximumGasoline * 100)) / 2;
}
void HybridVehicle::drive(float km) {
	if (km > ElectricVehicle::calculateRange()) {
		km -= ElectricVehicle::calculateRange();
		currentCharge = 0;
	}
	if (currentCharge > 0) {
		currentCharge -= (km / 100) * ElectricVehicle::engineEfficiency;
	}else {
		currentGasoline -= (km / 100) * GasolineVehicle::engineEfficiency;
		if (currentGasoline < 0) {
			cout << "Your car has run out of energy!" << endl;
		}
	}
}

HybridVehicle::~HybridVehicle() {
	cout << "In HybridVehicle Destructor" << endl;
}
