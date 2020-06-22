#include <iostream>
#include <limits.h>
#include <list>

class Graph {
  int V;
  std::list<int> *adj;

public:
  bool isCyclicUtil(int v, bool visited[], bool *rs);
  Graph(int V);
  void addEdge(int v, int w);
  bool isCyclic();
};
Graph::Graph(int V) {
  this->V = V;
  adj = new std::list<int>[V];
}
void Graph::addEdge(int v, int w) { adj[v].push_back(w); }

bool Graph::isCyclicUtil(int v, bool visited[], bool *recStack) {
  if (visited[v] == false) {
    visited[v] = true;
    recStack[v] = true;
    std::list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i) {
      if (!visited[*i] && isCyclicUtil(*i, visited, recStack))
        return true;
      else if (recStack[*i])
        return true;
    }
  }
  recStack[v] = false;
  return false;
}

bool Graph::isCyclic() {
  bool *visited = new bool[V];
  bool *recStack = new bool[V];
  for (int i = 0; i < V; i++) {
    visited[i] = false;
    recStack[i] = false;
  }
  for (int i = 0; i < V; i++)
    if (isCyclicUtil(i, visited, recStack))
      return true;
  return false;
}

int main() {
  int m, n;
  std::cin >> m >> n;
  Graph g(m);
  while (n--) {
    int src, dst;
    std::cin >> src >> dst;
    g.addEdge(src, dst);
  }
  if (g.isCyclic())
    std::cout << "Graph contains cycle\n";
  else
    std::cout << "Graph doesn't contain cycle\n";
  return 0;
}
