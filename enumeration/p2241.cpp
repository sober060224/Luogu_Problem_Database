#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MN = 1001;

void show(vector<int> &a)
{
    for (int i = 1; i < a.size(); i++)
        cout << a[i] << ' ';
    cout << endl;
}

void solve()
{
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n, m;
    cin >> n >> m;

    ll squre = 0;
    for (int i = 1; i <= min(n, m); i++)
        squre += (n - i + 1) * (m - i + 1);

    ll rectangle = 0;
    // 垂直方向，
    for (int i = 1; i <= n; i++)
    {
        // 水平方向
        for (int j = 1; j <= m; j++)
        {
            if (i == j)
                continue;

            rectangle += (n - i + 1) * (m - j + 1);
        }
    }

    cout << squre << ' ' << rectangle;

    return 0;
}