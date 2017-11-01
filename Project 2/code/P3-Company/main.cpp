#include "Runway.hpp"
#include "Random.hpp"

void initialize(int &end_time, int&queue_limit,
	double &arrival_rate, double &departure_rate);

void run_idle(int time);

int main() {
	int end_time;
	int queue_limit;
	int flight_number = 0;
	double arrival_rate, departure_rate;
	bool flag = false;
	initialize(end_time, queue_limit, arrival_rate, departure_rate);
	Random variable;
	Runway landing_runway(queue_limit);
	Runway takingoff_runway(queue_limit);
	for (int current_time = 0; current_time < end_time; ++current_time) {
		
		int number_arrivals = variable.poisson(arrival_rate);
		for (int i = 0; i < number_arrivals; ++i) {
			Plane current_plane(flight_number++, current_time, arriving);
				if (landing_runway.can_land(current_plane) != success)
					current_plane.refuse();
		}

		int number_departures = variable.poisson(departure_rate);
		for (int j = 0; j < number_departures; ++j) {
			Plane current_plane(flight_number++, current_time, departing);
				if (takingoff_runway.can_depart(current_plane) != success)
					current_plane.refuse();
		}

		Plane moving_plane;

		Runway_activity fullFlag = (landing_runway.getLanding().size() == queue_limit) ? land : takingoff;
		switch (takingoff_runway.activity(current_time, moving_plane, fullFlag)) {
		case land:
			moving_plane.land(current_time);
			break;
		case takingoff:
			moving_plane.fly(current_time);
			break;
		case idle:
			switch (takingoff_runway.activity(current_time, moving_plane, idle)) {
			case land:
				moving_plane.land(current_time);
				break;
			case idle:
				run_idle(current_time);
				break;
			}
			break;
		}
		
		switch (landing_runway.activity(current_time, moving_plane, land)) {
			case land:
				moving_plane.land(current_time);
			break;
			case idle:
				switch (landing_runway.activity(current_time, moving_plane, idle)) {
					case takingoff:
						moving_plane.fly(current_time);
						break;
					case idle:
						run_idle(current_time);
					break;
				}
			break;
		}

	}
	landing_runway.shut_down(end_time);
	takingoff_runway.shut_down(end_time);
	return 0;
}

void initialize(int &end_time, int &queue_limit,
double &arrival_rate, double &departure_rate){
	cout << "This program simulatesa an airport with only one runway." << endl
		<< "One plane can land or depart in each unit of time." << endl
		<< "Up to what number of planes can be waiting to land "
		<< "or take off at any time?" << flush;
	cin >> queue_limit;
	cout << "How many units of time will the simulation run?" << flush;
	cin >> end_time;
	bool acceptable;
	do{
		cout << "Expected number of arrivals per unit time?" << flush;
		cin >> arrival_rate;
		cout << "Expected number of departures per unit time?" << flush;
		cin >> departure_rate;
		if (arrival_rate < 0.0 || departure_rate < 0.0)
			cerr << "These rates must be nonnegative." << endl;
		else acceptable = true;
		if (acceptable && arrival_rate + departure_rate > 1.0)
			cerr << "Safety Warning: This ariport will become saturated." << endl;
	}while(!acceptable);
}

void run_idle(int time){
  cout << time << ": Runway is idle" << endl;
}


