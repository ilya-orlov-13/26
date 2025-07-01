#include "Header.h"

// ����������� GraphAdjacencyMatrix
GraphAdjacencyMatrix::GraphAdjacencyMatrix(int V) : NumVertices(V) {
    if (V <= 0) {
        throw invalid_argument("������������� ���������� ������");
    }
    AdjacencyMatrix = new bool* [NumVertices];
    for (int I = 0; I < NumVertices; ++I) {
        AdjacencyMatrix[I] = new bool[NumVertices];
        for (int J = 0; J < NumVertices; ++J) {
            AdjacencyMatrix[I][J] = false;
        }
    }
}

// ���������� GraphAdjacencyMatrix
GraphAdjacencyMatrix::~GraphAdjacencyMatrix() {
    for (int I = 0; I < NumVertices; ++I) {
        delete[] AdjacencyMatrix[I];
    }
    delete[] AdjacencyMatrix;
    AdjacencyMatrix = nullptr;
}

// ����� AddEdge
void GraphAdjacencyMatrix::AddEdge(int U, int V) {
    if (U < 0 || U >= NumVertices || V < 0 || V >= NumVertices) {
        throw out_of_range("������ ������� ������� �� ������� ���������");
    }
    AdjacencyMatrix[U][V] = true;
    AdjacencyMatrix[V][U] = true; // ��� ������������������ �����
}

// ����� IsEdge
bool GraphAdjacencyMatrix::IsEdge(int U, int V) const {
    if (U < 0 || U >= NumVertices || V < 0 || V >= NumVertices) {
        throw out_of_range("������ ������� ������� �� ������� ���������");
    }
    return AdjacencyMatrix[U][V];
}

// ����� CalculateDegrees
vector<int> GraphAdjacencyMatrix::CalculateDegrees() const {
    vector<int> DegreesVector(NumVertices, 0);

    for (int I = 0; I < NumVertices; ++I) {
        for (int J = 0; J < NumVertices; ++J) {
            if (AdjacencyMatrix[I][J]) {
                DegreesVector[I]++;
                if(I==J) DegreesVector[I]++;
            }
        }
    }
    return DegreesVector;
}

// ����� PrintAdjacencyMatrix
void GraphAdjacencyMatrix::PrintAdjacencyMatrix() const {
    cout << "  ";
    for (int J = 0; J < NumVertices; ++J) {
        cout << J << " ";
    }
    cout << endl;
    for (int I = 0; I < NumVertices; ++I) {
        cout << I << ":";
        for (int J = 0; J < NumVertices; ++J) {
            cout << (AdjacencyMatrix[I][J] ? 1 : 0) << " ";
        }
        cout << endl;
    }
}


// Graf1
void SolveGraf1Task() {
    string FileName;
	cout << "������� ��� �����: ";
	cin >> FileName;
    ifstream Fin(FileName);

    if (!Fin.is_open()) {
        cerr << "������: �� ������� ������� ���� '" << FileName << "'" << endl;
        return;
    }

    int NumVerticesFromFile;
    if (!(Fin >> NumVerticesFromFile)) {
        cerr << "������: �� ������� ��������� ���������� ������" << endl;
        Fin.close();
        return;
    }
    if (NumVerticesFromFile <= 0) {
        cerr << "������: ������������� ���������� ������" << endl;
        Fin.close();
        return;
    }

    GraphAdjacencyMatrix* GraphInstance = nullptr;
    try {
        GraphInstance = new GraphAdjacencyMatrix(NumVerticesFromFile);

        for (int I = 0; I < NumVerticesFromFile; ++I) {
            for (int J = 0; J < NumVerticesFromFile; ++J) {
                int EdgeExists;
                if (!(Fin >> EdgeExists)) {
                    cerr << "������: �������� ������� ���������" << endl;
                    delete GraphInstance;
                    Fin.close();
                    return;
                }
                if (EdgeExists == 1) {
                    GraphInstance->AddEdge(I, J);
                }
                else if (EdgeExists != 0) {
                    cerr << "������: ������� ��������� �������� ���������� ��������" << endl;
                    delete GraphInstance;
                    Fin.close();
                    return;
                }
            }
        }


    }
    catch (const exception& E) {
        cerr << "������ ��� �������� ��� ������ �����: " << E.what() << endl;
        delete GraphInstance;
        Fin.close();
        return;
    }
    Fin.close();

    vector<int> DegreesVector;
    try {
        DegreesVector = GraphInstance->CalculateDegrees();
    }
    catch (const exception& E) {
        cerr << "������ ��� ���������� �������: " << E.what() << endl;
        delete GraphInstance;
        return;
    }

    cout << "������� ������:" << endl;
    for (int I = 0; I < NumVerticesFromFile; ++I) {
        cout << I+1 << ": " << DegreesVector[I] << endl;
    }

    delete GraphInstance;
}