#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/breadth_first_search.hpp>
#include <iostream>
#include <vector>

using namespace boost;

typedef adjacency_list<vecS, vecS, undirectedS> Graph;

void run_bfs(const Graph& g, int start) {
    auto vis = make_bfs_visitor(null_visitor());
    breadth_first_search(g, vertex(start, g), visitor(vis));
}

Graph make_graph(const std::vector<std::pair<int, int>>& edges, int nodes) {
    Graph g(nodes);
    for (auto& [u, v] : edges) {
        add_edge(u, v, g);
    }
    return g;
}

int main() {
    std::vector<std::vector<std::pair<int, int>>> all_edges = {
        { {0,1}, {0,2}, {1,3}, {2,4}, {4,5} },                                  // 5 edges
        { {0,1}, {0,2}, {1,3}, {2,4}, {4,5}, {1,2}, {3,5} },                    // 7 edges
        { {0,1}, {0,2}, {1,3}, {2,4}, {4,5}, {1,2}, {3,5}, {3,4}, {0,5} }       // 9 edges
    };

    for (const auto& edges : all_edges) {
        Graph g = make_graph(edges, 6);
        run_bfs(g, 0);
    }

    return 0;
}
