#include <bits/stdc++.h>
using namespace std;
#define ll long long

class record
{
public:
    string name;
    int score;
    record(string name, int score) : name(name), score(score) {}
};

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

    int Q, cnt = 0;
    cin >> Q;
    unordered_map<string, int> um;
    while (Q--)
    {
        int op;
        cin >> op;

        switch (op)
        {
        case 1:
        {
            string name;
            int score;
            cin >> name;
            cin >> score;
            if (um.find(name) != um.end())
                um[name] = score;
            else
            {
                cnt++;
                um.insert({name, score});
            }
            cout << "OK" << endl;

            break;
        }
        case 2:
        {
            string name;
            cin >> name;
            if (um.find(name) == um.end())
                cout << "Not found" << endl;
            else
                cout << um[name] << endl;

            break;
        }
        case 3:
        {
            string name;
            cin >> name;
            if (um.find(name) == um.end())
                cout << "Not found" << endl;
            else
            {
                um.erase(name);
                cout << "Deleted successfully" << endl;
                cnt--;
            }

            break;
        }
        case 4:
        {
            cout << cnt << endl;
            break;
        }
        default:
            break;
        }
    }

    return 0;
}