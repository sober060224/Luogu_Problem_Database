#include <bits/stdc++.h>
using namespace std;
#define ll long long

class area
{
public:
    ll l, r, value;
    area(ll l, ll r, ll value) : l(l), r(r), value(value) {}
};

void showve(vector<ll> &a)
{
    for (ll i = 1; i < a.size(); i++)
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

    // srand((unsigned ll)time(nullptr));
    // ll cnt = 0;
    // for (ll i = 0; i < 10; i++)
    // {
    //     ll a = rand() % 1000, b = rand() % 1000;
    //     if ((a * b / 2) == (b / 2 * a))
    //         cnt++;
    // }
    // cout << cnt;

    ll n;
    cin >> n;
    vector<ll> a(n + 1);
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] += a[i - 1];
    }

    // 将任意区间的值存下来，找到差值最小的两个不相交区间
    vector<area> diff;
    diff.reserve(n / 2 * (n + 1));
    for (ll i = 1; i <= n; i++)
        for (ll j = i; j <= n; j++)
            diff.push_back(area(i, j, a[j] - a[i - 1]));
    sort(diff.begin(), diff.end(), [](area &a, area &b){
        return a.value < b.value;
    });

    ll ans = INT_MAX;
    for (ll i = 0; i < diff.size(); i++)
    {
        for (ll j = i + 1; j < diff.size(); j++)
        {
            ll value = diff[j].value - diff[i].value;

            if (value >= ans && ans != INT_MAX)
                break;
            bool ok = (diff[j].r < diff[i].l) || (diff[i].r < diff[j].l);

            if (ok)
            {
                ans = min(ans, value);
                // 易漏剪枝
                if (ans == 0)
                    break;
            }
        }
    }
    cout << ans;

    return 0;
}