#include <string>
#include <vector>
using namespace std;

vector<string> strs;

void parseEmail(const string& str){
  string pre, post;
  int index = 0;
  while (index <= str.length()) {
    for (; index < str.length(); ++index) {
      if (str[index] >= '0' && str[index] <= '9'){
        pre += str[index];
        continue;
      }
      else if (str[index] >= 'A' && str[index] <= 'Z'){
        pre += str[index];
        continue;
      }
      else if (str[index] >= 'a' && str[index] <= 'z') {
        pre += str[index];
        continue;
      }
      else if (str[index] == '_' || str[index] == '-') {
        pre += str[index];
        continue;
      }
      else if (str[index] == '.') {
        if (index <= 0 || str[index - 1] == '.') {
          pre = "";
          continue;
        }
        post += str[index];
        continue;
      }  
    }
  
    for (; index < str.length; ++index) {
      if (str[index] >= '0' && str[index] <= '9'){
        post += str[index];
        continue;
      }
      else if (str[index] >= 'A' && str[index] <= 'Z'){
        post += str[index];
        continue;
      }
      else if (str[index] >= 'a' && str[index] <= 'z') {
        post += str[index];
        continue;
      }
      else if (str[index] == '_' || str[index] == '-') {
        post += str[index];
        continue;
      }
      else if (str[index] == '.') {
        if (index <= 0 || str[index - 1] == '.') {
          pre = post = "";
          break;
        }
        post += str[index];
        continue;
      } 
    }
  }
}

int main() {
  string temp;
  while(cin >> temp) {
    strs.push_back(temp);
  }

  cout << strs[0] << endl;
  for (int i = 1; i < strs.length() - 1; ++i)
    parseEmail(strs[i]);
  cout << strs[strs.length() - 1] << endl;
}