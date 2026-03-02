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
    vector<int> a(n + 1), prefix(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        prefix[i] = prefix[i - 1] + a[i];
    }
    showve(prefix);

    int ans = INT_MIN;
    

    cout << ans;

    return 0;
}