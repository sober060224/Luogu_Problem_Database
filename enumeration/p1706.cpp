#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MN = 1001;

void showve(vector<int> &a)
{
    for (int i = 1; i < a.size(); i++)
        cout << setw(5) << a[i];
    cout << endl;
}

void solve(vector<int> &perm, int index, vector<bool> &visited)
{
    int n = perm.size() - 1;
    if (index > n)
    {
        showve(perm);
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (visited[i])
            continue;

        visited[i] = true;
        perm[index] = i;
        solve(perm, index + 1, visited);
        visited[i] = false;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        a[i] = i;

    do
    {
        showve(a);
    } while (next_permutation(++a.begin(), a.end()));
    

    // vector<bool> visited(n + 1, false);
    // vector<int> perm(n + 1);
    // solve(perm, 1, visited);

    return 0;
}