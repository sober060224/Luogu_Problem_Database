#include <bits/stdc++.h>
using namespace std;
#define ll long long

int gcd(int a, int b)
{
    return a % b == 0 ? b : gcd(b, a % b);
}
void test()
{
    int n, m;
    cin >> n >> m;
    cout << gcd(n, m);
}

void showve(vector<int> &a)
{
   for (int i = 1; i < a.size(); i++)
       cout << a[i] << ' ';
   cout << endl;
}

void ans(string a, string b)
{
    string ans [] = {
        a, // 双引号中替换为 A 题的答案
        b, // 双引号中替换为 B 题的答案
    };
    char T;
    cin >> T;
    cout << ans[T - 'A'] << endl;
}

void solve()
{
    int l = 343720, w = 233333, t = l / 2;
    double ans = sqrt(t * t + w * w) * 4;
    // cout << ans << endl;
    // cout << fixed << setprecision(2) << ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    // n-1 + (n - 2) + ... + 1 - (6 + 5 + ... + 1)
    string a = "1204";
    // test();
    solve();

    return 0;
}