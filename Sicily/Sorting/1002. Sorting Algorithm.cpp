#include <stdio.h>
#include <algorithm>
using std::sort;

int length, gap;
int data[1000000];
int temp;

int main() {
    
  while (1) {
    scanf("%d", &length);
    
    if(length == 0)
      return 0;
    
    scanf("%d", &gap);
    for (int t = 0; t < length; ++t) {
      scanf("%d", data + t);
    }

    sort(data, data + length);

    for (int t = 0; t < length; t += gap) {
      printf("%d ", data[t]);
    }
  }

  return 0;
}