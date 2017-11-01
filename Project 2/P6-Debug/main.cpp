#include "Runway.hpp"
#include <string>
void initialize(int &end_time, int&queue_limit);

void run_idle(int time);

int debuger(std::string notice);

const std::string notices[3] = {
	"Please type in the number of planes that arrive at this time unit: ",
	"Please type in the number of planes that plan to leave at this time unit: ",
	"Please type in the amount of fuel the plane has: "
};

int main() {
	int end_time;
	int queue_limit;
	int flight_number = 0;
	int fuel;
	bool enmergency = false;
	initialize(end_time, queue_limit);
	Runway small_airport(queue_limit);
	for (int current_time = 0; current_time < end_time; ++current_time) {
		enmergency = false;
		int number_arrivals = debuger(notices[0]);
		for (int i = 0; i < number_arrivals; ++i) {
			fuel = debuger(notices[2]);
			Plane current_plane(flight_number++, current_time, arriving, fuel);
			if(fuel <= small_airport.waitingTime()){
				if(!Emergency) {
					enmergency = true;
					small_airport.emergency_land();
					cout << "<---Emergency situations: Plane " << flight_number - 1 << " has no fuel to wait, land immediately!--->" << endl;
					current_plane.land(current_time);
				}
				else
					current_plane.refuse();
				continue;
			}
			if (small_airport.can_land(current_plane) != success)
				current_plane.refuse();
		}
		int number_departures = debuger(notices[1]);

		for (int j = 0; j < number_departures; ++j) {
			Plane current_plane(flight_number++, current_time, departing, 0);
			if (small_airport.can_depart(current_plane) != success)
				current_plane.refuse();
		}

		Plane moving_plane;
		if(!enmergency)
			switch(small_airport.activity(current_time, moving_plane)){
				case land:
					break;
				case takingoff:
					moving_plane.fly(current_time);
					break;
				case idle:
					run_idle(current_time);
					break;
			}
	}
	small_airport.shut_down(end_time);
	getchar();
	getchar();
	return 0;
}

void initialize(int &end_time, int &queue_limit){
	cout << "This program simulatesa an airport with only one runway." << endl
		<< "One plane can land or depart in each unit of time." << endl
		<< "Up to what number of planes can be waiting to land "
		<< "or take off at any time?" << flush;
	cin >> queue_limit;
	cout << "How many units of time will the simulation run?" << flush;
	cin >> end_time;
}

void run_idle(int time){
  cout << time << ": Runway is idle" << endl;
}

int debuger(std::string notice) {
	bool acceptable = false;
	int res;
	do {
		cout << notice << "(please type in a positive number)";
		cin >> res;
		if (res >= 0)
			acceptable = true;
	} while (!acceptable);
	return res;
}

