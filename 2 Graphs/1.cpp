#include "../leetcode.h"

using Graph = vector<vector<int>>;
using Path = vector<int>;

void allPathsSourceTarget(vector<Path> &paths, const Graph &graph,
                          Path &current)
{
    int u = current[current.size() - 1];
    for (int v : graph[u])
    {
        current.push_back(v);
        if (v == graph.size() - 1)
            paths.push_back(current);
        else
            allPathsSourceTarget(paths, graph, current);
        current.pop_back();
    }
}

vector<Path> allPathsSourceTarget(Graph &graph)
{
    vector<Path> paths;
    Path current{0};
    allPathsSourceTarget(paths, graph, current);
    return paths;
}

int main()
{
    Graph graph;
    cin >> graph;
    cout << allPathsSourceTarget(graph) << endl;
    return 0;
}
