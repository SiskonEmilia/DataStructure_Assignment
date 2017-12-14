#include <iostream>
#include <list>

using namespace std;

list<int> edges[1000];
bool isVisited[1000];
int size = 0, num = 0, res = 0;

void DFS(int i) {
    isVisited[i] = true;
    for (auto e : edges[i]) {
        if (!isVisited[e]) {
            DFS(e);
        }
    }
}

int main() {
    for (int i = 0; i < 1000; ++i) 
        isVisited[i] = false;
    cin >> size >> num;
    int from, to;
    for (int i = 0; i < num; ++i) {
        cin >> from >> to;
        edges[from - 1].push_back(to - 1);
        edges[to - 1].push_back(from - 1);
    }
    for (int i = 0; i < size; ++i) {
        if (!isVisited[i]) {
            isVisited[i] = true;
            DFS(i);
            ++res;
        }
    }
    cout << res << endl;
    return 0;
}
