#include "../leetcode.h"

int minCostConnectPoints(vector<vector<int>> &points)
{
    int weight = 0, count = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        queue;
    vector<bool> connected(points.size());
    queue.push({0, 0});

    while (count < points.size())
    {
        auto current = queue.top();
        queue.pop();

        int u = current.second;
        if (!connected[u])
        {
            connected[u] = true;
            weight += current.first;
            for (int v = 0; v < points.size(); ++v)
                if (!connected[v])
                {
                    auto &p = points[u], &q = points[v];
                    int distance = abs(p[0] - q[0]) + abs(p[1] - q[1]);
                    queue.push({distance, v});
                }
            ++count;
        }
    }
    return weight;
}

int main()
{
    vector<vector<int>> points;
    cin >> points;
    cout << minCostConnectPoints(points) << endl;
    return 0;
}
