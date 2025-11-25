#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int C(int x) {
    return x * x * x;
}

struct E {
    int a, b;
};

int main() {
    int tc = 1, n;
    while (cin >> n) {
        vector<int> w(n + 1);
        for (int i = 1; i <= n; i++) cin >> w[i];

        int r;
        cin >> r;
        vector<E> ed(r);
        for (int i = 0; i < r; i++) cin >> ed[i].a >> ed[i].b;

        int q;
        cin >> q;
        vector<int> ask(q);
        for (int i = 0; i < q; i++) cin >> ask[i];

        vector<int> d(n + 1, INT_MAX);
        d[1] = 0;

        for (int i = 1; i < n; i++) {
            for (auto &e : ed) {
                int u = e.a, v = e.b;
                int cost = C(w[v] - w[u]);
                if (d[u] != INT_MAX && d[u] + cost < d[v]) {
                    d[v] = d[u] + cost;
                }
            }
        }

        cout << "Set #" << tc++ << "\n";
        for (int t : ask) {
            if (t < 1 || t > n || d[t] == INT_MAX || d[t] < 3) {
                cout << "?\n";
            } else {
                cout << d[t] << "\n";
            }
        }
    }
    return 0;
}
