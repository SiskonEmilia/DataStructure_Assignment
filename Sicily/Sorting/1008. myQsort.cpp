#include <stdio.h>

int num;
int length;
int data[1000];
int temp;

void swap(int& a, int& b) {
  temp = a;
  a = b;
  b = temp;
}

int partition(int start, int end) {
  int pivox = data[end];
  int i = start - 1;
  for (int j = start; j < end; ++j) {
    if (data[j] <= pivox) {
      ++i;
      swap(data[i], data[j]);
    }
  }
  swap(data[i + 1], data[end]);
  return i + 1;
}

void quickSort(int start, int end) {
  if (start < end) {
    int p = partition(start, end);
    quickSort(start, p - 1);
    quickSort(p + 1, end);
  }
}

int main() {
    scanf("%d", &num);
  for (int i = 0; i < num; ++i) {
    scanf("%d", &length);
    for (int t = 0; t < length; ++t) {
      scanf("%d", data + t);
    }
    quickSort(0, length - 1);
    for (int t = 0; t < length; ++t) {
      printf("%d\n", data[t]);
    }
  }
  return 0;
}