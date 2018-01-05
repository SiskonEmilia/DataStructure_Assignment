#include <stdio.h>

bool data[20000001];
int num, k, temp;

int main() {
  scanf("%d%d", &num, &k);
  for (int i = 0; i < num; ++i) {
    scanf("%d", &temp);
    data[temp + 10000000] = true;
  }
  temp = 0;
  for (int t = 20000000; true; --t) {
    if (data[t]) {
      ++temp;
      if (temp == k) {
        printf("%d\n", t - 10000000);
        return 0;
      }
    }
  }
  return 0;
}