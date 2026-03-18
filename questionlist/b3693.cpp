#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

vector<vector<ull>> ar(1010, vector<ull>(1010)); // 或动态分配

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, m, q;
        cin >> n >> m >> q;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                ull t;
                cin >> t;
                ar[i][j] = ar[i-1][j] + ar[i][j-1] - ar[i-1][j-1] + t; // 自然溢出模 2^64
            }
        }
        ull ans = 0;
        while (q--) {
            int u, v, x, y;
            cin >> u >> v >> x >> y;
            ull t = ar[x][y] - ar[u-1][y] - ar[x][v-1] + ar[u-1][v-1];
            ans ^= t;
        }
        cout << ans << '\n';
    }
    return 0;
}