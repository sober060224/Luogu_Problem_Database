#include <bits/stdc++.h>
using namespace std;
#define ll long long

void showm(map<ll, ll, greater<ll>> m)
{
    for (auto i : m)
        cout << i.first << ' ' << i.second << endl;
}
void showpq(priority_queue<pair<ll, ll>> pq)
{
    while(!pq.empty())
    {
        cout << pq.top().first << ' ' << pq.top().second << endl;
        pq.pop();
    }
}
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

    ll n, k, x;
    cin >> n >> k >> x;

    map<ll, ll, greater<ll>> m;
    for (ll i = 0; i < n; i++)
    {
        ll t;
        cin >> t;
        m[t]++;
    }
    
    while(k)
    {
        auto head = m.begin();
        if (m.size() == 1)
        {
            cout << head->first - k / head->second * x;
            return 0;
        }
        auto next = head;
        next++;
        int diff = head->first - next->first, cnt = (diff + x - 1) / x;
        if (k >= cnt * head->second)
        {
            k -= cnt * head->second;
            m[head->first - cnt * x] += head->second;
            m.erase(head);
        }
        else
        {
            cout << head->first - k / head->second * x;
            return 0;
        }
    }

    // showm(m);
    cout << m.begin()->first;

    return 0;
}