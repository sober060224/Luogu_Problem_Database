#include <bits/stdc++.h>
using namespace std;
#define ll long long

void showve(vector<int> &a)
{
    for (int i = 1; i < a.size(); i++)
        cout << a[i] << ' ';
    cout << endl;
}

int myHash(vector<int> &a)
{
    int t = 0;
    for (int i = 1; i < a.size(); i++)
    {
        t = t * 10 + a[i];
        t %= 1000003;
    }
    return t % 1000003;
}

void solve(vector<int> &nums, int index, vector<bool> &visited, int &M, bool &point)
{
    int N = nums.size() - 1;

    if (!M)
        return;
    if (index > N)
    {
        // showve(nums);
        // cout << myHash(nums) << endl;
        if (point)
            M--;
        point = true;
        if (M == 0)
            showve(nums);
        return;
    }

    if (!point)
    {
        for (int i = nums[index]; i <= N; i++)
        {
            // showve(nums);
            if (visited[i])
                continue;

            nums[index] = i;
            visited[i] = true;
            solve(nums, index + 1, visited, M, point);
            visited[i] = false;
        }
    }
    else
    {
        for (int i = 1; i <= N; i++)
        {
            // showve(nums);
            if (!M)
                return;
            if (visited[i])
                continue;

            nums[index] = i;
            visited[i] = true;
            solve(nums, index + 1, visited, M, point);
            visited[i] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M;
    cin >> N >> M;
    vector<int> fingers(N + 1);
    for (int i = 1; i <= N; i++)
        cin >> fingers[i];
    vector<int> nums(N + 1);
    vector<bool> visited(N + 1, false);
    bool point = false;
    solve(fingers, 1, visited, M, point);
    // for (int i = 0; i < M; i++)
    // {
    //     // showve(fingers);
    //     next_permutation(++fingers.begin(), fingers.end());
    // }
    // showve(fingers);

    return 0;
}