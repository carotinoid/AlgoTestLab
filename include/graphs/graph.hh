#ifndef GRAPH_HH
#define GRAPH_HH

#include <exception>
#include <fstream>
#include <iostream>
#include <utility>
#include <vector>

class Graph {
  private:
    int _num_nodes{};
    int _num_edges{};
    std::vector<std::vector<std::pair<long long, long long>>> move;

  public:
    Graph(int node) : _num_nodes(node), _num_edges(0) { move.resize(node + 1); }
    Graph(std::string path);
    ~Graph(){};
    void add_edge(int u, int v, int w);
    void export_to(std::string path);
    std::vector<std::pair<long long, long long>> get_edges(int node) { return move[node]; }
    int get_num_nodes() const { return _num_nodes; }
    void describe(std::string name = "");
};

#endif  // GRAPH_HH