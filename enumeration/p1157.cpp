#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MN = 1001;

void showve(vector<int> &a)
{
    for (int i = 1; i < a.size(); i++)
        cout << setw(3) << a[i];
    cout << endl;
}

void solve(vector<int> &perm, int index, int n, int cur)
{
    int r = perm.size() - 1;

    if (index > r)
    {
        showve(perm);
        return;
    }

    // 要选 可选
    if (r - index > n - cur + 1)
        return;

    for (int i = cur; i <= n; i++)
    {
        perm[index] = i;
        solve(perm, index + 1, n, i + 1);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n, r;
    cin >> n >> r;
    vector<int> perm(r + 1);

    solve(perm, 1, n, 1);

    return 0;
}