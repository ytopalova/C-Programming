#include "GasolineVehicle.h"
#include "Vehicle.h"
#include<iostream>

GasolineVehicle::GasolineVehicle(float _maximumGasoline, float _gasolineEfficiency) {
	maximumGasoline = _maximumGasoline;
	currentGasoline = _maximumGasoline;
	engineEfficiency = _gasolineEfficiency;
}

float GasolineVehicle::calculateRange() {
	return currentGasoline * 100 / engineEfficiency;

}
float GasolineVehicle::percentEnergyRemaining() {
	return currentGasoline * 100.0f / maximumGasoline;

}
void GasolineVehicle::drive(float km) {
	currentGasoline -= (km / 100) * engineEfficiency;
}

GasolineVehicle::~GasolineVehicle() {
	cout << "In GasolineVehicle Destructor" << endl;
}
