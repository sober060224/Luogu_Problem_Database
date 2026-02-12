#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1001;

class student
{
public:
    string s;
    int y, m, d, index;
    student(string s, int y, int m, int d) : s(s), y(y), m(m), d(d) {}
    student() {}
};

void show(vector<int> &a)
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

    int n;
    cin >> n;
    vector<student> students(n + 1);
    for (int i = 1; i <= n; i++)
    {
        student t;
        t.index = i;
        cin >> t.s >> t.y >> t.m >> t.d;
        students[i] = t;
    }

    sort(students.begin(), students.end(), [](student &a, student &b)
         { 
            if (a.y == b.y && a.m == b.m && a.d == b.d)
                return a.index > b.index;
            if (a.y == b.y && a.m == b.m)
                return a.d < b.d;
            if (a.y == b.y)
                return a.m < b.m;
            return a.y < b.y; });

    for (int i = 1; i <= n; i++)
        cout << students[i].s << endl;

    return 0;
}