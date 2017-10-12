#include <iostream>
#include <cmath>
using namespace std;

int area, pos, temp, counter, num1, num2;

int main(){
	for(int i = 9; i < 10000; ++i){
		
		pos = 0;
		temp = area = i * i;
		
		while(temp){
			temp /= 10;
			pos += 1;
		}

		for(int t = 1; t < pos; ++t){
			counter = pow(10, t);
			num1 = area / counter;
			num2 = area % counter;
			if ((int)pow((num1 + num2), 2) == area)
			{
				cout << area << endl;
			}
		}
	}
}

// from 0 -> 99999999
// div : 0 -> 9999
// 9999 x 9999 kinds
