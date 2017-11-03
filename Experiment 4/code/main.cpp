#include <string>
#include "myList.hpp"
using namespace std;

linkedList<char> *list1 = nullptr;
arrayList<char> *list2 = nullptr;

int main(){
  string inputHandler;
  char ele;
  unsigned index;
  while (true) {
    cout 
      << "--------------------MENU-------------------\n"
      << "a. Creat a linked list.\n"
      << "b. Creat an array list.\n"
      << "c. Append an element to the linked list.\n"
      << "d. Append an element to the array list.\n"
      << "e. Remove an element from the linked list.\n"
      << "f. Remove an element from the array list.\n"
      << "g. Print all elements in the linked list.\n"
      << "h. Print all elements in the array list.\n"
      << "q. Quit.\n"
      << "Please select the function you want to use:\n>";
    cin >> inputHandler;
    getchar();
    if(inputHandler.size() != 1){
      cout << "Invalid input, press enter to try again.\n>";
      getchar();
      continue;
    }
    switch(inputHandler[0]){
      case 'a':
      if(list1){
        cout << "You've created one!\n"
          << "Press enter to continue.\n>";
        getchar();
      }
      else{
        list1 = new linkedList<char>;
        cout << "Success!\n"
          << "Press enter to continue.\n>";
        getchar();
      }
      break;
      case 'b':
      if(list2){
        cout << "You've created one!\n"
          << "Press enter to continue.\n>";
        getchar();
      }
      else{
        list2 = new arrayList<char>;
        cout << "Success!\n"
          << "Press enter to continue.\n>";
        getchar();
      }
      break;
      case 'c':
        cout << "Please type in the element you want to append:\n>";
        cin >> ele;
        getchar();
        cout << "Please type in the index that you want to append to:\n>";
        cin >> index;
        getchar();
        if(list1 == nullptr){
          cout << "You haven't creat a list.\n"
            << "Press enter to continue.\n";
          getchar();
        }
        if(list1->append(ele, index)){
          cout << "Success!\n"
            << "Press enter to continue.\n";
          getchar();
        }
        else{
          cout << "Failed!\n"
            << "Press enter to continue.\n";
          getchar();
        }
        break;
      case 'd':
        cout << "Please type in the element you want to append:\n>";
        cin >> ele;
        getchar();
        cout << "Please type in the index that you want to append to:\n>";
        cin >> index;
        getchar();
        if(list2 == nullptr){
          cout << "You haven't creat a list.\n"
            << "Press enter to continue.\n";
          getchar();
        }
        if(list2->append(ele, index)){
          cout << "Success!\n"
            << "Press enter to continue.\n";
          getchar();
        }
        else{
          cout << "Failed!\n"
            << "Press enter to continue.\n";
          getchar();
        }
        break;
      case 'e':
        cout << "Please type in the index of element that you want to remove:\n>";
        cin >> index;
        getchar();
        if(list1 == nullptr){
          cout << "You haven't creat a list.\n"
            << "Press enter to continue.\n";
          getchar();
        }
        if(list1->remove(index)){
          cout << "Success!\n"
            << "Press enter to continue.\n";
          getchar();
        }
        else{
          cout << "Failed!\n"
            << "Press enter to continue.\n";
          getchar();
        }
        break;
      case 'f':
        cout << "Please type in the index of element that you want to remove:\n>";
        cin >> index;
        getchar();
        if(list2 == nullptr){
          cout << "You haven't creat a list.\n"
            << "Press enter to continue.\n";
          getchar();
        }
        if(list2->remove(index)){
          cout << "Success!\n"
            << "Press enter to continue.\n";
          getchar();
        }
        else{
          cout << "Failed!\n"
            << "Press enter to continue.\n";
          getchar();
        }
        break;
      case 'g':
        if(list1){
          list1->print();
          cout << "Success!\n"
            << "Press enter to continue.\n";
          getchar();
        }
        else{
          cout << "You haven't creat a list.\n"
            << "Press enter to continue.\n";
          getchar();
        }
      break;
      case 'h':
        if(list2){
          list2->print();
          cout << "Success!\n"
            << "Press enter to continue.\n";
          getchar();
        }
        else{
          cout << "You haven't creat a list.\n"
            << "Press enter to continue.\n";
          getchar();
        }
      break;
      case 'q':
      if(list1) delete list1;
      if(list2) delete list2;
      cout << "Thanks for your using..." << endl;
      return 0;
      default:
      cout << "Invalid input, press enter to try again.\n>";
      getchar();
      continue;
      break;
    }
  }
}