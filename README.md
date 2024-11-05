# MatrixGraph Library

## Overview

The **MatrixGraph** library provides a simple and flexible implementation of a graph structure using an adjacency matrix. It supports both directed and undirected graphs and includes functionality for adding, removing, and updating edges with optional weights. Additionally, it includes methods for finding paths between vertices using Breadth-First Search (BFS) and offers a queue-based implementation to support BFS traversal.

## Features

- **Graph Creation**: Initialize a graph with a specified number of vertices and choose if it is directed or undirected.
- **Edge Manipulation**: Add, remove, and update edges with optional weights.
- **Pathfinding**: Check if a path exists between two vertices and retrieve paths using BFS.
- **File Export**: Save the graph structure or specific paths to a file for easy export and analysis.

## File Structure

- `MatrixGraph_ranish.h`: Header file for the `MatrixGraph` class.
- `Queue_ranish.hpp`: Header file containing the `Queue` class for BFS traversal.
- `main.cpp`: Contains the main function for testing and interacting with the `MatrixGraph` library.

## Class Descriptions

### `MatrixGraph`

The `MatrixGraph` class provides the main functionality of the graph. Key methods include:

- **Constructor**: Initializes the graph with a specified number of vertices and directed/undirected configuration.
- **addEdge**: Adds an edge between two vertices, optionally with a weight.
- **removeEdge**: Removes an edge between two vertices.
- **adjacent**: Checks if there is a direct edge between two vertices.
- **getEdgeWeight**: Retrieves the weight of an edge between two vertices.
- **setEdgeWeight**: Sets a new weight for an existing edge.
- **toString**: Returns a string representation of the adjacency matrix.
- **printRaw**: Prints the raw adjacency matrix to the console.
- **pathExists**: Checks if a path exists between two vertices.
- **getBFSPath**: Uses BFS to find a path between two vertices and returns the path as a vector of integers.

### `Queue`

The `Queue` class is a basic implementation of a queue using linked nodes. This queue is utilized in the `getBFSPath` method of the `MatrixGraph` class.

Key methods include:

- **enqueue**: Adds an element to the rear of the queue.
- **dequeue**: Removes the front element from the queue.
- **getFront**: Returns the front element of the queue without removing it.
- **isEmpty**: Checks if the queue is empty.

## Usage

### Building and Running

To build and run the program, use a C++ compiler:

```bash
g++ main.cpp -o graph_program
./graph_program
```

### User Interaction

When running the program, users can interact with the graph through the following options:

1. **Print the Graph**: Displays the adjacency matrix representation.
2. **Find a Path**: Checks if a path exists between two specified vertices and outputs the path if it exists.
3. **Start a File**: Saves the current state of the graph to a specified file.
4. **Add a Path to the File**: Appends a path (if one exists) between two vertices to the existing file.
5. **Quit**: Exits the program.

### Example Code

```cpp
MatrixGraph graph(5, false);  // Create an undirected graph with 5 vertices.
graph.addEdge(0, 1, 2.5);     // Add a weighted edge between vertex 0 and 1.
graph.addEdge(1, 2);          // Add an unweighted edge between vertex 1 and 2.

std::cout << graph.toString(); // Print the adjacency matrix.
```

### Dependencies

This project depends on standard C++ libraries only. It does not require any external libraries.

### Future Work

- Implement advanced pathfinding algorithms like Dijkstra's or A* for weighted graphs.
- Add functionality for importing graphs from files.
- Add support for other graph representations, such as adjacency lists.

## License

This project is licensed under the MIT License.
