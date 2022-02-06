#include "../leetcode.h"

using Graph = vector<vector<pair<int, int>>>;

vector<int> shortestPaths(const Graph &graph, int src, int k)
{
    vector<int> distance(graph.size(), numeric_limits<int>::max());
    distance[src] = 0;

    for (int i = 0; i < k; ++i)
    {
        vector<int> current = distance;
        for (int u = 0; u < graph.size(); ++u)
            for (auto &edge : graph[u])
            {
                int v = edge.first, w = edge.second;
                if (distance[u] != numeric_limits<int>::max())
                    current[v] = min(current[v], distance[u] + w);
            }
        distance = current;
    }
    return distance;
}

int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst,
                      int k)
{
    Graph graph(n);
    for (auto &edge : flights)
        graph[edge[0]].push_back({edge[1], edge[2]});

    vector<int> distance = shortestPaths(graph, src, k + 1);
    if (distance[dst] == numeric_limits<int>::max())
        return -1;
    else
        return distance[dst];
}

int main()
{
    int n = 0, src = 0, dst = 0, k = 0;
    vector<vector<int>> flights;
    cin >> n >> flights >> src >> dst >> k;
    cout << findCheapestPrice(n, flights, src, dst, k) << endl;
    return 0;
}
