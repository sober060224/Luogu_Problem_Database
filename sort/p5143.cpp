#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MN = 1001;

class Point
{
public:
    int x, y, z;
};

double dis(int x1, int y1, int z1, int x2, int y2, int z2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 - z2));
}

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

    int N;
    cin >> N;
    vector<Point> coordinates(N + 1);
    for (int i = 1; i <= N; i++)
        cin >> coordinates[i].x >> coordinates[i].y >> coordinates[i].z;

    sort(++coordinates.begin(), coordinates.end(), [](Point &a, Point &b)
         { return a.z < b.z; });

    double sum = 0.0;
    for (int i = 1; i <= N - 1; i++)
        sum += dis(coordinates[i].x, coordinates[i].y, coordinates[i].z, coordinates[i + 1].x, coordinates[i + 1].y, coordinates[i + 1].z);

    cout << fixed << setprecision(3) << sum;

    return 0;
}