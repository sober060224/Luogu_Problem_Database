#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MN = 1001;

bool isPrime(int &x)
{
    if (x < 2)
        return false;
    if (x == 2)
        return true;
    if (x % 2 == 0)
        return false;
    int limit = sqrt(x);
    for (int i = 2; i <= limit; i++)
        if (x % i == 0)
            return false;
    return true;
}
// void testiP()
// {
//     if (isPrime(22))
//         cout << "ok";
// }

void showve(vector<int> &a)
{
    for (int i = 1; i < a.size(); i++)
        cout << a[i] << ' ';
    cout << endl;
}

void solve(vector<int> &x, int k, int index, int sum, int &res, int total)
{
    int n = x.size() - 1;

    // 选完k个数
    if (total >= k)
    {
        // 不是素数
        if (!isPrime(sum))
            return;
        // cout << sum << endl;
        res++;
        return;
    }

    // 要选>可选
    if (k - total > n - index + 1)
        return;

    // 去重，上下两个剪枝效果一样
    for (int i = index; i <= n - (k - total - 1); i++)
        solve(x, k, i + 1, sum + x[i], res, total + 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    // testiP();

    int n, k;
    cin >> n >> k;
    vector<int> x(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> x[i];

    int sum = 0, res = 0, total = 0;

    solve(x, k, 1, sum, res, total);
    cout << res;

    return 0;
}