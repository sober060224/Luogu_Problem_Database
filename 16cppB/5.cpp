#include <bits/stdc++.h>
using namespace std;
#define ll long long

class diff
{
public:
    int l, r, length;
    diff() {}
    diff(int l, int r, int length) : l(l), r(r), length(length) {}
    bool operator()(const diff &other)
    {
        if (length == other.length)
            return l < other.l;
        return length < other.length;
    }
};

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

    int N, M;
    cin >> N >> M;
    vector<int> A(N + 1);
    for (int i = 1; i <= N; i++)
        cin >> A[i];

    sort(++A.begin(), A.end());
    vector<bool> visited(N + 1, false);
    priority_queue<diff> pq;
    for (int i = 2; i <= N; i++)
        pq.push(diff(A[i - 1], A[i], A[i] - A[i - 1]));

    return 0;
}