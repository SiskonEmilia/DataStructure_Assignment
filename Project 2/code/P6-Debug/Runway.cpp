#include "Runway.hpp"

Runway::Runway(int limit){
  queue_limit = limit;
  num_land_requests = num_takeoff_requests = 0;
  num_landings = num_takeoffs = num_crashs = num_emergency =0;
  num_land_refused = num_takeoff_refused = 0;
  num_land_accepted = num_takeoff_accepted = 0;
  land_wait = takeoff_wait = idle_time = 0;
}

Error_code Runway::can_land(const Plane &current){
  Error_code result;
  if (landing.size() < queue_limit)
    result = landing.append(current);
  else 
    result = fail;
  ++num_land_requests;
  if (result != success)
    ++num_land_refused;
  else
    ++num_land_accepted;
  return result;
}

Error_code Runway::can_depart(const Plane &current){
  Error_code result;
  if (takeoff.size() < queue_limit)
    result = takeoff.append(current);
  else
    result = fail;
  ++num_takeoff_requests;
  if (result != success)
    ++num_takeoff_refused;
  else
    ++num_takeoff_accepted;
  return result;
}

Runway_activity Runway::activity(int time, Plane &moving){
  Runway_activity in_progress;
  if(!landing.empty()){
    landing.retrieve(moving);
    land_wait += time - moving.started();
	landing.serve();
    if(moving.land(time))
      ++num_landings;
	else {
	  ++num_crashs;
	  cout << "Runway is trying to deal with the next request." << endl;
	  return activity(time, moving);
	}
	in_progress = land;
  }
  else if (!takeoff.empty()){
    takeoff.retrieve(moving);
    takeoff_wait += time - moving.started();
    ++num_takeoffs;
    in_progress = takingoff;
    takeoff.serve();
  }
  else{
    ++idle_time;
    in_progress = idle;
  }
  return in_progress;
}

void Runway::emergency_land(){
	++num_land_accepted;
	++num_land_requests;
    ++num_landings;
	++num_emergency;
}

void Runway::shut_down(int time) const{
  cout << "Simulation has concluded after " << time << " time units." << endl
    
    << "Total number of planes processed "
    << (num_land_requests + num_takeoff_requests) << endl
    
    << "Total number of planes asking to land "
    << num_land_requests << endl  
    << "Total number of planes asking to takeoff "
    << num_takeoff_requests << endl
   
    << "Total number of planes accepted to land "
    << num_land_accepted << endl
    << "Total number of planes accepted to takeoff "
    << num_takeoff_accepted << endl
    
    << "Total number of planes refused to land "
    << num_land_refused << endl
    << "Total number of planes refused to takeoff "
    << num_takeoff_refused<< endl
    
    << "Total number of planes that landed "
    << num_landings << endl
    << "Total number of planes that tookoff "
    << num_takeoffs << endl
	<< "Total number of planes that landed under the emergency situation "
	<< num_emergency << endl
    << "Total number of planes that crashed "
    << num_crashs << endl
    
    << "Total number of planes left in landing queue "
    << landing.size() << endl
    << "Total number of planes left in takeoff queue "
    << takeoff.size() << endl
    
    << "Precentage of time runway idle "
    << 100.0 * ((float)idle_time)/((float)time) << "%" << endl

    << "Average wait in landing queue "
    << ((float)land_wait) / ((float) time)
    << " per time unit" << endl
    << "Average wait in takeoff queue "
    << ((float)takeoff_wait) / ((float) time)
    << " per time unit" << endl

    << "Average observed rate of planes wanting to land "
    << ((float)num_land_requests) / ((float)time)
    << " per time unit" << endl

    << "Average observed rate of planes wanting to takeoff "
    << ((float)num_takeoff_requests) / ((float)time)
    << " per time unit" << endl;
}

int Runway::waitingTime(){
  return landing.size();
}