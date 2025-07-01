#pragma once
#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <stdexcept>

using namespace std;

// ����� ��� ������������� ������������������ ����� �������� ���������
class GraphAdjacencyMatrix {
private:
    bool** AdjacencyMatrix; // ������� ���������
    int NumVertices;        // ���������� ������

public:
    // �����������: ������� ���� � V ���������
    GraphAdjacencyMatrix(int V);

    // ����������: ����������� ������ ������� ���������
    ~GraphAdjacencyMatrix();

    // ��������� ����� ����� ��������� U � V
    void AddEdge(int U, int V);

    // ��������� ������� ����� ����� U � V
    bool IsEdge(int U, int V) const;

    // ��������� ������� ������ �������
    vector<int> CalculateDegrees() const;

    // ������� ������� ���������
    void PrintAdjacencyMatrix() const;
};

// Graf1
void SolveGraf1Task();

#endif // HEADER_H