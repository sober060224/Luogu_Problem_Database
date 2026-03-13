#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll MOD = 1e9 + 7;

ll quickPower(ll a, ll b, ll c)
{
    ll t = a, sum = 1;
    while (b)
    {
        if (b & 1)
            sum = (t % c) * (sum % c);
        b >>= 1;
        t = (t % c) * (t % c);
    }
    return sum % c;
}
void testqp()
{
    cout << quickPower(3, 13, 100);
}

// // visited:数字是否被使用过
// void solve(vector<ll> &op, ll index, vector<ll> &a, ll sum, vector<bool> &visited, ll &res)
// {
//     ll n = a.size() - 1;
//     if (index > n - 1)
//     {
//         // 找到^位置，先计算^之后再进行下一步计算
//         // 存储^位置，快速找到^之后先计算^再进行计算
//         // 枚举的时候有^出现就先计算^，再进行下一步计算
//         showve(op);
//         showve(visited);
//         unordered_set<ll> us;
//         for (ll i = 1; i <= n - 1; i++)
//         {
//             if (op[i] == 1)
//             {
//                 // 计算+-
//                 for (ll j = 0; j < 2; j++)
//                 {
//                     if (visited[i + j])
//                         continue;
//                     sum += a[i + j];
//                     visited[i + j] = true;
//                     us.insert(i + j);
//                 }
//             }
//             else if (op[i] == 2)
//             {
//                 if (visited[i + 1])
//                     continue;
//                 sum -= a[i + 1];
//                 visited[i + 1] = true;
//                 us.insert(i + 1);
//             }
//         }
//         res += sum;
//         for (ll i : us)
//             visited[i] = false;
//         return;
//     }
//     for (ll i = 1; i <= 3; i++)
//     {
//         op[index] = i;
//         if (i == 3)
//         {
//             if (index > 1)
//             {
//                 if (op[index - 1] == 1)
//                     sum = sum + (a[index + 1] ^ a[index]);
//                 else if (op[index - 1] == 2)
//                     sum = sum - (a[index + 1] ^ a[index]);
//             }
//             else
//                 sum = sum + (a[index + 1] ^ a[index]);
//             visited[index + 1] = true;
//             visited[index] = true;
//         }
//         solve(op, index + 1, a, sum, visited, res);
//         if (i == 3)
//         {
//             visited[index + 1] = false;
//             visited[index] = false;
//         }
//     }
// }

// 枚举的时候有^出现就先计算^，再进行下一步计算
// 直接统计全部异或块的和忽略了多个异或的可能性
// 存储^位置，快速找到^之后先计算^再进行计算
// 找到^位置，先计算^之后再进行下一步计算
// 速度太慢，可以在枚举的时候就开始进行计算
// 异或优先级最高，计算要先考虑异或的存在
// 记录每次运算符之后块的和，total记录上次块的总和（避免因下一个块不确定导致出错）
// 三个递归代表不同的选择，和for等价，但是这里用不了for
void solve(vector<ll> &a, ll index, ll curXor, ll total, ll sign, ll &ans)
{
    ll n = a.size() - 1;
    if (index > n - 1)
    {
        total += curXor * sign;
        ans = (total + ans) % MOD;
        return;
    }
    // +-^
    solve(a, index + 1, a[index + 1], total + sign * curXor, 1, ans);
    solve(a, index + 1, a[index + 1], total + curXor * sign, -1, ans);
    solve(a, index + 1, curXor ^ a[index + 1], total, sign, ans);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    // testqp();
    ll n, sum = 0, ans = 0;
    cin >> n;
    vector<ll> a(n + 1);
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum ^= a[i];
        if (i < n)
            ans = (ans + 2 * sum * quickPower(3, n - i - 1, MOD)) % MOD;
        else
            ans = (ans + sum) % MOD;
    }
    cout << ans;

    // if (n == 1)
    // {
    //     cout << a[1] % MOD << endl;
    //     return 0;
    // }
    // ll ans = 0;
    // solve(a, 1, a[1], 0, 1, ans);
    // cout << ans;

    return 0;
}