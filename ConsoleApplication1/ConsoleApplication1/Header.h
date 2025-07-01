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

// Класс для представления неориентированного графа матрицей смежности
class GraphAdjacencyMatrix {
private:
    bool** AdjacencyMatrix; // Матрица смежности
    int NumVertices;        // Количество вершин

public:
    // Конструктор: создает граф с V вершинами
    GraphAdjacencyMatrix(int V);

    // Деструктор: освобождает память матрицы смежности
    ~GraphAdjacencyMatrix();

    // Добавляет ребро между вершинами U и V
    void AddEdge(int U, int V);

    // Проверяет наличие ребра между U и V
    bool IsEdge(int U, int V) const;

    // Вычисляет степень каждой вершины
    vector<int> CalculateDegrees() const;

    // Выводит матрицу смежности
    void PrintAdjacencyMatrix() const;
};

// Graf1
void SolveGraf1Task();

#endif // HEADER_H