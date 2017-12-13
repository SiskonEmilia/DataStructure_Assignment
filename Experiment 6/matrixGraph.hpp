#ifndef MATRIX_GRAPH_H
#define MATRIX_GRAPH_H
#include "global.hpp"

class matrixGraph {
public:
    matrixGraph() {
        for (int i = 0; i < MAX_N; ++i){
            isVisited[i] = false;
            for (int t = 0; t < MAX_N; ++t) {
                graph[i][t] = make_pair(false, -1);
            }
        }
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
        for(int i = 0; i < size; ++i) {
            if (!isVisited[i] && graph[index][i].first && i != index) {
                DFS(i, blanks + 1);
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
                    for (int t = 0; t < size; ++t) {
                        if (!isVisited[t] && graph[i][t].first && t != i) {
                            indexs.push(t);
                            isVisited[t] = true;
                        }
                    }
                }
                cout << endl;
            }
        }
    }

    void printNodes() {
        for (int i = 0 ; i < size; ++i)
            cout << "#" << i << ": "
                << nodes[i] << endl;
    }

    bool addNode(const string& node) {
        if (size >= MAX_N)
            return false;
        nodes[size++] = node;
        return true;
    }

    bool addEdge(const int &index1, const int &index2, const unsigned& weight) {
        if (index1 >= size || index2 >= size || index1 == index2 || index1 < 0 || index2 < 0 || weight <= 0)
            return false;
        graph[index1][index2] = graph[index2][index1] = make_pair(true, weight);
        return true;
    }


private:
    pair<bool, unsigned> graph[MAX_N][MAX_N];
    string nodes[MAX_N];
    bool isVisited[MAX_N];
    int size;
};

#endif