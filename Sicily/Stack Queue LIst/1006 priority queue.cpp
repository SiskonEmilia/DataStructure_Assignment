#include <iostream>
#include <queue>

using namespace std;

struct node{
    int priority;
    bool isMine;
    node(int priority, bool isMine = false):
    priority(priority), isMine(isMine){}
};

int main(){
    int cases = 0;
    int num = 0, index = 0, priority = 0;


    cin >> cases;
    for(int i = 0; i < cases; ++i){
        priority_queue<int> reference;
        queue<node> myQueue;
        cin >> num >> index;
        for(int t = 0; t < num; ++t){
            cin >> priority;
            reference.push(priority);
            myQueue.push(node(priority, t == index));
        }// Get the job list
        index = 0;
        while(1){
            if(myQueue.front().priority == reference.top()){
                ++index;
                if(myQueue.front().isMine){
                    cout << index << endl;
                    break;
                }
                myQueue.pop();
                reference.pop();
            }
            else{
                myQueue.push(myQueue.front());
                myQueue.pop();
            }
        }
    }



    return 0;
}