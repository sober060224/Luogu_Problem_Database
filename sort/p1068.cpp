#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1001;

void showus(unordered_set<int> &us)
{
    for (int i : us)
        cout << i << ' ';
    cout << endl;
}

void show(vector<pair<int, int>> &a)
{
    for (int i = 1; i < a.size(); i++)
        cout << a[i].second << ' ' << a[i].first << endl;
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
    vector<pair<int, int>> p(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> p[i].second >> p[i].first;

    // 面试分数线根据计划录取人数的 150% 划定
    sort(++p.begin(), p.end(), [](pair<int, int> &a, pair<int, int> &b)
         {
        if (a.first == b.first)
            return a.second > b.second;
        return a.first < b.first; });
    int line = m * 1.5, sum = line;

    for (int i = n - line; i >= 1 && p[i].first == p[n - line + 1].first; i--)
        sum++;

    cout << p[n - sum + 1].first << ' ' << sum << endl;
    for (int i = n; i >= n - sum + 1; i--)
        cout << p[i].second << ' ' << p[i].first << endl;

    return 0;
}