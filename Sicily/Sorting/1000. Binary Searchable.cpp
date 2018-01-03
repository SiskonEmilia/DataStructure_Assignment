#include <stdio.h>

int length;
int data[100];
int temp, res;
bool status[100];

int main() {
  status[0] = true;
  while(scanf("%d", &length) != EOF) {
    res = 0;
    for (int i = 0; i < length; ++i) {
      scanf("%d", data + i);
    }

    temp = data[0];
    for (int i = 1; i < length; ++i) {
      if (data[i] >= temp){
        temp = data[i];
        status[i] = true;
      }
      else {
        status[i] = false;
      }
    }

    temp = data[length - 1];
    for (int i = length - 1; i >= 0; --i) {
      if (data[i] <= temp){
        temp = data[i];
        if (status[i]) {
          ++res;
        }
      }
    }

    printf("%d\n", res);
  }
}