#include <bits/stdc++.h>
using namespace std;
#define ll long long

void showve(vector<int> &a)
{
    for (int i = 1; i < a.size(); i++)
        cout << a[i] << ' ';
    cout << endl;
}

void solve(vector<vector<char>> &matrix, int x, int y, string des, int &total)
{
    int N = matrix.size() - 1, M = matrix[0].size() - 1;

    // 从最上方若干行（至少一行）的格子全部是白色的；
    // 接下来若干行（至少一行）的格子全部是蓝色的；
    // 剩下的行（至少一行）全部是红色的；
    if (x == N + 1)
    {
        bool w = true;
        for (int i = 1; i <= M; i++)
            if (matrix[1][i] != 'w')
                w = false;

                return;
    }

    for (int i = 0; i < des.size(); i++)
    {
        if (matrix[x][y] == des[i])
            continue;

        matrix[x][y] = des[i];

        if (y % M == 0)
            solve(matrix, x + 1, 1, des, ++total);
        solve(matrix, x, y + 1, des, ++total);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M;
    cin >> N >> M;
    vector<vector<char>> matrix(N + 1, vector<char>(M + 1));
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            cin >> matrix[i][j];

    return 0;
}