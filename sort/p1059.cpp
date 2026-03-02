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

    int N;
    cin >> N;
    vector<int> a(N + 1);
    for (int i = 1; i <= N; i++)
        cin >> a[i];
    
    sort(++a.begin(), a.end());
    a.erase(unique(++a.begin(), a.end()), a.end());
    cout << a.size() - 1 << endl;
    showve(a);

    return 0;
}