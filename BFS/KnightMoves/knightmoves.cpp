#include <bits/stdc++.h>
using namespace std;

int kr[] = {2,2,-2,-2,1,1,-1,-1};
int kc[] = {1,-1,1,-1,2,-2,2,-2};

int solve(int r1, int c1, int r2, int c2) {
    int d[8][8];
    memset(d, -1, sizeof(d));

    queue<pair<int,int>> q;
    d[r1][c1] = 0;
    q.push({r1, c1});

    while (!q.empty()) {
        auto p = q.front();
        q.pop();

        if (p.first == r2 && p.second == c2) return d[p.first][p.second];

        for (int i = 0; i < 8; i++) {
            int nr = p.first + kr[i];
            int nc = p.second + kc[i];

            if (nr >= 0 && nr < 8 && nc >= 0 && nc < 8 && d[nr][nc] == -1) {
                d[nr][nc] = d[p.first][p.second] + 1;
                q.push({nr, nc});
            }
        }
    }
    return -1;
}

int main() {
    string s, t;

    while (cin >> s >> t) {
        int r1 = s[1] - '1';
        int c1 = s[0] - 'a';
        int r2 = t[1] - '1';
        int c2 = t[0] - 'a';

        int ans = solve(r1, c1, r2, c2);

        cout << "To get from " << s << " to " << t
             << " takes " << ans << " knight moves.\n";
    }
}
