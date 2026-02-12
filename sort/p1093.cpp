#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

class Student
{
public:
    vector<int> grade;
    int index, sum;
    Student()
    {
        grade.resize(3);
        sum = 0;
    }
};

void solve()
{
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<Student> s(n + 1);
    for (int i = 1; i <= n; i++)
    {
        s[i].index = i;
        for (int j = 0; j < 3; j++)
        {
            cin >> s[i].grade[j];
            s[i].sum += s[i].grade[j];
        }
    }

    sort(s.begin(), s.end(), [](Student &a, Student &b)
         {
        if (a.sum == b.sum)
            return a.grade[0] > b.grade[0];
        return a.sum > b.sum; });

    for (int i = 0; i < 5; i++)
        cout << s[i].index << ' ' << s[i].sum << endl;

    return 0;
}