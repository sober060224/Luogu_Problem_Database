#include <bits/stdc++.h>
using namespace std;
#define ll long long

class ticket
{
public:
    int x, y, length;
    ticket(){}
    ticket(int x, int y, int length) : x(x), y(y), length(length){}
    bool operator<(const ticket &t) const
    {
        if (length == t.length)
            return x > t.x;
        return length > t.length;
    }
};

void showpq(priority_queue<ticket> pq)
{
    cout << "----------------------------" << endl;
    while (!pq.empty())
    {
        cout << pq.top().x << ' ' << pq.top().y << ' ' << pq.top().length << endl;
        pq.pop();
    }
}

void showum(unordered_map<int, int> &um)
{
    cout << "----------------------------" << endl;
    for (auto t : um)
        cout << t.first << ' ' << t.second << endl;
}

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

    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    // 右指针一直向右走，直到攒够了m个数为止
    // 攒够m个数之后左指针开始移，直到还剩m-1个数为止
    unordered_map<int, int> um;
    priority_queue<ticket> pq;
    int l = 1, r = 1, cnt = 0;

    while (l <= n + 1 && r <= n + 1)
    {
        if (cnt < m)
        {
            if (um.find(a[r]) == um.end() || !um[a[r]])
                cnt++;
            um[a[r++]]++;
        }
        else
        {
            pq.push(ticket(l, r - 1, r - l));
            um[a[l]]--;
            if (!um[a[l++]])
                cnt--;
        }
    }

    cout << pq.top().x << ' ' << pq.top().y;

    return 0;
}