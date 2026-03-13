#include <bits/stdc++.h>
using namespace std;
#define ll long long

void showve(vector<int> &a)
{
   for (int i = 1; i < a.size(); i++)
       cout << a[i] << ' ';
   cout << endl;
}

void solve(vector<int> &container, int index, int a)
{

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;
    cin >> N;
    vector<int> a(N + 1);
    int total = 0;
    for (int i = 1; i <= N; i++)
    {
        cin >> a[i];
        if (a[i] != 1)
            total++;
    }

    cout << total;

    return 0;
}