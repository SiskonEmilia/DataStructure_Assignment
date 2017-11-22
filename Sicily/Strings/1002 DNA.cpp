#include <vector>
#include <string>
#include <iostream>
using namespace std;


int tests = 0, num = 0, counter = 0;
string temp;

void getCom(vector<string>& ori, vector<string>& com) {
  for (int i = 0; i < num; ++i) {
    temp = "";
    for (int t = 0; t < ori[i].length(); ++t) {
      switch(ori[i][t]) {
        case 'A':
        temp += "T";
        break;
        
        case 'T':
        temp += "A";
        break;
        
        case 'C':
        temp += "G";
        break;

        case 'G':
        temp += "C";
        break;
        
        default:
        break;
      }
    }
    com.push_back(temp);
  }
}

int main() {
  cin >> tests;
  for (; tests > 0; --tests) {
    vector<string> ori, com;
    counter = 0;
    cin >> num;

    for (int i = 0; i < num; ++i) {
      cin >> temp;
      ori.push_back(temp);
    }
    getCom(ori, com);

    for (int i = 0; i < num; ++i) {
      for (int t = i + 1; t < num; ++t) {
        if (ori[i] == com[t]) {
          ++counter;
          com[t] = "M";
          ori[t] = "E";
          break;
        }
      }
    }

    cout << counter << endl;
  }
}