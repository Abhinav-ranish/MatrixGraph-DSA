#include "MatrixGraph_ranish.h"
#include "MatrixGraph_ranish.cpp"
#include <iostream>
#include <iomanip>
#include <fstream>

int main() {
    int numVertices;
    bool directed;
    std::cout << "Enter the number of vertices: ";
    std::cin >> numVertices;
    std::cout << "Is the graph directed? (1 for yes, 0 for no): ";
    std::cin >> directed;

    MatrixGraph graph(numVertices, directed);
    int choice;
    std::string filename;

    do {
        std::cout << "Welcome to the Graph tester!" << std::endl;
        std::cout << "1) Print the graph" << std::endl;
        std::cout << "2) Find a path" << std::endl;
        std::cout << "3) Start a file" << std::endl;
        std::cout << "4) Add a path to the file" << std::endl;
        std::cout << "0) Quit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::cout << "Graph:" << std::endl;
                std::cout << graph.toString() << std::endl;
                break;
            }
            case 2: {
                int source, destination;
                std::cout << "Enter the source vertex: ";
                std::cin >> source;
                std::cout << "Enter the destination vertex: ";
                std::cin >> destination;

                if (graph.pathExists(source, destination)) {
                    std::cout << "Path from " << std::setw(2) << source << " to " << std::setw(2) << destination << " is:" << std::endl;
                    std::vector<int> path = graph.getBFSPath(source, destination);
                    for (int i = 0; i < path.size(); ++i) {
                        int vertex = path[i];
                        std::cout << "[" << std::setw(2) << vertex << ": " << std::fixed << std::setprecision(2) << graph.getEdgeWeight(vertex, destination) << "]==> ";
                    }
                    std::cout << std::endl;
                } else {
                    std::cout << "No path from " << source << " to " << destination << "." << std::endl;
                }
                break;
            }
            case 3: {
                std::cout << "Enter the filename to start: ";
                std::cin >> filename;
                std::ofstream file(filename);
                if (file.is_open()) {
                    file << graph.toString();
                    file.close();
                    std::cout << "Graph has been written to " << filename << "." << std::endl;
                } else {
                    std::cout << "Unable to open file." << std::endl;
                }
                break;
            }
            case 4: {
                if (filename.empty()) {
                    std::cout << "No file has been created yet." << std::endl;
                } else {
                    int source, destination;
                    std::cout << "Enter source vertex: ";
                    std::cin >> source;
                    std::cout << "Enter destination vertex: ";
                    std::cin >> destination;
                    std::ofstream file(filename, std::ios::app);
                    if (file.is_open()) {
                        if (graph.pathExists(source, destination)) {
                            std::vector<int> path = graph.getBFSPath(source, destination);
                            file << "Path from " << source << " to " << destination << " is:" << std::endl;
                            for (int i = 0; i < path.size(); ++i) {
                                int vertex = path[i];
                                file << "[" << std::setw(2) << vertex << ": " << std::fixed << std::setprecision(2) << graph.getEdgeWeight(vertex, destination) << "]==> ";
                            }
                            file << std::endl;
                        } else {
                            file << "No path from " << source << " to " << destination << "." << std::endl;
                        }
                        file.close();
                        std::cout << "Path has been added to " << filename << "." << std::endl;
                    } else {
                        std::cout << "Unable to open file." << std::endl;
                    }
                }
                break;
            }
            case 0: {
                std::cout << "Exiting program." << std::endl;
                break;
            }
            default: {
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
            }
        }
    } while (choice != 0);

    return 0;
}
