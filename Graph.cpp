#include "Graph.h"
#include <fstream>
#include <iostream>
#include <sstream>

Graph::Graph() {
	vertices_ = std::vector<int>();
	adj_matrix_ = std::vector<std::vector<bool>>();
}

void Graph::add_vertex(int value) {
	vertices_.push_back(value);
	int newSize = vertices_.size();
	for (auto& row : adj_matrix_) {
		row.push_back(false);
	}
	adj_matrix_.emplace_back(newSize, false);
}

void Graph::remove_vertex(int vertexId) {
	adj_matrix_.erase(adj_matrix_.begin() + static_cast<std::ptrdiff_t>(vertexId));
	for (auto& row : adj_matrix_) {
		row.erase(row.begin() + static_cast<std::ptrdiff_t>(vertexId));
	}
}

void Graph::connect_vertex(int vertexId1, int vertexId2) {
	adj_matrix_[vertexId1][vertexId2] = true;
	adj_matrix_[vertexId2][vertexId1] = true;
}

void Graph::disconnect_vertex(int vertexId1, int vertexId2 ) {
	adj_matrix_[vertexId1][vertexId2] = false;
	adj_matrix_[vertexId2][vertexId1] = false;
}

void Graph::save_to_file(std::string filename) {
	std::ofstream fout(filename);
	int size = vertices_.size();
	for (auto elem : vertices_) {
		fout << elem << " ";
	}
	fout << std::endl;
	for (auto& row : adj_matrix_) {
		for (auto elem : row) {
			fout << elem << " ";
		}
		fout << std::endl;
	}
}

void Graph::load_from_file(std::string filename) {
	std::ifstream fin(filename);
	int vertexValue = 0;
	std::string line;
	std::getline(fin, line);
	std::istringstream iss(line);
	while (iss >> vertexValue) {
		vertices_.push_back(vertexValue);
	}

	int size = vertices_.size();
	adj_matrix_.assign(size, std::vector<bool>(size, false));
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			int cell = 0;
			fin >> cell;
			adj_matrix_[i][j] = cell;
		}
	}
}

std::ostream& operator<<(std::ostream& os, const Graph& g) {
	os << "Вершины: ";
	for (int v : g.vertices_) {
		os << v << " ";
	}
	os << std::endl;
	os << std::endl;
	os << "Матрица смежности: " << std::endl;
	int size = g.vertices_.size();
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			os << g.adj_matrix_[i][j] << " ";
		}
		os << std::endl;
	}
	return os;
}

void Graph::clear() {
	vertices_.clear();
	adj_matrix_.clear();
}

Graph::~Graph() {
	clear();
	std::cout << "Граф очищен из памяти." << std::endl;
}
