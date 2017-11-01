#ifndef MY_LIST
#define MY_LIST

#include <iostream>
#define MAX_SIZE 10
using namespace std;


template<typename T>
struct Node{
  Node<T> *next;
  T data;
  Node(const T &data, Node<T> *next = nullptr):data(data), next(next){}
};

template<typename T>
class linkedList{
private:
  Node<T> *head;
  unsigned _size;
public:
  linkedList():head(nullptr), _size(0){}
  ~linkedList(){
    clear();
  }

  bool append(const T &dataIn, unsigned index = 0){
    if(index > _size)
      return false;
    if(head){
      if(index == 0){
        Node<T> *temp = new Node<T>(dataIn, head);
        if(temp == nullptr)
          return false;
        head = temp;
        ++_size;
      }
      else{
        Node<T> *prev = head, *temp;
        for(int i = 1; i < index; ++i){
          prev = prev->next;
        }
        temp = new Node<T>(dataIn, prev->next);
        if(temp == nullptr)
          return false;
        prev->next = temp;
        ++_size;
      }
    }
    else{
      head = new Node<T>(dataIn);
      if(head == nullptr)
        return false;
      ++_size;
    }
    return true;
  }

  bool remove(unsigned index = 0){
    if(index >= _size)
      return false;

    if(index == 0){
      Node<T> *temp = head;
      head = head->next;
      delete temp;
      --_size;
    }
    else{
      Node<T> *prev = head, *temp;
      for(int i = 1; i < index; ++i){
        prev = prev->next;
      }
      temp = prev->next;
      prev->next = prev->next->next;
      delete temp;
      --_size;
    }
    return true;
  }

  void clear(){
    Node<T> *temp = head;
    while(temp != nullptr){
      head = head->next;
      delete temp;
      temp = head;
    }
    _size = 0;
  }

  void print(){
    Node<T> *temp = head;
    while(temp != nullptr){
      cout << temp->data << "->";
      temp = temp->next;
    }
    cout << "NULL" << endl;
  }
};

template<typename T>
class arrayList{
private:
  T _storage[MAX_SIZE];
  unsigned _size;
public:
  arrayList():_size(0){}
  
  bool append(const T &dataIn, unsigned index = 0){
    if(index > _size)
      return false;
    if(_size >= MAX_SIZE)
      return false;

    for(int i = index; i < _size - 1; ++i){
      _storage[i + 1] = _storage[i];
    }
    _storage[index] = dataIn;
    ++_size;
    return true;
  }

  bool remove(unsigned index = 0){
    if(index >= _size)
      return false;
    
    for(int i = index; i < _size - 1; ++i){
      _storage[i] = _storage[i + 1];
    }
    --_size;
    return true;
  }

  void clear(){
    _size = 0;
  }

  void print(){
    for(int i = 0; i < _size; ++i)
      cout << _storage[i] << "->";
    cout << "NULL" << endl;
  }

};

#endif