#include <iostream>
#define MAX_N 1000
using namespace std;

int num;
int matrix[MAX_N][MAX_N];

bool solve(){
	int sum = 0, test;
		for(int i = 0; i < num; ++i){
			sum += matrix[0][i];
		}

		for(int t = 0; t < num; ++t){
			test = 0;
			for(int i = 0; i < num; ++i){
				test += matrix[t][i];
			}
			if(test != sum)
				return false;
		}

		for(int t = 0; t < num; ++t){
			test = 0;
			for(int i = 0; i < num; ++i){
				test += matrix[i][t];
			}
			if(test != sum)
				return false;
		}

		test = 0;
		for(int i = 0; i < num; ++i){
			test += matrix[num - i - 1][i];
		}
		if(test != sum)
			return false;

		test = 0;
		for(int i = 0; i < num; ++i){
			test += matrix[i][i];
		}
		if(test != sum)
			return false;

		return true;
	
}

int main(){
	ios::sync_with_stdio(false);
	cout << "Please type in the size of your square: [size < 100000]\n";
	cin >> num;
	for(int i = 0; i < num; ++i){
		for(int t = 0; t < num; ++t){
			cin >> matrix[i][t];
		}
	}

	if(solve()){
		cout << "Dadala~~ You've found a magic square!\n";
	}
	else{
		cout << "Opps... It seems that it is not a magic square...\n";
	}

	return 0;
}