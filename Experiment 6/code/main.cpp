#define MAX_N 1000
#include "listGraph.hpp"
#include "matrixGraph.hpp"
using namespace std;

graphList listgraph;
matrixGraph matrixgraph;

void insertNode (int which) {
    string name;
    cout << "Please type in the name of the vertex you want to insert:" << endl;
    cin >> name;
    getchar();
    switch(which) {
        case 1:
            if (listgraph.addNode(name)) {
                cout << "Succeeded!\nPress enter to return to menu." << endl;
                getchar();
            }
            else {
                cout << "This graph has been full!\nPress enter to return to menu." << endl;
                getchar();
            }
        break;
        case 2:
            if (matrixgraph.addNode(name)) {
                cout << "Succeeded!\nPress enter to return to menu." << endl;
                getchar();
            }
            else {
                cout << "This graph has been full!\nPress enter to return to menu." << endl;
                getchar();
            }
        break;
    }
}

void insertEdge (int which) {
    int index1, index2, weight;
    cout << "Please type in indexs of those two vertexs you want to connect and the weight of this edge:" << endl;
    cin >> index1 >> index2 >> weight;
    getchar();
    switch(which) {
        case 1:
            if (listgraph.addEdge(index1, index2, weight)) {
                cout << "Succeeded!\nPress enter to return to menu." << endl;
                getchar();
            }
            else {
                cout << "Falied due to invalid input!\nPress enter to return to menu." << endl;
                getchar();
            }
        break;
        case 2:
            if (matrixgraph.addEdge(index1, index2, weight)) {
                cout << "Succeeded!\nPress enter to return to menu." << endl;
                getchar();
            }
            else {
                cout << "Falied due to invalid input!\nPress enter to return to menu." << endl;
                getchar();
            }
        break;
    }
}

void print (int which) {
    cout << endl;
    switch(which) {
        case 1:
            listgraph.printNodes();
        break;
        case 2:
            matrixgraph.printNodes();
        break;
    }
    cout << "\nPress enter to return to menu." << endl;
    getchar();
}

void dfs (int which) {
    cout << endl;
    switch(which) {
        case 1:
            listgraph.DFSprint();
        break;
        case 2:
            matrixgraph.DFSprint();
        break;
    }
    cout << "\nPress enter to return to menu." << endl;
    getchar();
}

void bfs (int which) {
    cout << endl;
    switch(which) {
        case 1:
            listgraph.BFSprint();
        break;
        case 2:
            matrixgraph.BFSprint();
        break;
    }
    cout << "\nPress enter to return to menu." << endl;
    getchar();
}

void dijkstra (int which) {
    int index;
    cout << "Please type in the index of the starting vertex:" << endl;
    cin >> index;
    getchar();
    switch(which) {
        case 1:
            listgraph.shortest(index);
        break;
        case 2:
            matrixgraph.shortest(index);
        break;
    }
    cout << "\nPress enter to return to menu." << endl;
    getchar();
}


int main(){
    string input;
    while (true) {
        cout 
            << "----------------------------------------------------------\n"
            << "a. Insert an element to graph implemented with list\n"
            << "b. Insert an element to graph implemented with matrix\n"
            << "c. Add edges between vertexs of graph implemented with list\n"
            << "d. Add edges between vertexs of graph implemented with matrix\n"
            << "e. Print vertexs of graph implemented with list\n"
            << "f. Print vertexs of graph implemented with matrix\n"
            << "g. Traverse the graph implemented with list with DFS\n"
            << "h. Traverse the graph implemented with matrix with DFS\n"
            << "i. Traverse the graph implemented with list with BFS\n"
            << "j. Traverse the graph implemented with matrix with BFS\n"
            << "k. Get the shortest path from a vertex to others (list)\n"
            << "l. Get the shortest path from a vertex to others (matrix)\n"
            << "q. quit\n"
            << "Please select the function you want to use:" << endl;
        cin >> input;
        getchar();

        if (input.length() != 1){
            cout << "Invalid input, type enter to try again.\n";
            getchar();
            continue;
        }

        switch (input[0]) {
            case 'a':
                insertNode(1);
            break;
            
            case 'b':
                insertNode(2);
            break;
            
            case 'c':
                insertEdge(1);
            break;
            
            case 'd':
                insertEdge(2);
            break;
            
            case 'e':
                print(1);
            break;
            
            case 'f':
                print(2);
            break;
            
            case 'g':
                dfs(1);
            break;
            
            case 'h':
                dfs(2);
            break;
            
            case 'i':
                bfs(1);
            break;

            case 'j':
                bfs(2);
            break;

            case 'k':
                dijkstra(1);
            break;

            case 'l':
                dijkstra(2);
            break;
            
            case 'q':
                cout << "Thanks for your using." << endl;
                return 0;
            break;

            default:
                cout << "Invalid input, type enter to try again.\n";
                getchar();
            continue;
        }           
    }
    return 0;
}