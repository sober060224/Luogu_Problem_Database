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
    string d;
    cin >> n >> d;
    reverse(d.begin(), d.end());
    vector<int> a(1e5);
    int line = d.size();

    // 将.去掉
    auto it = find(d.begin(), d.end(), '.');
    int index = it - d.begin();
    d.erase(it);
    for (int i = 0; i < d.size(); i++)
        a[i + 1] = d[i] - '0';

    // 将浮点数乘以2^n
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= line; j++)
            a[j] *= 2;
        for (int j = 1; j <= line + 1; j++)
        {
            a[j + 1] += a[j] / 10;
            a[j] %= 10;
        }
        if (a[line + 1])
            line++;
    }

    // 四舍五入到最接近的整数
    if (a[index] >= 5)
        a[index + 1]++;
    for (int j = 1; j <= line + 1; j++)
    {
        a[j + 1] += a[j] / 10;
        a[j] %= 10;
    }
    if (a[line + 1])
        line++;
    
    // 输出
    for (int i = line; i > index; i--)
        cout << a[i];

    return 0;
}