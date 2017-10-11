#ifndef MY_STACK
#define MY_STACK
#include <string>

template <typename dataType>
struct node
{
    dataType data;
    node *next;
    node(dataType data, node *next = nullptr);
};

template <typename dataType>
class stack
{
  private:
    node<dataType> *head;
    unsigned size;

  public:
    stack() : head(nullptr), size(0) {}
    ~stack(){
        node<dataType> *temp = head;
        while(size--){
            temp = head->next;
            delete head;
            head = temp;
        }
    }

    bool push(const dataType& dataIn){
        if(size++){
            node<dataType> *temp = head;
            head = new node<dataType>(dataIn, head);
            if(head == nullptr){
                head = temp;
                --size;
                return false;
            }
        }
        else{
            head = new node<dataType>(dataIn);
            if(head == nullptr){
                --size;
                return false;
            }
        }
        return true;
    }

    bool pop(){
        if(size){
            --size;
            node<dataType> *temp = head->next;
            delete head;
            head = temp;
            return true;
        }
        else
            return false;
    }

    dataType& top(){
        if(size){
            return head->data;
        }
        else{
            throw std::string("Error: Trying to get top from an empty stack.");
        }
    }

    unsigned size(){
        return size;
    }

    bool isEmpty(){
        return size == 0;
    }
};

#endif