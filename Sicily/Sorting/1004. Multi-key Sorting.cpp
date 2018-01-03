#include <cstdio>

int isShow[1000001];
int size1, size2, counter;
int sequences[3000000];

int main() {
  while(scanf("%d", &size1) != EOF) {
    for (int i = 1; i <= size1; ++i)
      isShow[i] = -1;
    scanf("%d", &size2);

    for (int i = 0; i < size2; ++i) {
      scanf("%d", sequences + i);
      isShow[sequences[i]] = i;
    }

    counter = 0;
    for (int i = 1; i <= size1; ++i)
      if (isShow[i] != -1) ++counter;

    printf("%d\n", counter);

    int i = 0;
    while(1) {
      if (isShow[sequences[i]] == i) {
        printf("%d", sequences[i]);
        break;
      }
      ++i;
    }
    
    for (++i; i < size2; ++i) {
      if (isShow[sequences[i]] == i) {
        printf(" %d", sequences[i]);
      }
    }
    printf("\n");

  }
  return 0;
}