#ifndef RUNWAY_H
#define RUNWAY_H
#include "Plane.hpp"
#include "myQueue.hpp"

enum Runway_activity {idle, land, takingoff};

class Runway {
private:
  static Extended_queue<Plane> landing;
  static Extended_queue<Plane> takeoff;
  int queue_limit;
  int num_land_requests;
  int num_takeoff_requests;
  int num_landings;
  int num_takeoffs;
  int num_land_accepted;
  int num_takeoff_accepted;
  int num_land_refused;
  int num_takeoff_refused;
  int land_wait;
  int takeoff_wait;
  int idle_time;

public:
  Runway(int limit);
  Error_code can_land(const Plane &current);
  Error_code can_depart(const Plane &current);
  Runway_activity activity(int time, Plane &moving, Runway_activity priority = idle);
  Extended_queue<Plane>& getLanding();
  Extended_queue<Plane>& getTakingoff();
  void shut_down(int time) const;
};

#endif