#include <iostream>
#include <string>
using namespace std;

string res, rev;
int index = 0;

int parseInt();
int isNumber(const char& ch);

int main() {
	while (cin >> rev) {
		if (rev == "XXX") {
			return 0;
		}
    res = "";
		for (index = 0; index < rev.length(); ++index) {
			if (isNumber(rev[index]) != -1) {
				char toRepeat = rev[index - 1];
				res += string(parseInt() - 1, toRepeat);
			}
			else {
				res += rev[index];
			}
		}
		cout << res << endl;
	}
}

int isNumber(const char& ch) {
	if (ch >= '0' && ch <= '9')
		return ch - '0';
	return -1;
}

int parseInt() {
	int res = 0, temp = 0;
	while ((temp = isNumber(rev[index])) != -1) {
		res *= 10;
		res += temp;
		++index;
	}
	--index;
	return res;
}