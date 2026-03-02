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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int R, C, K;
    cin >> R >> C >> K;
    vector<string> matrix(R + 1);

    for (int i = 1; i <= R; i++)
        cin >> matrix[i];

    int count = 0;

    for (int i = 1; i <= R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            bool ok = true;
            for (int k = 0; k < K; k++)
            {
                if (j + k >= C || matrix[i][j + k] != '.')
                {
                    ok = false;
                    break;
                }
            }
            if (ok)
                count++;

            ok = true;
            for (int k = 0; k < K; k++)
            {
                 if (i + k > R || matrix[i + k][j] != '.')
                {
                    ok = false;
                    break;
                }
            }
            if (ok)
                count++;
        }
    }

    // // row
    // for (int i = 1; i <= R; i++)
    // {
    //     for (int j = 0; j < C - K + 1; j++)
    //     {
    //         bool ok = true;
    //         for (int k = 0; k < K; k++)
    //         {
    //             if (matrix[i][j + k] != '.')
    //             {
    //                 ok = false;
    //                 break;
    //             }
    //         }
    //         if (ok)
    //             count++;
    //     }
    // }
    // // col
    // for (int i = 1; i <= R - K + 1; i++)
    // {
    //     for (int j = 0; j < C; j++)
    //     {
    //         bool ok = true;
    //         for (int k = 0; k < K; k++)
    //         {
    //             if (matrix[i + k][j] != '.')
    //             {
    //                 ok = false;
    //                 break;
    //             }
    //         }
    //         if (ok)
    //             count++;
    //     }
    // }

    if (K == 1)
        cout << count / 2;
    else
        cout << count;

    return 0;
}