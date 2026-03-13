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

vector<int> ans(1e5);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    srand((unsigned int)time(nullptr));
    int T;
    cin >> T;
    // T = rand() % int(1e5);
    int a, b, c, k, newa, newb, newc;
    while (T--)
    {
        cin >> a >> b >> c >> k;
        while (k--)
        {
            newa = (b + c) / 2;
            newb = (a + c) / 2;
            newc = (a + b) / 2;
            a = newa;
            b = newb;
            c = newc;
            if (a == b == c)
                break;
        }
        cout << a << ' ' << b << ' ' << c << endl;
    }

    return 0;
}