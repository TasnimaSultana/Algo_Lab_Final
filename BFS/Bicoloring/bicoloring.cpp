#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n;
    while (cin >> n && n != 0) {
        int m;
        cin >> m;

        vector<vector<int>> adj(n);
        vector<int> col(n, -1);

        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        queue<int> q;
        bool ok = true;

        col[0] = 0;
        q.push(0);

        while (!q.empty() && ok) {
            int x = q.front();
            q.pop();

            for (int y : adj[x]) {
                if (col[y] == -1) {
                    col[y] = 1 - col[x];
                    q.push(y);
                } else if (col[y] == col[x]) {
                    ok = false;
                    break;
                }
            }
        }

        cout << (ok ? "BICOLORABLE." : "NOT BICOLORABLE.") << "\n";
    }
    return 0;
}
