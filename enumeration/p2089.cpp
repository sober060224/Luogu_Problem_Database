#include <iostream>
#include <vector>
using namespace std;
#define ll long long
const int MN = 1001;

void showve(vector<int> &a)
{
    for (int i = 1; i < a.size(); i++)
        cout << a[i] << ' ';
    cout << endl;
}

void solve(vector<int> &a, int index, int n, int &project, vector<vector<int>> &dest)
{
    // 超出数组边界
    if (index == 11)
    {
        if (!n)
        {
            dest.push_back(a); // 存储所有方案
            project++;         // 统计方案数
        }
        return;
    }

    // 避免剩下n过小或过大
    if (n < (10 - index + 1) || n > (10 - index + 1) * 3)
        return;

    for (int i = 1; i <= 3; i++)
    {
        // 避免剩下n过小
        if (n < i)
            continue;
        a[index] = i;
        solve(a, index + 1, n - i, project, dest);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;

    vector<int> a(11);
    vector<vector<int>> dest;
    int project = 0;

    if (n <= 30 && n >= 10)
        solve(a, 1, n, project, dest);

    cout << project << endl;
    for (vector<int> v : dest)
        showve(v);

    return 0;
}