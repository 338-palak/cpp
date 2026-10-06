#include <bits/stdc++.h>
using namespace std;

bool isSafe(int node, int color[], bool graph[101][101], int n, int col) {

    for (int k = 0; k < n; k++) {

        if (k != node && graph[k][node] == 1 && color[k] == col) {
            return false;
        }
    }

    return true;
}

bool solve(int node, int color[], int m, int N, bool graph[101][101]) {

    // Base case:
    // If all N nodes have been colored
    if (node == N) {
        return true;
    }

    // Try every color from 1 to m
    for (int i = 1; i <= m; i++) {

        if (isSafe(node, color, graph, N, i)) {

            // Assign color
            color[node] = i;

            // Color the next node
            if (solve(node + 1, color, m, N, graph)) {
                return true;
            }

            // Backtracking
            color[node] = 0;
        }
    }

    return false;
}

bool graphColoring(bool graph[101][101], int m, int N) {

    int color[101] = {0};

    if (solve(0, color, m, N, graph)) {
        return true;
    }

    return false;
}

int main() {

    int N = 4;
    int m = 3;

    bool graph[101][101] = {0};

    graph[0][1] = 1;
    graph[1][0] = 1;

    graph[1][2] = 1;
    graph[2][1] = 1;

    graph[2][3] = 1;
    graph[3][2] = 1;

    graph[3][0] = 1;
    graph[0][3] = 1;

    graph[0][2] = 1;
    graph[2][0] = 1;

    if (graphColoring(graph, m, N)) {
        cout << "Graph can be colored with " << m << " colors";
    } else {
        cout << "Graph cannot be colored with " << m << " colors";
    }

    return 0;
}