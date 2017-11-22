#include <stack>
#include <string>
#include <iostream>
using namespace std;

int main() {
  int counter = 0;
  string toVerify;
  stack<char> Stack;
  cin >> counter;
  
  for(int i = 0; i < counter; ++i) {
    cin >> toVerify;
    for (int t = 0; t < toVerify.length(); ++t) {
      switch(toVerify[t]) {
        case '(':
          Stack.push('(');
        break;

        case '[':
          Stack.push('[');
        break;
        
        case '{':
          Stack.push('{');
        break;

        case ')':
          if(!Stack.empty() && Stack.top() == '(') {
            Stack.pop();
          }
          else {
            Stack.push('E');
            t = toVerify.length();
          }
        break;

        case ']':
          if(!Stack.empty() && Stack.top() == '[') {
            Stack.pop();
          }
          else {
            Stack.push('E');
            t = toVerify.length();
          }
        break;

        case '}':
          if(!Stack.empty() && Stack.top() == '{') {
            Stack.pop();
          }
          else {
            Stack.push('E');
            t = toVerify.length();
          }
        break;

        default:
        break;
      }
    }
    if(Stack.empty()) {
      cout << "Yes" << endl;
    }
    else {
      cout << "No" << endl;
    }

    while(!Stack.empty()) {
      Stack.pop();
    }
  }
}  