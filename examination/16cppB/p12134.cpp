#include <chrono>
#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#define ll long long

using namespace std;

int main()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n + 1);
    for (ll i = 1; i <= n; i++)
        cin >> a[i];

    sort(++a.begin(), a.end());
    ll ans = 1e10;
    for (ll i = 1; i + m - 1 <= n; i++)
        ans = min(ans, a[i + m - 1] * a[i + m - 1] - a[i] * a[i]);

    cout << ans;

    return 0;
}