#include <bits/stdc++.h>
using namespace std;
#define ll long long

void showve(vector<int> &a)
{
   for (int i = 1; i < a.size(); i++)
       cout << a[i] << ' ';
   cout << endl;
}

int solve(string &a, string &b)
{
    int total = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == b[i])
            total++;
    }
    return total;
}

// 错解，有可能不是最少操作次数
void brute(string &a)
{
    int total = 0;
    for (int i = 1; i < a.size(); i++)
    {
        if (a[i] != a[i - 1])
            continue;
        
        for (int j = i + 1; j < a.size(); j++)
        {
            if (a[j] != a[i])
            {
                total++;
                swap(a[j], a[i]);
                break;
            }
        }
    }

    cout << total << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;

    // 忽略过程，关注起始和结束。每次通过换位将原字符串改成目标字符串是不同字符的一半
    // 答案只有可能是ABAB……或者BABA……，将原字符串交换位置变成目标串
    // 交换形成两者的交换次数，其实就是原字符串和目标串的编辑距离/2
    // 从怎么将原字符串通过交换变成目标串改成怎么从原字符串直接变成目标串的最小值
    while (T--)
    {
        int n;
        cin >> n;
        string a, b;
        // a = "BABABA...", b = "ABABABAB..."
        for (int i = 0; i < 2 * n; i++)
        {
            if (i & 1)
            {
                a += 'A';
                b += 'B';
            }
            else
            {
                a += 'B';
                b += 'A';
            }
        }

        string s;
        cin >> s;
        // brute(s);
        int t = solve(s, a);
        cout << min(t, 2 * n - t) / 2 << endl;
    }

    return 0;
}