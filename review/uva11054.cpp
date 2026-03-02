#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MN = 1001;

void show(vector<int> &a)
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

    while (1)
    {
        cin >> n;
        if (!n)
            break;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        int sum = 0;
        vector<int> prefix(n + 1);
        for (int i = 1; i <= n; i++)
        {
            prefix[i] = prefix[i - 1] + a[i];
            sum += abs(prefix[i]);
        }
        cout << sum << endl;
    }

    return 0;
}