#include "Plane.hpp"

Plane::Plane(int fit, int time, Plane_status status){
  fit_num = fit;
  clock_start = time;
  state = status;
  cout << "Plane number " << fit << " ready to ";
  if(status == arriving)
    cout << "land." << endl;
  else
    cout << "take off." << endl;
}

Plane::Plane(){
  fit_num = -1;
  clock_start = -1;
  state = null;
}

void Plane::refuse() const{
  cout << "Plane number " << fit_num;
  if (state == arriving)
    cout << " directed to another airport" << endl;
  else
    cout << " told to try to takeoff again later" << endl;
}

void Plane::land(int time) const{
  int wait = time - clock_start;
  cout << time << ": Plane number " << fit_num << " landed after "
    << wait << " time unit" << ((wait == 1) ? "" : "s")
    << " in the landing queue." << endl;
}

void Plane::fly(int time) const{
  int wait = time - clock_start;
  cout << time << ": Plane number " << fit_num << " took off after "
  << wait << " time unit" << ((wait == 1) ? "" : "s")
  << " in the takeoff queue." << endl;
}

int Plane::started() const{
  return clock_start;
}

Plane& Plane::operator=(const Plane& in) {
	this->fit_num = in.fit_num;
	this->clock_start = in.clock_start;
	this->state = in.state;
	return *this;
}