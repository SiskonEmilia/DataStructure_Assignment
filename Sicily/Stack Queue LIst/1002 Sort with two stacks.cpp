#include <stack>
#include <iostream>
#define MAX_N 1003
using namespace std;

bool biMap[MAX_N][MAX_N] = { { false } };
char color[MAX_N] = { 0 };
int queue[MAX_N] = { 0 };
int small[MAX_N] = { 0 };
int num;

void calculate() {
	stack<int> s1, s2;
	int index = 0, pre = 1, counter = 0;;
	while (pre != num + 1) {
		if (!s1.empty() && s1.top() == pre) {
			s1.pop();
			++pre;
			cout << "b";
			if (++counter != num)
				cout << " ";
			else
				cout << endl;
		}
		else if (!s2.empty() && s2.top() == pre) {
			s2.pop();
			++pre;
			cout << "d";
			if (++counter != num)
				cout << " ";
			else
				cout << endl;
		}
		else {
			switch (color[index]) {
			case 1:
				s1.push(queue[index++]);
				cout << "a ";
				break;
			case 2:
				s2.push(queue[index++]);
				cout << "c ";
				break;
			default:
				cout << "Error!" << endl;
				exit(0);
			}
		}
	}
}

bool setColor(int index, char colorIn) {
	color[index] = colorIn;
	for (int i = index + 1; i < num; ++i) {
		if (biMap[index][i]) {
			if (color[i] == colorIn) {
				return false;
			}
			if (!setColor(i, 3 - colorIn)) return false;
		}
	}
	return true;
}

void constructMap() {
	for (int i = 0; i < num; ++i) {
		for (int t = 0; t < num; ++t) {
			biMap[i][t] = false;
		}
	}

	for (int i = 0; i < num; ++i) {
		for (int t = i + 1; t < num; ++t) {
			if (queue[i] < queue[t] && queue[i] > small[t]) {
				biMap[i][t] = biMap[t][i] = true;
			}
		}
	}
}

void findMin() {
	for (int i = num; i > 0; --i) {
		small[i - 1] = small[i];
		if (queue[i - 1] < small[i - 1]) {
			small[i - 1] = queue[i - 1];
		}
	}
}


int main() {
	int temp;
	bool flag;
	while (cin >> num) {
		flag = true;
		for (int i = 0; i < num; ++i) {
			cin >> temp;
			queue[i] = temp;
			color[i] = 0;
		}
		small[num] = 0x7fffffff;
		findMin();
		constructMap();
		for (int i = 0; i < num; ++i) {
			if (!color[i])
				if (!setColor(i, 1)) {
					flag = false;
					break;
				}
		}
		if (flag)
			calculate();
		else
			cout << "0" << endl;
	}
}