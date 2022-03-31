#include "Vehicle.h"
#include "ElectricVehicle.h"
#include<iostream>

ElectricVehicle::ElectricVehicle(float _maximumCharge, float _electricEfficiency) {
	maximumCharge = _maximumCharge;
	currentCharge = _maximumCharge;
	engineEfficiency = _electricEfficiency;
}


float ElectricVehicle::calculateRange() {
	return currentCharge * 100 / engineEfficiency;

}
float ElectricVehicle::percentEnergyRemaining() {
	return currentCharge * 100.0f / maximumCharge;

}
void ElectricVehicle::drive(float km) {
	currentCharge -= (km / 100) * engineEfficiency;


}
ElectricVehicle::~ElectricVehicle() {
	cout << "In ElectricVehicle Destructor" << endl;
}