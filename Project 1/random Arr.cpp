#include <iostream>  
#include <vector>
#include <ctime>  
#include <algorithm> // std::move_backward  
#include <random> // std::default_random_engine  
#include <chrono> // std::chrono::system_clock 
using namespace std; 
  
int main (int argc, char* argv[])  
{  
    std::vector<int> v;  
    int num;
    srand((unsigned)time(0));
    num = rand() % 1000;    
    for (int i = 0; i < num; ++i) {  
        v.push_back (i);  
    }  
  
    // obtain a time-based seed:  
    unsigned seed = std::chrono::system_clock::now ().time_since_epoch ().count ();  
    std::shuffle (v.begin (), v.end (), std::default_random_engine (seed));  
  
    cout << num << endl;
    for (auto& it : v) {  
        std::cout << it + 1 << " ";  
    }  
  
    std::cout << "\n";  
  
    return 0;  
} 