#include "hash.hpp"
using namespace std;

hash_map map;

void menuPage() {
  cout << "************************Menu************************" << endl
       << "* a. Display the hash map     b. Find an element   *" << endl
       << "* c. Insert an element        d. Delete an element *" << endl
       << "* q. Quit                                          *" << endl
       << "****************************************************" << endl
       << ">";
}

void printError() {
  cout << "Invalid input, press enter to try agagin!";
  getchar();
}

void findStu() {
  string input, name, subname;
  cout << "Please type in the first name and last name of the person you want to find:" << endl
       << "(format: [first name] [last name])" << endl
       << ">";
  cin >> name >> subname;
  input = name + " " + subname;
  getchar();
  auto res = map.findStu(input);
  if (res.size() == 0) {
    cout << "NO DATA FOUND" << endl
         << "Press enter to return." << endl
         << ">";
    getchar();
  }
  else {
    int counter = 0;
    for (auto iter = res.begin(); iter != res.end(); ++iter) {
      cout << "#" << ++counter << ": " << endl
           << "Found after " << iter->times << " times of comparing." << endl;
      map.printUser(iter->iter);
    }
  }
}

void insertStu() {
  string name, gender, stuid, phone, subname;
  cout << "Please type in the first and last name of the person you want to insert:" << endl
       << "(format: [first name] [last name])" << endl
       << ">";
  cin >> name >> subname;
  cout << "Please type in the gender of the person you want to insert:" << endl
       << ">";
  cin >> gender;
  cout << "Please type in the student ID of the person you want to insert:" << endl
       << ">";
  cin >> stuid;
  cout << "Please type in the phone number of the person you want to insert:" << endl
       << ">";
  cin >> phone;
  getchar();
  map.insert(Student(name + " " + subname, gender, stuid, phone));
  cout << "Success! Press enter to return." << endl
       << ">";
  getchar();
}

void deleteStu() {
  string input, name, subname;
  cout << "Please type in the first name and last name of the person you want to find:" << endl
       << "(format: [first name] [last name])" << endl
       << ">";
  cin >> name >> subname;
  input = name + " " + subname;
  getchar();
  auto res = map.findStu(input);
  if (res.size() == 0) {
    cout << "NO DATA FOUND" << endl
         << "Press enter to return." << endl
         << ">";
    getchar();
  }
  else {
    int counter = 0;
    for (auto iter = res.begin(); iter != res.end(); ++iter) {
      cout << "#" << ++counter << ": " << endl
           << "Found after " << iter->times << " times of comparing." << endl;
      hash_map::printUser(iter->iter);
    }
    cout << "Which piece of data do you want to delete? Tell me the number of it:" << endl
         << ">";
    cin >> counter;
    getchar();
    if (counter > res.size() || counter <= 0) {
      cout << "Invalid input. Press enter to return." << endl
           << ">";
      getchar();
      return;
    }
    else {
      auto iter = res.begin();
      for (int i = 1; i < counter; ++i) {
        ++iter;
      }
      map.deleteStu(iter->iter);
      cout << "Success! Press enter to return." << endl
           << ">";
      getchar();
    }
  }
}

int main() {
  string input;
  while (1) {
    menuPage();
    cin >> input;
    getchar();
    if (input.length() != 1) {
      printError();
      continue;
    }
    switch (tolower(input[0])) {
      case 'a':
        map.printAll();
        break;
      case 'b':
        findStu();
        break;
      case 'c':
        insertStu();
        break;
      case 'd':
        deleteStu();
        break;
      case 'q':
        return 0;
        break;
      default:
        printError();
        break;
    }
  }
  return 0;
}
