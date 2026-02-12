#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1001;

void show(vector<int> &a)
{
    for (int i = 1; i < a.size(); i++)
        cout << a[i] << ' ';
    cout << endl;
}
void showus(unordered_set<int> &us)
{
    for (int i : us)
        cout << i << ' ';
    cout << endl;
}

void testus()
{
    unordered_set<int> a;
    a.insert(1);
    a.insert(1);
    showus(a);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    // testus();
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    unordered_set<int> us;
    int sum = n - 1;
    for (int i = 1; i <= n - 1; i++)
    {
        // showve(a);
        // 两个连续元素之间差的绝对值包括了 [1,n−1] 之间的所有整数
        int t = abs(a[i + 1] - a[i]);
        if (t <= n - 1 && t >= 1 && us.find(t) == us.end())
            sum--;
        us.insert(t);
        // showus(us);
    }

    if (!sum)
        cout << "Jolly";
    else
        cout << "Not jolly";

    return 0;
}