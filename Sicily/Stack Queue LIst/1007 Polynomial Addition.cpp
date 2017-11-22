#include <iostream>
using namespace std;


class Poly {
public:
  Poly() {
    for (int i = 0; i < 10001; ++i) {
      _storage[i] = 0;
    }
  }

  void add(int coff, int power) {
    _storage[power] += coff;
  }

  void add(const Poly& poly) {
    for(int i = 0; i < 10001; ++i) {
      _storage[i] += poly._storage[i];
    }
  }

  void print() {
    int counter = 0;

    for(int i = 10000; i >= 0; --i) {
      if(_storage[i] != 0) {
        ++counter;
      }
    }
    cout << counter << endl;
    for(int i = 10000; i >= 0; --i) {
      if(_storage[i] != 0) {
        cout << _storage[i] << " " << i << endl;
      }
    }
  }

  void clear() {
    for (int i = 0; i < 10001; ++i) {
      _storage[i] = 0;
    }
  }

private:
  int _storage[10001];
};

Poly in1, in2;
int num, i1, i2, siz;

int main() {
  cin >> num;
  for(int i = 0 ; i < num; ++i) {
    in1.clear();
    in2.clear();
    cin >> siz;
    for(int i = 0; i < siz; ++i) {
      cin >> i1 >> i2;
      in1.add(i1, i2);
    }
    cin >> siz;
    for(int i = 0; i < siz; ++i) {
      cin >> i1 >> i2;
      in2.add(i1, i2);
    }
    in1.add(in2);
    in1.print();
  }
}