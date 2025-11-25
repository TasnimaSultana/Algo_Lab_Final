#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct W {
    int a, b, t;
};

int runBF(int n, const vector<W>& ed) {
    vector<ll> d(n, (ll)1e18);
    d[0] = 0;

    for (int i = 0; i < n - 1; i++) {
        bool pushed = false;
        for (auto &e : ed) {
            if (d[e.a] < (ll)1e18 && d[e.a] + e.t < d[e.b]) {
                d[e.b] = d[e.a] + e.t;
                pushed = true;
            }
        }
        if (!pushed) break;
    }

    for (auto &e : ed) {
        if (d[e.a] < (ll)1e18 && d[e.a] + e.t < d[e.b]) return 1;
    }
    return 0;
}

void go() {
    int n, m;
    cin >> n >> m;

    vector<W> ed(m);
    for (int i = 0; i < m; i++) cin >> ed[i].a >> ed[i].b >> ed[i].t;

    int cyc = runBF(n, ed);
    cout << (cyc ? "possible\n" : "not possible\n");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int c;
    cin >> c;
    while (c--) go();
}

