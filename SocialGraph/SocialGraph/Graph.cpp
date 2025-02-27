#include "Graph.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ���������� �����
void Graph::addEdge(string st1, string st2)
{
    int v1 = -1;
    int v2 = -1;
    for (int i = 0; i < vname.size(); i++) {
        if (vname[i] == st1)
            v1 = i;
        if (vname[i] == st2)
            v2 = i;
    }
    if (v1 == -1) {
        vname.push_back(st1);
        v1 = vname.size() - 1;
        addVertex(v1);
    }
    if (v2 == -1) {
        vname.push_back(st2);
        v2 = vname.size() - 1;
        addVertex(v2);
    }

    matrix[v1][v2] = 1;
    matrix[v2][v1] = 1;
}
// ���������� �������
void Graph::addVertex(int value) {
    vertexes.push_back(value);
    size_matrix++;
    vector<vector<int>> newMatrix(size_matrix, vector<int>(size_matrix, 0));
    for (int i = 0; i < size_matrix - 1; i++) {
        for (int j = 0; j < size_matrix - 1; j++) {
            newMatrix[i][j] = matrix[i][j];
        }
    }
    matrix = newMatrix;
}

//������ ���������
void Graph::print(int** matrix_v) {
    cout << endl;
    for (int i = 0; i < size_matrix; i++) {
        cout << vname[i] << " know: ";
        int f = 0;
        for (int j = 0; j < size_matrix; j++) {
            if (matrix_v[i][j] != 0 && matrix_v[i][j] < 4) {
                if (f > 0)
                    cout << ", ";
                cout << vname[j];
            }
        }
        cout << "." << endl;
    }
}

//�������� ������-�������� (���������� � ������)
#define VERYBIGINT 1000000000
void Graph::findMinDistancesFloyd()
{
    // ������� �����
    int** weights = new int*[size_matrix];
    for (int i = 0; i < size_matrix; i++) {
        weights[i] = new int[size_matrix];
    }
    // ������������ �������
    for (int i = 0; i < size_matrix; i++)
    {
        for (int j = 0; j < size_matrix; j++)
        {
            if (i == j)
            {
                weights[i][j] = 0; // ���� �� ����� ���� ����� 0
            }
            else {
                if (!edgeExists(i, j))
                {
                    weights[i][j] = VERYBIGINT; // ���� ����� ���
                }
                else {
                    weights[i][j] = matrix[i][j]; // ���� ����� ����
                }
            }
        }
    }

    for (int k = 0; k < vertexes.size(); k++) // �������� �� k
    {
        int ck = vertexes[k]; // ������� ����� �������
        for (int i = 0; i < vertexes.size(); i++)
        {
            if (i == k)
                continue;
            int ci = vertexes[i];
            for (int j = 0; j < vertexes.size(); j++)
            {
                if (j == k)
                    continue;
                int cj = vertexes[j];
                if (weights[ci][ck] + weights[ck][cj] < weights[ci][cj]) {
                    // �������� �������� �����
                    weights[ci][cj] = weights[ci][ck] + weights[ck][cj];
                }
            }
        }
    }
    print(weights);
}

bool Graph::edgeExists(int v1, int v2)
{
    return matrix[v1][v2] > 0;
}
