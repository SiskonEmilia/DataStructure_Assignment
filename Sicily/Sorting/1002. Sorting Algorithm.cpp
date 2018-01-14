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

    printf("%d", data[0]);
    for (int t = gap; t < length; t += gap) {
      printf(" %d", data[t]);
    }
    printf("\n");
  }

  return 0;
}