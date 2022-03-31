#include "Vehicle.h"
#include<iostream>

using namespace std;

	
void createVehicle(Vehicle &v, int w = 4, int d = 2) {
	v.numWheels = w;
	v.numDoors = d;
}

int main(int argc, char** argv) {
	
	Vehicle original;				//empty constructor no ()
	Vehicle copy(original);			//copy constructor by reference
	Vehicle secondCopy(&original);  //copy constructor by pointer
	copy.printVehicle();
	createVehicle(copy, 2);			//wheels is 2, everything else is default value
	copy.printVehicle();
	createVehicle(copy, 2, 3);		//wheels is 2, doors is 3
	copy.printVehicle();
	copy = secondCopy;
	copy.printVehicle();			//copy is same as second copy
	return 0;

}

