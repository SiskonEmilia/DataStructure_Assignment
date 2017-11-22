#include <queue>
#include <iostream>

using namespace std;

queue<int> q1, q2, res;

int main() {
  int in;
  for (int i = 0; i < 5; ++i) {
    cin >> in;
    q1.push(in);
  }
  for (int i = 0; i < 5; ++i) {
    cin >> in;
    q2.push(in);
  }
  for (int i = 0; i < 10; ++i) {
    if (q1.empty()) {
      res.push(q2.front());
      q2.pop();
    }
    else if (q2.empty()) {
      res.push(q1.front());
      q1.pop();
    }
    else {
      if (q1.front() < q2.front()) {
        res.push(q1.front());
        q1.pop();
      }
      else {
        res.push(q2.front());
        q2.pop();
      }
    }
  }
  for (int i = 0; i < 10; ++i) {
    cout << res.front() << " ";
    res.pop();
  }
}