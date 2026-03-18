#include <bits/stdc++.h>
using namespace std;
#define ll long long

void showve(vector<pair<int, int>> &a)
{
    for (int i = 1; i < a.size(); i++)
        cout << a[i].first << ' ';
    cout << endl;
}

void solve()
{
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    // int n;
    // cin >> n;
    // vector<int> a(n + 1);
    // for (int i = 1; i <= n; i++)
    //     cin >> a[i];
    // sort(++a.begin(), a.end(), greater<>());
    // showve(a);
    // auto it = lower_bound(++a.begin(), a.end(), 3, greater<>());
    // cout << it - a.begin();

    // 将下标一起存着，排序一下，二分查找迭代器
    int n;
    cin >> n;
    vector<pair<int, int>> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int t;
        cin >> t;
        a[i] = {t, i};
    }
    sort(++a.begin(), a.end());
    // showve(a);
    // auto it = lower_bound(++a.begin(), a.end(), make_pair(3, 0));
    // cout << it - a.begin();
    int Q;
    cin >> Q;

    while (Q--)
    {
        int t;
        cin >> t;
        auto it = lower_bound(++a.begin(), a.end(), make_pair(t, 0));
        if (it->first == t)
            cout << it->second << endl;
        else
            cout << 0 << endl;
    }

    return 0;
}