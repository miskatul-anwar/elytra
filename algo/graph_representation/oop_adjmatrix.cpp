#include <cstddef>
#include <iostream>
#include <vector>
using namespace std;
class Graph {
private:
  vector<vector<int>> graph;
  size_t vertices;

public:
  Graph(int vertices) {
    this->vertices = vertices;
    graph.resize(vertices, vector<int>(vertices, 0));
  }

  void add_edge(int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1; // Assuming undirected graph
  }

  void print_g() {
    for (auto row : this->graph) {
      for (auto col : row) {
        cout << col << " ";
      }
      cout << endl;
    }
  }

  size_t size() { return vertices; }
  vector<vector<int>> get_graph() { return graph; }
  bool has_edge(int u, int v) { return graph[u][v] == 1; }

  ~Graph() {

    for (size_t i = 0; i < vertices; ++i) {
      graph[i].clear();
    }

    graph.clear();
  }
};

int main(void) {
  Graph g(5);

  g.add_edge(0, 1);
  g.add_edge(1, 2);
  g.add_edge(2, 3);
  g.add_edge(3, 4);
  g.add_edge(4, 0);

  g.print_g();

  return 0;
}