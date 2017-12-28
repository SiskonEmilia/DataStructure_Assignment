#include <fstream>
#include <iostream>
#include <cstdlib>

using namespace std;

fstream file("name.data", ios::out);

void printFirst(){
  switch(rand() % 10) {
    case 0:
      file << "Zhang ";
    break;
    case 1:
      file << "Wang ";   
    break;
    case 2:
      file << "Li ";
    break;
    case 3:
      file << "Yang ";
    break;
    case 4:
      file << "Han ";
    break;
    case 5:
      file << "Xiong ";
    break;
    case 6:
      file << "Xu ";
    break;
    case 7:
      file << "Xie ";
    break;
    case 8:
      file << "Ai ";
    break;
    case 9:
      file << "Kai ";
    break;
  }
}

void printLast() {
  switch(rand() % 15) {
    case 0:
      file << "Zhang ";
    break;
    case 1:
      file << "Wang ";   
    break;
    case 2:
      file << "Li ";
    break;
    case 3:
      file << "Yang ";
    break;
    case 4:
      file << "Han ";
    break;
    case 5:
      file << "Xiong ";
    break;
    case 6:
      file << "Xu ";
    break;
    case 7:
      file << "Xie ";
    break;
    case 8:
      file << "Ai ";
    break;
    case 9:
      file << "Kai ";
    break;
    case 10:
      file << "Liya ";
    break;
    case 11:
      file << "Jiewen ";
    break;
    case 12:
      file << "Zijian ";
    break;
    case 13:
      file << "Weiyuan ";
    break;
    case 14:
      file << "Yongqi ";
    break;
  }
}

void getGender() {
  switch(rand() % 3) {
    case 0:
      file << "Male ";
    break;
    case 1:
      file << "Female ";
    break;
    default:
      file << "Unbelievable ";
    break;
  }
}

void getTel() {
  file << "1";
  for (int i = 0; i < 10; ++i)
    file << rand() % 10;
  file << "\n";
}

int main() {
  int num;
  cin >> num;
  for (int i = 0; i < num; ++i) {
    printFirst();
    printLast();
    getGender();
    file << "163402";
    if (i < 10)
      file << "0";
    file << i << " ";
    getTel();
  }
}