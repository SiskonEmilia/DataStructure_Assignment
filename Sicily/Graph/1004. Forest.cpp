#include <stdio.h>
#include <list>
#define MAX_N 100
using std::list;

struct Path {
  int from;
  int to;
  Path(int from, int to) : from(from), to(to){}
};

list<Path> vertexs[MAX_N];
int indegree[MAX_N];
int numV, numP;
int from, to;
bool isVisited[MAX_N];
bool isValid;
int widths[MAX_N + 1];
int heights[MAX_N];

void clear() {
  for (int i = 0; i < MAX_N; ++i) {
    vertexs[i].clear();
    isVisited[i] = false;
    widths[i] = 0;
    heights[i] = 0;
    indegree[i] = 0;
  }
  widths[MAX_N] = 0;
  isValid = true;
}

void dfs(int index) {
  isVisited[index] = true;
  for (auto iter : vertexs[index]) {
    if (isVisited[iter.to]) {
      isValid = false;
      return;
    }
    else {
        heights[iter.to] = heights[index] + 1;
        widths[heights[index] + 1] += 1;
        dfs(iter.to);
    }
  }
}

void init() {
  for (int i = 0; i < numV && isValid; ++i) {
    if (!isVisited[i] && indegree[i] == 0) {
      heights[i] = 0;
      widths[0] += 1;
      dfs(i);
    }
  }
  int t = 0;
  for (int i = 0; i < numV; ++i) {
    t += widths[i];
  }
  if (t != numV) {
    isValid = false;
  }
}

int main() {
  while(scanf("%d %d", &numV, &numP) != EOF) {
    if (numV == 0)
      break;
    clear();
    for (int i = 0; i < numP; ++i) {
      scanf("%d %d", &from, &to);
      vertexs[from - 1].push_back(Path(from - 1, to - 1));
      indegree[to - 1] += 1;
    }
    init();
    if (isValid) {
      int maxheight = 0, maxwidth = 0;
      for (int i = 0; i <= numV; ++i) {
        if (widths[i] > 0) {
          if (widths[i] > maxwidth){
            maxwidth = widths[i];
          }
        }
        else {
          maxheight = i - 1;
          break;
        }
      }
      printf("%d %d\n", maxheight, maxwidth);
    }
    else {
      printf("INVALID\n");
    }
  }

  return 0;
}