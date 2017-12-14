#ifndef LIST_GRAPH_H
#define LIST_GRAPH_H
#include "global.hpp"
#include <list>
using namespace std;

class graphList {
public:
    graphList() {
        for (int i = 0; i < MAX_N; ++i)
            isVisited[i] = false;
        size = 0;
    }

    void DFSprint() {
        for (int i = 0; i < MAX_N; ++i)
            isVisited[i] = false;
        if (size == 0)
            return;
        for (int i = 0; i < size; ++i) {
            DFS(i, 0);
        }
    }

    void DFS(const int &index, const unsigned blanks) {
        if (isVisited[index])
            return;
        for (unsigned i = 0; i < blanks; ++i) {
            cout << " ";
        }
        cout << nodes[index] << endl;
        isVisited[index] = true;
        for(auto i: graph[index]) {
            if (!isVisited[i.first]) {
                DFS(i.first, blanks + 1);
            }
        }
    }

    void BFSprint() {
        for (int i = 0; i < MAX_N; ++i)
            isVisited[i] = false;
        if (size == 0)
            return;
        queue<int> indexs;
        for (int i = 0; i < size; ++i) {
            if(!isVisited[i]) {
                indexs.push(i);
                isVisited[i] = true;
                while (!indexs.empty()) {
                    auto index = indexs.front();
                    indexs.pop();
                    cout << nodes[index] << endl;
                    for (auto t: graph[index]) {
                        if (!isVisited[t.first]) {
                            indexs.push(t.first);
                            isVisited[t.first] = true;
                        }
                    }
                }
                cout << endl;
            }
        }

    }

    void printNodes() {
        for (int i = 0; i < size; ++i) {
            cout << "#" << i << ": "
                << nodes[i] << endl;
        }
    }

    bool addNode(const string& node) {
        if (size >= MAX_N)
            return false;
        nodes[size++] = node;
        return true;
    }

    bool addEdge(const int &index1, const int &index2, const int& weight) {
        if (index1 >= size || index2 >= size || index1 == index2 || index1 < 0 || index2 < 0 || weight <= 0)
            return false;
        graph[index1].push_back(make_pair(index2, weight));
        graph[index2].push_back(make_pair(index1, weight));
        return true;
    }

    void shortest(const int &index) {
        if (index >= size || index < 0) {
            cout << "Invalid input.";
            return;
        }

        for (int i = 0; i < MAX_N; ++i)
            isVisited[i] = false;
        isVisited[index] = true;

        int *path = new int[size];
        int newIndex;
        for (int i = 0; i < size; ++i) {
            path[i] = -1;
        }
        path[index] = 0;

        for (auto i : graph[index]) {
            path[i.first] = i.second;
        }

        while ((newIndex = findMin(path)) != -1) {
            refreshPath(path, newIndex);
        }


        for (int i = 0; i < size ; ++i) {
            if (path[i] != -1)
                cout << nodes[index] << "->" << nodes[i] << ":"
                    << path[i] << endl;
            else {
                cout << "There's no valid path from " << nodes[index] << " to " << nodes[i] << endl;
            }
        }
        
        delete []path;
    }

    int findMin(int *path) {
        int minDistance = -1, index = -1;
        for (int i = 0; i < size; ++i) {
            if (!isVisited[i] && path[i] != -1) {
                if (minDistance == -1 || path[i] < minDistance) {
                    minDistance = path[i];
                    index = i;
                }
            }
        }
        if (index != -1)
            isVisited[index] = true;
        return index;
    }

    void refreshPath(int *path, int newVertex) {
        int temp;
        for (auto edge : graph[newVertex]) {
            temp = path[newVertex] + edge.second;
            if (path[edge.first] > temp || path[edge.first] == -1) {
                path[edge.first] = temp;
            }
        }
    }

private:
    list< pair<int, unsigned> > graph[MAX_N];
    string nodes[MAX_N];
    bool isVisited[MAX_N];
    int size;
};

#endif