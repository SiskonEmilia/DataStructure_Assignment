#ifndef HASH_H
#define HASH_H
#define MAX_SIZE 1000
#include <iostream>
#include <string>
#include <fstream>
#include <list>
using namespace std;

struct Student {
  string name;
  string gender;
  string stuid;
  string phone;
  Student(string name = "", string gender = "", string stuid = "", string phone = ""):
  name(name), gender(gender), stuid(stuid), phone(phone){}
  Student(const Student &student) :
  name(student.name), gender(student.gender), stuid(student.stuid), phone(student.phone) {}
};

struct StuFound {
  list<Student>::iterator iter;
  int times;
  StuFound(list<Student>::iterator iter, int times): iter(iter), times(times) {}
};

class hash_map {

  list<Student> map[MAX_SIZE];
public:
  
  hash_map(){
    string name, gender, stuid, phone, subname;
    unsigned index;
    fstream file("name.data", ios::in);

    while(file >> name) {
      file >> subname >> gender >> stuid >> phone;
      name += " " + subname;
      index = getHash(name);
      map[index].push_back(Student(name, gender, stuid, phone));
    }
  }

  unsigned getHash(string name) {
    unsigned hash = 5381;
    for (unsigned i = 0; i < name.length(); ++i) {
      hash = (hash << 5) + name[i];
    }
    return hash % MAX_SIZE;
  }

  list<StuFound> findStu(string name) {
    int counter = 0;
    list<StuFound> res;
    auto index = getHash(name);
    for (auto iter = map[index].begin(); iter != map[index].end(); ++iter) {
      ++counter;
      if (iter->name == name) {
        res.push_back(StuFound(iter, counter));
      }
    }
    return res;
  }

  bool insert(Student student) {
    auto index = getHash(student.name);
    map[index].push_back(student);
    return true;
  }

  bool deleteStu(list<Student>::iterator iter) {
    auto index = getHash(iter->name);
    map[index].erase(iter);
    return true;
  }

  void printAll() {
    for(unsigned i = 0; i < MAX_SIZE; ++i) {
      for (auto iter = map[i].begin(); iter != map[i].end(); ++iter) {
        printUser(iter);
      }
    }
  }

  static void printUser(list<Student>::iterator iter) {
    cout <<
    "-------------------------------" << endl <<
    "Name  : " + iter->name << endl <<
    "Gender: " + iter->gender << endl <<
    "Stuid : " + iter->stuid << endl <<
    "Phone : " + iter->phone << endl <<
    "-------------------------------" << endl << endl;
  }
};

#endif