#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int id = 1;

    while (true) {
        vector<vector<int>> adj(21);
        int c;

        if (!(cin >> c)) return 0;

        for (int i = 1; i <= 19; i++) {
            if (i != 1) cin >> c;
            for (int k = 0; k < c; k++) {
                int to;
                cin >> to;
                adj[i].push_back(to);
                adj[to].push_back(i);
            }
        }

        int qn;
        cin >> qn;

        cout << "Test Set #" << id++ << "\n";

        while (qn--) {
            int s, t;
            cin >> s >> t;

            vector<int> d(21, -1);
            queue<int> q;
            d[s] = 0;
            q.push(s);

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int w : adj[u]) {
                    if (d[w] == -1) {
                        d[w] = d[u] + 1;
                        q.push(w);
                    }
                }
            }

            cout << setw(2) << s << " to "
                 << setw(2) << t << ": "
                 << d[t] << "\n";
        }

        cout << "\n";
    }
}
