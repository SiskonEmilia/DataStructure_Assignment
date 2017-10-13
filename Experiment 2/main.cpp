#include <iostream>
#include <vector>
#include <string>
#include "queue.hpp"
#include "stack.hpp"

using namespace std;

unsigned numOfStack = 0, numOfQueue = 0;
vector<queue<char>> queueArr;
vector<stack<char>> stackArr;

void aCreatStack(){
  stackArr.push_back(stack<char>());
  ++numOfStack;
  cout 
    << "\nSucceed!\n"
    << numOfStack << " stacks avaliable now.\n"
    << "Press enter to continue.\n"
    << ">";
  getchar();
}

void bCreatQueue(){
  queueArr.push_back(queue<char>());
  ++numOfQueue;
  cout 
    << "\nSucceed!\n"
    << numOfQueue << " queues avaliable now.\n"
    << "Press enter to continue.\n"
    << ">";
  getchar();
}

void cTopOf(){
  unsigned index;
  cout 
    << "\nPlease type in the number of which stack you want to check:\n"
    << ">";
  cin >> index;
  getchar();
  if(index > numOfStack || index <= 0){
    cout << "Invalid input: no such stack.\n";
  }
  else{
    try{
      cout << stackArr[index - 1].top() << endl;
    }
    catch(string err){
      cout << err << endl;
    }
  }
  cout 
    << "Press enter to return menu.\n"
    << ">";
  getchar();
}

void dFrontOf(){
  unsigned index;
  cout 
    << "\nPlease type in the number of which queue you want to check:\n"
    << ">";
  cin >> index;
  getchar();
  if(index > numOfQueue || index <= 0){
    cout << "Invalid input: no such queue.\n";
  }
  else{
    try{
      cout << queueArr[index - 1].front() << endl;
    }
    catch(string err){
      cout << err << endl;
    }
  }
  cout 
    << "Press enter to return menu.\n"
    << ">";
  getchar();
}

void eAddToStack(){
  unsigned index;
  cout 
    << "\nPlease type in the number of which stack you want to push into:\n"
    << ">";
  cin >> index;
  getchar();
  if(index > numOfStack || index <= 0){
    cout << "Invalid input: no such stack.\n";
  }
  else{
    string res;
    cout << "Please type in the content you want to push into:\n"
      << ">";
    getline(cin, res);
    try{
      for(auto i:res){
        if(i == ' ')
          continue;
        if(!stackArr[index - 1].push(i)){
          cout << "Failure: No enough storage\n";
          throw string("");
        }
      }
      cout << "Succeed!\n";
    }
    catch(...){}
  }
  cout 
    << "Press enter to return menu.\n"
    << ">";
  getchar();
}

void fAddToQueue(){
  unsigned index;
  cout 
    << "\nPlease type in the number of which queue you want to push into:\n"
    << ">";
  cin >> index;
  getchar();
  if(index > numOfQueue || index <= 0){
    cout << "Invalid input: no such queue.\n";
  }
  else{
    string res;
    cout << "Please type in the content you want to push into:\n"
      << ">";
    getline(cin, res);
    try{
      for(auto i:res){
        if(i == ' ')
          continue;
        if(!queueArr[index - 1].push(i)){
          cout << "Failure: No enough storage\n";
          throw string("");
        }
      }
      cout << "Succeed!\n";
    }
    catch(...){}
  }
  cout 
    << "Press enter to return menu.\n"
    << ">";
  getchar();
}

void gPopFromStack(){
  unsigned index;
  cout 
    << "\nPlease type in the number of which stack you want to pop from:\n"
    << ">";
  cin >> index;
  getchar();
  if(index > numOfStack || index <= 0){
    cout << "Invalid input: no such stack.\n";
  }
  else{
    if(stackArr[index - 1].pop()){
      cout << "Succeed!\n";
    }
    else{
      cout << "Error: Trying to pop from an empty stack.\n";
    }
  }
  cout 
    << "Press enter to return menu.\n"
    << ">";
  getchar();
}

void hPopFromQueue(){
  unsigned index;
  cout 
    << "\nPlease type in the number of which queue you want to pop from:\n"
    << ">";
  cin >> index;
  getchar();
  if(index > numOfQueue || index <= 0){
    cout << "Invalid input: no such queue.\n";
  }
  else{
    if(queueArr[index - 1].pop()){
      cout << "Succeed!\n";
    }
    else{
      cout << "Error: Trying to pop from an empty queue.\n";
    }
  }
  cout 
    << "Press enter to return menu.\n"
    << ">";
  getchar();
}

void iShow(){
  cout << "\nHere's " << numOfStack << " stacks avaliable and " << numOfQueue << " queues avaliable.\n"
    << "Press enter to continue.\n"
    << ">";
  getchar();
}

int main(){
  string strHandle;
  while(1){
    cout 
      << "\n-----------------------------------------------\n"
      << "Please select the function you want to use:\n"
      << "a.Create a new stack\n"
      << "b.Create a new queue\n"
      << "c.Check a specific stack's top element\n"
      << "d.Check a specific queue's front element\n"
      << "e.Add an element to a specific stack\n"
      << "f.Add an element to a specific queue\n"
      << "g.Pop an element from a specific stack\n"
      << "h.Pop an element from a specific queue\n"
      << "i.Show that how many stacks and queues have been created\n"
      << "q.Quit\n"
      << ">";
    cin >> strHandle;
    getchar();
    
    if(strHandle.length() == 1){
      switch(strHandle[0]){
        case 'a': case 'A':
          aCreatStack();
          break;
        case 'b': case 'B':
          bCreatQueue();
          break;
        case 'c': case 'C':
          cTopOf();
          break;
        case 'd': case 'D':
          dFrontOf();
          break;
        case 'e': case 'E':
          eAddToStack();
          break;
        case 'f': case 'F':
          fAddToQueue();
          break;
        case 'g': case 'G':
          gPopFromStack();
          break;
        case 'h': case 'H':
          hPopFromQueue();
          break;
        case 'i': case 'I':
          iShow();
          break;
        case 'q': case 'Q':
          cout << "Thanks for your using!\n";
          return 0;
          break;
        default:
          cout 
            << "Invalid input, press enter to try again!\n"
            << ">";
          getchar();
          break;
      }
    }
    else{
      cout 
        << "Invalid input, press enter to try again!\n"
        << ">";
        getchar();
    }
  }
  return 0;
}