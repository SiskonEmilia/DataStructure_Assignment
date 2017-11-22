#include <iostream>
using namespace std;

int num;
int tests;
int nums[20];
int counter = 0;

int main () {

  cin >> tests;
  for (; tests > 0; --tests) {
    counter = 0;
    cin >> num;

    for (int i = 0; i < num; ++i) {
      cin >> nums[i];
    }

    for (int i = 0; i < num - 1; ++i) {
      for (int t = i + 1; t < num; ++t) {
        if (nums[i] == nums[t] * 2 || nums[t] == nums[i] * 2 ) {
          ++counter;
        }
      }
    }

    cout << counter << endl;
  }
}