#include "MatrixGraph_ranish.h"
#include "Queue_ranish.hpp" 
#include <iostream>
#include <iomanip>
#include <fstream>


MatrixGraph::MatrixGraph(int numVertices, bool directed) : numVertices(numVertices), directed(directed) {
    matrix.resize(numVertices, std::vector<float>(numVertices, 0.0));
}

void MatrixGraph::addEdge(int source, int destination) {
    matrix[source][destination] = 1.0; 
    if (!directed)
        matrix[destination][source] = 1.0; 
}

void MatrixGraph::addEdge(int source, int destination, float weight) {
    matrix[source][destination] = weight;
    if (!directed)
        matrix[destination][source] = weight;
}

void MatrixGraph::removeEdge(int source, int destination) {
    matrix[source][destination] = 0.0;
    if (!directed)
        matrix[destination][source] = 0.0;
}

bool MatrixGraph::adjacent(int source, int destination) {
    return matrix[source][destination] != 0.0;
}

float MatrixGraph::getEdgeWeight(int source, int destination) {
    if (matrix[source][destination] == 0.0)
        throw std::runtime_error("Edge doesn't exist");
    return matrix[source][destination];
}

void MatrixGraph::setEdgeWeight(int source, int destination, float weight) {
    if (matrix[source][destination] == 0.0)
        throw std::runtime_error("Edge doesn't exist");
    matrix[source][destination] = weight;
    if (!directed)
        matrix[destination][source] = weight;
}

std::string MatrixGraph::toString() {
    std::string result;
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            result += std::to_string(matrix[i][j]) + " ";
        }
        result += "\n";
    }
    return result;
}

void MatrixGraph::printRaw() {
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

bool MatrixGraph::pathExists(int source, int destination) {
    // Implement your pathfinding algorithm here
    // This could be DFS, BFS, Dijkstra's, etc.
    // For now, returning true if there's a direct edge
    return matrix[source][destination] != 0.0;
}


std::vector<int> MatrixGraph::getBFSPath(int source, int destination) {
    std::vector<int> path;
    if (source == destination) {
        path.push_back(source);
        return path;
    }

    std::vector<bool> visited(numVertices, false);
    std::vector<int> predecessor(numVertices, -1);
    Queue<int> queue;

    visited[source] = true;
    queue.enqueue(source);

    while (!queue.isEmpty()) {
        int currentVertex = queue.getFront(); 
        queue.dequeue();

        for (int i = 0; i < numVertices; ++i) {
            if (matrix[currentVertex][i] != 0 && !visited[i]) {
                visited[i] = true;
                predecessor[i] = currentVertex;
                queue.enqueue(i);

                if (i == destination) {
                    // Reconstruct path
                    int pred = i;
                    while (pred != -1) {
                        path.insert(path.begin(), pred);
                        pred = predecessor[pred];
                    }
                    return path;
                }
            }
        }
    }

    // No path found
    return path;
}


