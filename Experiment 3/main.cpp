#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

int capacity, item;
std::vector<int> items;

void solve(std::vector<int> ans, unsigned index = 0, int weight = 0);
void print(std::vector<int>& ans);

int main(){
  
  while(1){
    cout << "Tell me the capacity of your backpack:" << endl << ">";
    cin >> capacity;
    getchar();
    if(capacity <= 0){
      cout << "There's no such backpack in the world" << endl
        << "Press enter to try again." << endl << ">";
      getchar();
	  continue;
    }
	break;
  }

  cout << "Give me some items to store (ended with EOF):" << endl << ">";
  while(cin >> item){
    if(item <= 0)
      cout << "Neagative numbers and zero will not be accepted!\n";
    else
      items.push_back(item);
  }

  solve(std::vector<int>());
  cout << "Press enter to exit..." << endl << ">";
  getchar();
  getchar();

  return 0;
}

void solve(std::vector<int> ans, unsigned index, int weight){
  if (index < items.size())
	solve(ans, index + 1, weight);
  else
	return;
  ans.push_back(items[index]);
  weight += items[index];
  if(weight == capacity)
    return print(ans);
  solve(ans, index + 1, weight);
}

void print(std::vector<int>& ans){
  cout << "(" << ans[0];
  for(int i = 1; i < ans.size(); ++i)
    cout << ", " << ans[i];
  cout << ")" << endl;
}