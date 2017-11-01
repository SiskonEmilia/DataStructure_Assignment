#ifndef PLANE_H
#define PLANE_H

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::cerr;
using std::flush;

enum Plane_status {null, arriving, departing};

class Plane {
private:
  int fit_num;
  int clock_start;
  int fuel_left;
  Plane_status state;
public:
  Plane();
  Plane(int fit, int time, Plane_status status, int fuel_left);
  Plane(const Plane& in):fit_num(in.fit_num), clock_start(in.clock_start), state(in.state), fuel_left(in.fuel_left){}
  Plane& operator=(const Plane& in);
  void refuse() const;
  bool land(int time) const;
  void fly(int time) const;
  int getFuel() const;
  int started() const;
};

#endif