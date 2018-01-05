#include <stdio.h>
#include <list>
using namespace std;

list<int> datas[13];

int getHash(int data) {
  return data % 13;
}

int num, temp;

int main() {
  while(scanf("%d", &num)){
    if (num == 0)
      break;
    for (int i = 0; i < num; ++i) {
      scanf("%d", &temp);
      datas[getHash(temp)].push_back(temp);
    }
    for (int i = 0; i < 13; ++i) {
      printf("%d#", i);
      if (datas[i].empty()) {
        printf("NULL\n");
      }
      else {
        auto iter = datas[i].begin();
        int size = datas[i].size();
        printf("%d", *iter);
        for (int t = 1; t < size; ++t) {
          ++iter;
          printf(" %d", *iter);
        }
        printf("\n");
      }
      datas[i].clear();
    }
  }

  
}