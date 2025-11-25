#include <bits/stdc++.h>
using namespace std;

const long long LIM = 1e18;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int,int>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }

    vector<long long> dist(n + 1, LIM);
    vector<int> prv(n + 1, -1);

    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;

    dist[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();

        long long d = cur.first;
        int u = cur.second;

        if (d != dist[u]) continue;

        for (auto &nx : adj[u]) {
            int v = nx.first;
            int w = nx.second;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                prv[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    if (dist[n] == LIM) {
        cout << -1 << "\n";
        return 0;
    }

    vector<int> path;
    for (int v = n; v != -1; v = prv[v]) path.push_back(v);
    reverse(path.begin(), path.end());

    for (int v : path) cout << v << " ";
    cout << "\n";

    return 0;
}
