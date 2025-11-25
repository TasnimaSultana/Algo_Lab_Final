#include <bits/stdc++.h>
using namespace std;

const int BIG = 1000000007;

struct E {
    int v, w;
};

int runCase() {
    int n, r;
    if (!(cin >> n >> r)) return -1;

    vector<vector<E>> g(n + 1);
    for (int i = 0; i < r; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        g[a].push_back({b, w});
        g[b].push_back({a, w});
    }

    vector<int> best(n + 1, BIG), secondBest(n + 1, BIG);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    best[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();

        int d = cur.first;
        int u = cur.second;

        if (d > secondBest[u]) continue;

        for (auto &e : g[u]) {
            int v = e.v;
            int cost = d + e.w;

            if (cost < best[v]) {
                secondBest[v] = best[v];
                best[v] = cost;
                pq.push({best[v], v});
                if (secondBest[v] < BIG) pq.push({secondBest[v], v});
            } else if (cost > best[v] && cost < secondBest[v]) {
                secondBest[v] = cost;
                pq.push({secondBest[v], v});
            }
        }
    }

    return secondBest[n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 1; i <= t; i++) {
        int ans = runCase();
        if (ans != -1) {
            cout << "Case " << i << ": " << ans << "\n";
        }
    }
}
