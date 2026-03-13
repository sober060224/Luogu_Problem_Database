#include <bits/stdc++.h>
using namespace std;
#define ll long long

void showve(vector<int> &a)
{
   for (int i = 0; i < a.size(); i++)
       cout << a[i] << ' ';
   cout << endl;
}

void solve(vector<int> &a, int idx, bool started, bool tight, int &ans)
{
    int n = a.size();
    if (idx == n)
    {
        if (started)
            ans++;
        return;
    }

    // 设置限制，初始化
    int limit = tight ? a[idx] : 9, real_pos = n - idx, start = started ? 0 : 1;
    if (!started)
        solve(a, idx + 1, false, false, ans);
    
    // 从个位开始枚举
    for (int i = start; i <= limit; i++)
    {
        if (real_pos % 2 == 1)
        {
            if (i % 2 == 0)
                continue;
        }
        else
            if (i % 2 == 1)
                continue;
        // 还要设置限制，看前缀有没有相同
        solve(a, idx + 1, true, tight && (i == limit), ans);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, ans = 0;
    cin >> N;
    string s = to_string(N);
    vector<int> a(s.size());
    for (int i = 0; i < s.size(); i++)
        a[i] = s[i] - '0';
    // showve(a);
    solve(a, 0, false, true, ans);
    cout << ans;

    return 0;
}