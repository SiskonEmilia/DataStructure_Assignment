#ifndef MY_QUEUE
#define MY_QUEUE

template<typename dataType>
class queue{
private:
    dataType storage[50];
    unsigned head;
    unsigned rear;
    
public:
    queue();
    bool push();
    bool pop();
    bool front();
    bool isEmpty();
    unsigned size();
};


#endif