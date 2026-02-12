#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1001;

class president
{
public:
    vector<int> votes;
    int index;
};

// void parseStringToVector(vector<string> &a, vector<vector<int>> &people)
// {
//     int n = a.size() - 1;
//     for (int i = 1; i <= n; i++)
//         for (int j = 1; j <= n; j++)
//             people[i].push_back(a[i][j] - '0');
// }
void parseStringToVector(vector<string> &a, vector<president> &people)
{
    int n = a.size() - 1;
    for (int i = 1; i <= n; i++)
    {
        people[i].index = i;
        for (int j = 0; j < a[i].size(); j++)
            people[i].votes.push_back(a[i][j] - '0');
    }
}
void testpstv()
{
    vector<string> a = {"0", "981765"};
    vector<president> people(2);
    parseStringToVector(a, people);
    for (int i : people[1].votes)
        cout << i;
}

bool lessThan(president &a, president &b)
{
    // if (a.size() != b.size())
    //     return a.size() < b.size();
    // for (int i = 0; i < a.size(); i++)
    //     if (a[i] != b[i])
    //         return a[i] < b[i];
    // return false;
    if (a.votes.size() != b.votes.size())
        return a.votes.size() < b.votes.size();
    for (int i = 0; i < a.votes.size(); i++)
        if (a.votes[i] != b.votes[i])
            return a.votes[i] < b.votes[i];

    return false;
}
void testlt()
{
    president a, b;
    a.votes = {0, 3, 1}, b.votes = {0, 2, 2};
    if (lessThan(a, b))
        cout << "a < b" << endl;
    else
        cout << "a > b" << endl;
}

void solve()
{
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    // testlt();
    // vector<int> a = {0, 1, 2};
    // cout << *(++a.begin());
    int n;
    cin >> n;
    vector<string> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    vector<president> humans(n + 1);
    vector<vector<int>> people(n + 1);
    parseStringToVector(a, humans);
    sort(++humans.begin(), humans.end(), lessThan);

    cout << humans[n].index << endl;
    for (int i : humans[n].votes)
        cout << i;

    return 0;
}