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

    int m;
    cin >> m;

    set<int> s;
    while (m--)
    {
        int t, length;
        cin >> t >> length;
        switch (t)
        {
        case 1:
            if (s.find(length) == s.end())
                s.insert(length);
            else
                cout << "Already Exist" << endl;
            break;
        case 2:
            if (s.empty())
            {
                cout << "Empty" << endl;
                break;
            }
            auto it = s.lower_bound(length);
            // 找不到
            if (it == s.end())
            {
                cout << *(--it) << endl;
                s.erase(it);
                break;
            }
            // 在第一个地方找到
            if (it == s.begin())
            {
                cout << *it << endl;
                s.erase(it);
                break;
            }

            if (*it == length)
            {
                cout << *it << endl;
                s.erase(it);
            }
            else
            {
                auto it2 = it;
                it--;
                if (abs(*it - length) <= abs(*it2 - length))
                {
                    cout << *it << endl;
                    s.erase(it);
                }
                else
                {
                    cout << *it2 << endl;
                    s.erase(it2);
                }
            }
            break;
        }
    }

    return 0;
}