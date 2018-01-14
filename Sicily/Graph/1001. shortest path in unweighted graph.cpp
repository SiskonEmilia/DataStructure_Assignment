#include <stdio.h>
#include <queue>
#define MAX_N 1000
using std::queue;

int graph[MAX_N][MAX_N];
int paths[MAX_N];
bool isvisited[MAX_N];
int edges, vertexs;
int stap, endp;
queue<int> vertexQueue;

void init() {
  for (int i = 0; i < MAX_N; ++i) {
    for (int t = 0; t < MAX_N; ++t)
      graph[i][t] = -1;
    graph[i][i] = 0;
    paths[i] = -1;
    isvisited[i] = false;
  }
}

void bfs() {
  int temp;
  vertexQueue.push(0);
  isvisited[0] = true;
  paths[0] = 0;
  while(!vertexQueue.empty()) {
    temp = vertexQueue.front();
    vertexQueue.pop();
    for (int i = 0; i < vertexs; ++i) {   
      if (graph[temp][i] > 0 && !isvisited[i]){
        isvisited[i] = true;
        paths[i] = paths[temp] + 1;
        vertexQueue.push(i);
      }
    }
  }
}

int main() {
  init();
  scanf("%d %d", &vertexs, &edges);
  for (int i = 0; i < edges; ++i) {
    scanf("%d %d", &stap, &endp);
    graph[stap - 1][endp - 1] = graph[endp - 1][stap - 1] = 1;
  }
  bfs();
  for (int i = 0; i < vertexs; ++i) {
    printf("%d ", paths[i]);
  }
  printf("\n");
}