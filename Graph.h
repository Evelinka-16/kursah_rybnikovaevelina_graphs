#pragma once
#include <vector>
#include <iostream>

class Graph {
public:
    void add_vertex(int value);
    void connect_vertex(int vertexId1, int vertexId2);
    void disconnect_vertex(int vertexId1, int vertexId2);
    void remove_vertex(int vertexId);

    void save_to_file(std::string filename);
    void load_from_file(std::string filename);

    void clear();

    friend std::ostream& operator<<(std::ostream& os, const Graph& g);
private:
    std::vector<int> vertices_;
    std::vector<std::vector<bool>> adj_matrix_;
};