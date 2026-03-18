#include <bits/stdc++.h>
using namespace std;
#define ll long long

void showve(vector<int> &a)
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

    int n;
    cin >> n;
    vector<int> id(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int t;
        cin >> t;
        id[i] = t + id[i - 1];
    }

    // 区间查询10^4，id[i]，10^6
    // nlogn，找连续区间和是7的倍数的最大长度

    // 枚举两个变量，剩下数字比答案还少就退出
    int ans = 0;
    for (int i = 1; i + ans - 1 <= n; i++)
    {
        // 答案如果已经有k个奶牛是7的倍数了，那就要找比k更大的区间
        for (int j = i + ans - 1; j + ans - 1<= n; j++)
        {
            cout << id[j] << ' ' << id[i - 1] << endl;
            if ((id[j] - id[i - 1]) % 7 == 0)
                ans = max(ans, j - i + 1);
        }
    }
    cout << ans;

    // 答案没有单调性，连存区间都不行
    // 前缀和有单调性，枚举一个变量，另一个变量二分找7的倍数下标，尽可能往大了找
    // for循环枚举左边界，找二分找当前左边界和n中间位置值(id[mid] - id[i]) % 7 == 0
    // 答案没有单调性啊，找取余执行不下去
    
    return 0;
}