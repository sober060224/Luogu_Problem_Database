#include <bits/stdc++.h>
using namespace std;
#define ll long long

void showve(vector<int> &a)
{
   for (int i = 1; i < a.size(); i++)
       cout << a[i] << ' ';
   cout << endl;
}

void solve(vector<int> &a)
{
    int n = a.size() - 1, l, r;
    // 找第一个a[i] < a[i + 1]，保证移动最小前缀
    for (int i = n - 1; i > 0; i--)
    {
        if (a[i] < a[i + 1])
        {
            l = i;
            break;
        }
    }

    // 找到第一个a[i] > a[l]，保证最小后缀
    for (int i = n; i > 0; i--)
    {
        if (a[i] > a[l])
        {
            r = i;
            break;
        }
    }

    swap(a[l], a[r]);
    reverse(a.begin() + l + 1, a.end());
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        solve(a);
    showve(a);

    return 0;
}