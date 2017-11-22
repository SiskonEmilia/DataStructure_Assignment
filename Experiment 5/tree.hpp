#ifndef MY_TREE
#define MY_TREE

#include <iostream>
using namespace std;

class BTree {
public:
  BTree():_size(0), _presentStorage(10000) {
    _storage = new int[_presentStorage];
  }

  ~BTree() {
    delete[] _storage;
  }
  
  bool empty() const {
    return _size == 0;
  }

  unsigned size() const {
    return _size;
  }

  void append (const int& data) {
    if (_size == _presentStorage)
      extendStorage();
    _storage[_size++] = data;
  }

  int& operator[] (const unsigned& index) {
    if (index > _size)
      throw "RANGE_ERROR";
    return _storage[index - 1];
  }

  void print (unsigned position = 1, unsigned counter = 0) {
    if (position > _size)
      return;
    for (int i = 0; i < counter; ++i)
      cout << '|';
    cout << _storage[position - 1] << endl;
    print(position * 2, counter + 1);
    print(position * 2 + 1, counter + 1);
  }

  void interChange(unsigned position = 1) {
    if (position > _size)
      return;
    auto temp = _storage[position - 1];
    _storage[position - 1] = _storage[position];
    _storage[position] = temp;
    interChange(position * 2);
    interChange(position * 2 + 1);
  }

private:
  void extendStorage() {
    _presentStorage *= 2;
    auto temp = new int[_presentStorage];
    for (unsigned i = 0; i < _size; ++i) {
      temp[i] = _storage[i];
    }
    delete[] _storage;
    _storage = temp;
  }

  int *_storage;
  unsigned _size;
  unsigned _presentStorage;
};

#endif
