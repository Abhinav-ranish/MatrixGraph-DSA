
#ifndef MATRIXGRAPH_H
#define MATRIXGRAPH_H

#include <iostream>
#include <vector>
#include <stdexcept>

class MatrixGraph {
private:
    std::vector<std::vector<float> > matrix;
    int numVertices;
    bool directed;

public:
    MatrixGraph(int numVertices, bool directed);
    void addEdge(int source, int destination);
    void addEdge(int source, int destination, float weight);
    void removeEdge(int source, int destination);
    bool adjacent(int source, int destination);
    float getEdgeWeight(int source, int destination);
    void setEdgeWeight(int source, int destination, float weight);
    std::string toString();
    void printRaw();
    bool pathExists(int source, int destination);
    std::vector<int> getBFSPath(int source, int destination);
};

#endif // MATRIXGRAPH_H
