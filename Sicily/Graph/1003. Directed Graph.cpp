#include <stdio.h>
#include <list>
#define MAX_N 100
using std::list;

enum edgeType {
  tree, back, down, cross
};

struct Path {
  int from;
  int to;
  edgeType type;
  Path(int from, int to) : from(from), to(to), type(tree) {}
};

list<Path> vertexs[MAX_N];
bool isVisited[MAX_N];
bool isFinished[MAX_N];
int numofvertex, numofpaths;
int from, to, start;

void dfs(int index) {
  isVisited[index] = true;
  for (auto&iter : vertexs[index]) {
    if (!isVisited[iter.to]) {
      iter.type = tree;
      isVisited[iter.to] = true;
      dfs(iter.to);
    }
    else {
      if (vertexs[iter.to].empty() || !isFinished[iter.to]) {
        iter.type = back;
      }
      else {
        if (iter.from == start) {
          iter.type = down;
        }
        else {
          iter.type = cross;
        }
      }
    }
  }
  isFinished[index] = true;
}

void init() {
  for (int i = 0; i < numofvertex; ++i) {
    if (!isVisited[i]) {
      start = i;
      dfs(i);
    }
  }
}

void clear() {
  for (int i = 0; i < MAX_N; ++i) {
    isVisited[i] = isFinished[i] = false;
    vertexs[i].clear();
  }
}

void print(int from, int to) {
  int a = from - 1, b = to - 1;
  for (auto iter : vertexs[a]) {
    if (iter.from == a && iter.to == b) {
      printf("edge (%d,%d) is ", from, to);
      switch(iter.type){
        case tree:
          printf("Tree");
        break;
        case back:
          printf("Back");
        break;
        case down:
          printf("Down");
        break;
        case cross:
          printf("Cross");
        break;
        default:
          printf("Error");
        break;
      }
      printf(" Edge\n");
      break;
    }
  }
}



int main() {
  clear();
  scanf("%d%d", &numofvertex, &numofpaths);
  for (int i = 0; i < numofpaths; ++i) {
    scanf("%d %d", &from, &to);
    vertexs[from - 1].push_back(Path(from - 1, to - 1));
  }
  init();
  scanf("%d", &numofpaths);
  for (int i = 0; i < numofpaths; ++i) {
    scanf("%d %d", &from, &to);
    print(from, to);
  }
  return 0;
}