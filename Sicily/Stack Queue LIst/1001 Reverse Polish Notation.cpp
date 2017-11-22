#include <stack>
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

stack<char> oprs;
string str;
unsigned num;

void solve();
double cal();

int main() {
  cin >> num;
  for (unsigned i = 0; i < num; ++i) {
    cin >> str;
    solve();
  }
}

void solve() {

  for (unsigned i = 0; i < str.length(); ++i) {
    oprs.push(str[i]);
  }

  cout << fixed << setprecision(2) << cal() << endl;
  
}

double cal() {
  char opr = oprs.top();
  double temp;
  oprs.pop();
  switch (opr) {
    case '+':
      return cal() + cal();
    case '-':
      temp = cal();
      return cal() - temp;
    case '*':
      return cal() * cal();
    case '/':
      temp = cal();
      return cal() / temp;
    default:
      return opr - 'a' + 1;
  }
}