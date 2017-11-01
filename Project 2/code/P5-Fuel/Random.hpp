#ifndef MYRAND_H
#define MYRAND_H

#include <ctime>
#include <cmath>

class Random {
private:
  int reseed();
  double random_real();
  int seed,
    multiplier,
    add_on;
public:
  Random(bool pseudo = true);
  int poisson(double mean);
};

#endif