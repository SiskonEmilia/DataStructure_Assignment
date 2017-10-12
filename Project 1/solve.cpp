#include <stack>
#include <vector>
#include <queue>
#include <exception>
#include <iostream>
#define MAX_N 1000
using std::stack;
using std::vector;
using std::queue;
using std::cout;
using std::cin;
using std::endl;

#ifdef __linux__
// maroc which exists in g++ on linux
#define EMILIA

int number, temp, tar, counter = 0;
bool flag;
stack<int> toSort;
queue<int> beenSort;
vector<stack<int>> stacks;

void solve();

int main(){
  while(1){
    system("reset");
    cout << "Please tell me how many carriages are there.\n>";
    cin >> number; getchar();
    if(number < 0){
      cout << "Negeative number will not be accpted.\nPress enter to retry.\n>";
      getchar();
      continue;
    }
    if(number > MAX_N){
      cout << "Number which is so large will not be accpted.\nPress enter to retry.\n>";
      getchar();
      continue;
    }
    break;
  }

  system("reset");
  cout << "Please give me numbers of those carriages and sperate them with blankspaces.\n(Direction: -----> number start from #1)\n>";
  for(int i = 0; i < number; ++i){
    cin >> temp;
    toSort.push(temp);
  }
  getchar();


  system("reset");
  temp = 0;
  //Use variable temp to store the number of stacks
  while(beenSort.size() != number){
    flag = false;

    // find if 1 is top
    if(toSort.size() && (toSort.top() == 1 || (beenSort.size() && toSort.top() == beenSort.back() + 1))){
      beenSort.push(toSort.top());
      toSort.pop();
      cout << "-----------------------------\n"
        << "\nOperation " << ++counter << endl
        << "\t#" << beenSort.back() << " carriage was sent from waiting queue dirctly to the result queue.\n\n";
      continue;
    }

    // search in stack
    for(int i = 0; i < temp; ++i){
      if(stacks[i].size() && beenSort.size() && stacks[i].top() == beenSort.back() + 1){
        flag = true;
        beenSort.push(stacks[i].top());
        stacks[i].pop();
        cout << "-----------------------------\n"
        << "\nOperation " << ++counter << endl
        << "\t#" << beenSort.back() << " carriage was sent to the result queue from stack #" << i + 1 <<".\n\n";
        break;
      }
    }

    if(flag)
      continue;  

    for(int i = 0, dis = MAX_N + 1; i < temp; ++i){
      if(stacks[i].size() && stacks[i].top() > toSort.top()){
        if(dis > stacks[i].top() - toSort.top()){
          dis = stacks[i].top() - toSort.top();
          tar = i;
          flag = true;
        }
      }
      else if(stacks[i].empty()){
          if(dis > toSort.top()){
            tar = i;
            flag = true;
          }
      }
    }

    if(flag){
      stacks[tar].push(toSort.top());
      toSort.pop();
      cout << "-----------------------------\n"
        << "\nOperation " << ++counter << endl
        << "\t#" <<  stacks[tar].top() << " carriage was sent from the waiting queue to stack #" << tar + 1 <<".\n\n";
      continue;
    }

    ++temp;
    stacks.push_back(stack<int>());
    stacks[temp - 1].push(toSort.top());
    toSort.pop();
    cout << "-----------------------------\n"
        << "\nOperation " << ++counter << endl
        << "\tNew stack created! Its number is " << temp << endl
        << "\t#" << stacks[temp - 1].top() << " carriage was sent to this new stack.\n\n";
  }

  cout << "Direction: <----" << endl;
  while(beenSort.size()){
    cout << beenSort.front() << " ";
    beenSort.pop();
  }

  cout << "\n-----------------------------\n"
    << "Sorting finished.\n"
    << temp << " stack(s) used.\n"
    << counter << " operations executed.\n"
    <<"Press enter to quit.\n>"; getchar();
  /*
      CODE
  1\ find if 1 is top or top = back - 1
  2\ find if stack top = back -1
  3\ find if ava stack
  4\ creat stack    
  */
  return 0;
}

#endif

#ifndef EMILIA
// if not linux or not g++
int main(){
  cout << "Please execute this program on linux system and compile with g++.\n"
    << "If you have any question, send an email to xiongyq7@mail2.sysu.edu.cn\n";
  getchar();
  return 0;
}

#endif