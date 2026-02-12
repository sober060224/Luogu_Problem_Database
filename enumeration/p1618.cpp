#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MN = 1001;

class myHash
{
public:
    size_t operator()(const vector<int> &v) const
    {
        size_t t = 0;
        for (int i = 1; i < v.size(); i++)
            t = t * 10 + v[i];
        return t % 1000003;
    }
};

struct VectorHash
{
    size_t operator()(const vector<int> &v) const
    {
        hash<int> int_hasher;
        size_t seed = 0;
        for (auto &i : v)
            seed ^= int_hasher(i) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        return seed;
    }
};

// int ratioToMask(int A, int B, int C)
// {
//     return (A << 6) + (B << 3) + C;
// }
// void maskApplyRatio(int &A, int &B, int &C, int mask)
// {
//     A = mask & ((1 << 3) - 1);
//     mask >>= 3;
//     B = mask & ((1 << 3) - 1);
//     mask >>= 3;
//     C = mask & ((1 << 3) - 1);
// }
// void testMask(int A, int B, int C)
// {
//     int mask = ratioToMask(A, B, C);
//     cout << mask << endl;
//     int a, b, c;
//     maskApplyRatio(a, b, c, mask);
//     cout << a << endl
//          << b << endl
//          << c;
// }

void showve(vector<int> &a)
{
    for (int i = 1; i < a.size(); i++)
        cout << a[i] << ' ';
    cout << endl;
}

// void solve(vector<int> &a, vector<bool> &visited, int index, int mask)
// {
//     if (index == 4)
//     {
//         int a, b, c;
//         maskApplyRatio(a, b, c, mask);
//         return;
//     }
//     for (int i = 1; i <= 9; i++)
//     {
//         if (visited[i])
//             continue;
//         a[index] = i;
//         visited[i] = true;
//         solve(a, visited, index + 1, mask);
//         visited[i] = false;
//     }
// }

int arrayToNum(vector<int> &v, int lo, int hi)
{
    int x = 0;
    for (int i = lo; i <= hi; i++)
        x = x * 10 + v[i];
    return x;
}
void testatn()
{
    vector<int> a = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << arrayToNum(a, 7, 9);
}

void judge(vector<int> &container, vector<int> &ratio, set<vector<int>> &ans);

void solve(vector<int> &container, vector<bool> &visited, int index, set<vector<int>> &ans, vector<int> &ratio)
{
    if (index > 9)
    {
        judge(container, ratio, ans);
        return;
    }

    for (int i = 1; i <= 9; i++)
    {
        if (visited[i])
            continue;

        container[index] = i;
        visited[i] = true;
        solve(container, visited, index + 1, ans, ratio);
        visited[i] = false;
    }
}
void judge(vector<int> &container, vector<int> &ratio, set<vector<int>> &ans)
{
    // 从小到大排序三个三位数
    vector<int> num(4);
    int lo = 1, hi = 3;
    for (int i = 1; i <= 3; i++)
    {
        // showve(num);
        num[i] = arrayToNum(container, lo, hi);
        lo += 3, hi += 3;
    }
    sort(num.begin(), num.end());
    // showve(num);

    // 三个三位数是否符合比例
    if (num[1] * ratio[2] / ratio[1] == num[2] && num[1] * ratio[3] / ratio[1] == num[3])
        ans.insert(num);
}
void testjudge()
{
    vector<int> a = {0, 1, 9, 2, 3, 8, 4, 5, 7, 6};
    vector<int> ratio = {0, 1, 2, 3};
    set<vector<int>> ans;
    judge(a, ratio, ans);

    for (vector<int> v : ans)
        showve(v);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    // testatn();
    // testjudge();

    vector<int> ratio(4);
    for (int i = 1; i <= 3; i++)
    {
        cin >> ratio[i];
        if (ratio[i] == 0)
        {
            cout << "No!!!";
            return 0;
        }
    }

    sort(ratio.begin(), ratio.end());
    vector<int> container(10);
    vector<bool> visited(10);
    set<vector<int>> ans;

    solve(container, visited, 1, ans, ratio);

    if (ans.size() == 0)
        cout << "No!!!";
    for (vector<int> v : ans)
        showve(v);

    return 0;
}