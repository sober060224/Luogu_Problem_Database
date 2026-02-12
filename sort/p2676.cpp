#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1001;

void solve()
{
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, B;
    cin >> N >> B;
    vector<int> cows(N + 1);
    for (int i = 1; i <= N; i++)
        cin >> cows[i];
    sort(++cows.begin(), cows.end());

    int sum = 0;
    for (int i = N; i >= 1; i--)
    {
        if (B <= 0)
            break;
        B -= cows[i];
        sum++;
    }
    cout << sum;

    return 0;
}