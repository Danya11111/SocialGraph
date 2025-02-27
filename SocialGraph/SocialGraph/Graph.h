#pragma once
#include <vector>
#include <string>
using namespace std;

class Graph {
public:

    void addEdge(string st1, string st2);
    void addVertex(int vnumber);
    void print(int** matrix_v);
    void findMinDistancesFloyd();
private:
    bool edgeExists(int v1, int v2);

    vector<vector<int>> matrix; // матрица смежности
    int size_matrix;
    vector<string> vname;
    vector<int> vertexes;
};