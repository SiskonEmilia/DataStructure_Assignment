#include <map>
#include <cstdio>
using namespace std;

struct Data {
  int data;
  Data():data(0){}
};

map<int, Data> dataset;
int num, temp, length;
bool isStart = true;

int main() {
  scanf("%d", &num);
  for (int t = 0; t < num; ++t) {

    for(int i = 0; i < num; ++i) {
      scanf("%d", &temp);
      dataset[temp].data += 1;
    }

    for (auto i : dataset) {
      if (i.second.data == 1)
      printf("%d ", i.first);
    }

    printf("\n");
  }
  return 0;
}