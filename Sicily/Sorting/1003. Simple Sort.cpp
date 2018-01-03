#include <cstdio>
#include <algorithm>
using namespace std;

struct myData{
  int priorities[11];
};

myData entries[100];
myData orders[10];
int _size;
int num;
int length1, length2;

bool compare(const myData& a, const myData& b) {
  for(int i = 0; i < _size; ++i) {
    if (a.priorities[orders[i].priorities[0]] < b.priorities[orders[i].priorities[0]])
      return true;
    if (a.priorities[orders[i].priorities[0]] > b.priorities[orders[i].priorities[0]])
      return false; 
  }
  return false;
}

bool ordCom(const myData& a, const myData& b) {
  return a.priorities[1] < b.priorities[1];
}

int main() {
  scanf("%d", &num);
  for (int i = 0; i < num; ++i) {
    scanf("%d %d", &length1, &_size);
    for (int t = 0; t < length1; ++t) {
      entries[t].priorities[0] = t;
      for (int j = 0; j < _size; ++j) {
        scanf("%d", entries[t].priorities + j + 1);
      }
    }
    
    scanf("%d", &length2);
    for (int t = 0; t < length2; ++t) {
      for (int j = 0; j < _size; ++j) {
        orders[j].priorities[0] = j + 1;
        scanf("%d", orders[j].priorities + 1);
      }
      sort(orders, orders + _size, ordCom);
      stable_sort(entries, entries + length1, compare);
      printf("%d", entries[0].priorities[0]);
      for (int j = 1; j < length1; ++j) {
        printf(" %d", entries[j].priorities[0]);
      }
      printf("\n");
    }
  }
}