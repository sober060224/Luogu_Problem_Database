#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1001;

void show(vector<int> &a)
{
    for (int i : a)
        cout << i << ' ';
    cout << endl;
}

int solve(vector<int> &a, int lo, int hi)
{
    vector<int> t = a;
    int mid = (lo + hi) / 2, i = lo, k = lo, j = mid + 1, sum = 0;

    while (i <= mid && j <= hi)
    {
        // show(a);

        if (t[i] > t[j])
        {
            sum += (mid - i + 1);
            a[k] = t[j];
            k++, j++;
        }
        else
            a[k++] = t[i++];
    }

    while (i <= mid)
        a[k++] = t[i++];
    while (j <= hi)
        a[k++] = t[j++];
    // show(a);

    return sum;
}
void testsolve()
{
    // 2:1 4:2 5:2
    vector<int> a = {2, 4, 5, 1, 3};
    cout << solve(a, 0, 4);
}

int mergeSort(vector<int> &a, int lo, int hi)
{
    if (lo >= hi)
        return 0;
    int mid = (lo + hi) / 2;

    int left = mergeSort(a, lo, mid);
    int right = mergeSort(a, mid + 1, hi);
    return solve(a, lo, hi) + left + right;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    // testsolve();
    int N;
    cin >> N;
    vector<int> a(N + 1);
    for (int i = 1; i <= N; i++)
        cin >> a[i];

    cout << mergeSort(a, 1, N);

    return 0;
}