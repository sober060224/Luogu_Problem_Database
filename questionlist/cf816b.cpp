#include <bits/stdc++.h>
using namespace std;
#define ll long long

void showve(vector<int> &a)
{
   for (int i = 1; i < a.size(); i++)
   {
       cout << a[i] << ' ';
        if (i % 200 == 0)
            cout << endl;
   }
   cout << endl;
}

void solve()
{

}

vector<int> ar(2e5 + 10);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n, k, q;
    cin >> n >> k >> q;

    // n很大10^5，q很大10^5，l,r,a,b很大10^5
    // 区间修改
    // 区间查询大于k的值有多少个
    // d[i] = a[i] - a[i - 1]
    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        ar[r + 1]--;
        ar[l]++;
    }

    // 得到原值
    for (int i = 1; i <= 2e5; i++)
        ar[i] += ar[i - 1];
    // showve(a);
   
    // 有多少个大于k的值
    for (int i = 1; i <= 2e5; i++)
    {
        if (ar[i] >= k)
            ar[i] = 1;
        else
            ar[i] = 0;
    }

    // 得到大于k的前缀和
    for (int i = 1; i <= 2e5; i++)
        ar[i] += ar[i - 1];
    // for (int i = 90; i <= 100; i++)
    //     cout << ar[i] << ' ';
    // cout << endl;

    while (q--)
    {
        int a, b;
        cin >> a >> b;
        cout << ar[b] - ar[a - 1] << endl;
    }

    return 0;
}