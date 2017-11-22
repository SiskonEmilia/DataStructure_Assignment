#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

string part1, part2;
vector<string> strs;
string temp;

int main() {
  while(getline(cin, temp)) {
    if (temp == string(temp.size(), ' ')){
      strs.push_back("");
    }
    reverse(temp.begin(), temp.end());
    temp = temp.substr(temp.length() / 2) + temp.substr(0, temp.length() / 2);
    strs.push_back(temp);
  }
  for (int i = 1; i < strs.size(); i += 2) {
    if (strs[i] != "")
      cout << strs[i] << endl;
    if (strs[i - 1] != "")  
      cout << strs[i - 1] << endl;
  }
  if (strs.size() % 2 == 1) {
    if (strs[strs.size() - 1] != "")
    cout << strs[strs.size() - 1] << endl;
  }
}

