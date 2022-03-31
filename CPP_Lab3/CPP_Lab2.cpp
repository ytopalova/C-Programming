
#include<iostream>

using namespace std;

namespace CST8219 {

	class Vehicle {
	private:
		int numWheels;
		int numDoors;

	public:
		Vehicle() : Vehicle(4) {
			cout << "In constructor with 0 parameters" << endl;
		}

		Vehicle(int w) : Vehicle(4, w) {
			cout << "In constructor with 1 parameters, wheels = " << w << endl;
		}

		Vehicle(int w, int d) {
			numWheels = w;
			numDoors = d;
			cout << "In constructor with 2 parameters" << endl;
		}

		~Vehicle() {
			cout << "In destructor" << endl;
		}
	};
}

	using namespace CST8219;

	int main(int argc, char** argv) {
		Vehicle veh1;
		Vehicle veh2(4);
		Vehicle veh3(4,2);

		cout << "Vehicle takes " << sizeof(veh1) << endl;
		cout << "Vehicle takes " << sizeof(veh2) << endl;
		cout << "Vehicle takes " << sizeof(veh3) << endl;


		Vehicle* pVehicle;

		int d, w, i;
		do {
			cout << "Enter number of doors:" << endl;
			cin >> d;
			cout << "Enter number of wheels:" << endl;
			cin >> w;
			if (d > 0 && w > 0) {
				pVehicle = new Vehicle(w, d);
			}
			cout << "Press 1 for quit, if not countinue to create a vehicle" << endl;
			cin >> i;
		} while (i != 1);

		return 0;
	}

