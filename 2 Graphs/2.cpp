#include "../leetcode.h"

using Graph = vector<vector<pair<int, int>>>;

vector<int> dijkstra(const Graph &graph, int k)
{
    vector<int> distance(graph.size(), numeric_limits<int>::max());
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        queue;
    distance[k] = 0;
    queue.push({0, k});

    while (!queue.empty())
    {
        auto current = queue.top();
        queue.pop();

        int u = current.second;
        for (auto &edge : graph[u])
        {
            int v = edge.first, w = edge.second;
            if (distance[v] > distance[u] + w)
            {
                distance[v] = distance[u] + w;
                queue.push({distance[u] + w, v});
            }
        }
    }
    return distance;
}

int networkDelayTime(vector<vector<int>> &times, int n, int k)
{
    Graph graph(n);
    for (auto &edge : times)
        graph[edge[0] - 1].push_back({edge[1] - 1, edge[2]});

    vector<int> distance = dijkstra(graph, k - 1);
    int maximum = *max_element(distance.begin(), distance.end());
    if (maximum == numeric_limits<int>::max())
        return -1;
    else
        return maximum;
}

int main()
{
    vector<vector<int>> times;
    int n = 0, k = 0;
    cin >> times >> n >> k;
    cout << networkDelayTime(times, n, k) << endl;
    return 0;
}
