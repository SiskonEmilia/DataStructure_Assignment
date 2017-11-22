#include <iostream>
#include <string>
using namespace std;

int* find_next(int *P, int m) {
	int *pi = new int[m + 1];
	pi[1] = pi[0] = 0;
	int k = 0;
	for (int q = 2; q <= m; ++q) {
		while (k > 0 && k < m && P[k + 1] != P[q]) k = pi[k];
		if (k < m && P[k + 1] == P[q]) ++k;
		pi[q] = k;
	}
	return pi;
}

int KMP(int *T, int *P, int n, int m) {
	int q = 0;
	auto pi = find_next(P, m);
	for (int i = 1; i <= n; ++i) {
		while (q > 0 && q <= m && P[q + 1] != T[i]) {
			q = pi[q];
		}
		if (q < m && P[q + 1] == T[i]) {
			++q;
		}
		if (q == m) {
			delete[] pi;
			return i - m;
		}
	}

	delete[] pi;
	return -1;
}

int main() {
	int num1, num2, temp;
	while (cin >> num1) {
		int *substr = new int[num1 + 1];
		for (int i = 1; i <= num1; ++i) {
			cin >> temp;
			substr[i] = temp;
		}
		cin >> num2;
		int *str = new int[num2 + 1];
		for (int i = 1; i <= num2; ++i) {
			cin >> temp;
			str[i] = temp;
		}
		temp = KMP(str, substr, num2, num1);
		if (temp != -1)
			cout << temp << endl;
		else
			cout << "no solution" << endl;

		delete[] substr;
		delete[] str;
	}
}

