#include <stdio.h>
#include <algorithm>
using namespace std;

int num;
int length;
int dataIn[1000];
int temp;

int main() {
  scanf("%d", &num);
  for (int i = 0; i < num; ++i) {
    scanf("%d", &length);
    for (int t = 0; t < length; ++t) {
      scanf("%d", dataIn + t);
    }
    sort(dataIn, dataIn + length);
    for (int t = 0; t < length; ++t) {
      printf("%d\n", dataIn[t]);
    }
  }
  return 0;
}