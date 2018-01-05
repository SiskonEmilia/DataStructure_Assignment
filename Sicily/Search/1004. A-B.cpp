#include <algorithm>
#include <cstdio>
using namespace std;

int data1[100000],
    data2[100000],
    res[100000];
int task, length1, length2;

void solve() {
  int index1 = 0,
      index2 = 0,
      size = 0;
  while (index1 != length1) {
    for (;index1 < length1;) {
      if (data1[index1] < data2[index2] || index2 == length2) {
        res[size++] = data1[index1];
        do{
          ++index1;
        }while(index1 < length1 && data1[index1] == data1[index1 - 1]);
      }
      else if (data1[index1] == data2[index2]) {
        do{
          ++index1;
        }while(index1 < length1 && data1[index1] == data1[index1 - 1]);
        do{
          ++index2;
        }while(index2 < length2 && data2[index2] == data2[index2 - 1]);
      }
      else {
        do{
          ++index2;
        }while(index2 < length2 && data2[index2] == data2[index2 - 1]);
      }
    }
  }
  if (size != 0)
    printf("%d", res[0]);
  for (int i = 1; i < size; ++i) {
    printf(" %d", res[i]);
  }
  printf("\n");
}

int main() {
  scanf("%d", &task);
  for (int t = 0; t < task; ++t) {
    scanf("%d", &length1);
    for (int i = 0; i < length1; ++i) {
      scanf("%d", data1 + i);
    }

    scanf("%d", &length2);
    for (int i = 0; i < length2; ++i) {
      scanf("%d", data2+ i);
    }

    sort(data1, data1 + length1);
    sort(data2, data2 + length2);

    solve();
  }
}