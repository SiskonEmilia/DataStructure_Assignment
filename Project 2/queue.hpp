#ifndef MY_QUEUE
#define MY_QUEUE
#include <string>
#define MAX_QUEUE_SIZE 50

template<typename dataType>
class queue{
private:
    dataType storage[MAX_QUEUE_SIZE];
    unsigned head;
    unsigned rear;
    unsigned size;
    
public:
    queue():head(0), rear(0), size(0){}
    bool push(const dataType& dataIn){
        if(size != MAX_QUEUE_SIZE){
            ++size;
            storage[++head] = dataIn; 
            return true
        }
        return false;
    }
    bool pop(){
        if(size != 0){
            ++rear;
            return true;
        }
        return false;
    }
    dataType& front(){
        if(size != 0){
            return storage[rear];
        }
        else{
            throw std::string("Error: Trying to get top from an empty stack.");
        }
    }
    bool isEmpty(){
        return size == 0;
    }
    unsigned size(){
        return size;
    }
};


#endif