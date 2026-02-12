#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[100];
int main()
{
    scanf("%d", &n);
    int tot = 1;
    for (int i = 1; i <= n; ++i)
    {
        a[i] = i;
        tot *= i;
    }
    for (int i = 1; i <= tot; ++i)
    {
        for (int j = 1; j <= n; ++j)
            printf("    %d", a[j]); // 输出格式注意
        next_permutation(a + 1, a + n + 1);
        printf("\n");
    }
    return 0;
}
