#include <iostream>
#include <cstdio>
#define MAX_N 1000
using namespace std;

int number, counter = 0, limit;
int px = 0, py;
int mySquare[MAX_N][MAX_N] = { 0 };

int main(){
	cout << "Emilia: Give me an odd number, and I'll give you a magic square of that size.\n";
	
	while(1){
		cin >> number;
		if(number < MAX_N && number > 0 && number % 2 == 1)
			break;
		cout << "Emilia: I can do nothing with this number. Could you give me another one?\n";
	}

	py = number / 2;
	limit = number - 1;
	number = number * number;
	mySquare[px][py] = ++counter;
	px = limit;++py;
	while(1){
		if(counter == number)
			break;
		mySquare[px][py] = ++counter;
		--px;++py;
		if(py > limit)
			py = 0;
		if(px < 0)
			px = limit;
		if(mySquare[px][py] > 0){
			px += 1;
			py -= 1;
			if(px > limit)
				px = 0;
			if(py < 0)
				py = limit;
			px += 1;
			if(px > limit)
				px = 0;
		}
	}

	cout << "Here you are~ Your Magic Square:\n";
	for(int i = 0; i <= limit; ++i){
		for(int t = 0; t <= limit; ++t){
			printf("%7d ", mySquare[i][t]);
		}
		cout << endl;
	}
}