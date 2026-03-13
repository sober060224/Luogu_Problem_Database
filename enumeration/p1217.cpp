#include <bits/stdc++.h>
#include "p1217.h"
using namespace std;
#define ll long long

int vectorToInt(vector<int> &nums)
{
    int x = 0;
    for (int i = 1; nums[i] != 0 && i < nums.size(); i++)
        x = x * 10 + nums[i];
    return x;
}
void testvti()
{
    vector<int> nums = {0, 1, 2, 3};
    cout << vectorToInt(nums);
}

bool isPrime(int x)
{
    bool ok = true;
    for (int i = 2; i <= sqrt(x); i++)
        if (x % i == 0)
        {
            ok = false;
            break;
        }
    return ok;
}
void testip()
{
    if (isPrime(12))
        cout << "ok" << endl;
}
void showve(vector<int> &a)
{
   for (int i = 1; a[i] != 0 && i < a.size(); i++)
       cout << a[i];
   cout << endl;
}

// index2：总位数限制
void solve(vector<int> &nums, int index1, int index2, int a, int b)
{
    // 退出递归
    if (index1 > (index2 + 1) / 2)
    {
        showve(nums);
        exitRecursion(nums, index1, index2, a, b);

        return;
    }

    // 循环选择
    for (int i = 1; i <= 9; i++)
    {
        showve(nums);
        nums[index1] = i;

        solve(nums, index1 + 1, index2, a, b);
    }
}

// 是回文质数就输出
void exitRecursion(std::vector<int> &nums, int index1, int index2, int a, int b)
{
    // 3883
    // 构造回文数
    vector<int>::iterator End = ++nums.begin();
    int mid = index2 / 2;
    for (int i = 1; i < mid; i++)
        End++;
    vector<int>::iterator Begin = End;
    
    // vector<int> t = nums;
    // for (int i = 1; i <= index1; i++)
    //     t.push_back(t[mid - i + 1]);
    // int num = vectorToInt(t);
    // if (num >= a && num <= b && isPrime(t))
    //     showve(t);
}
void tester()
{
    vector<int> nums = {0, 1};
    int index1 = 1, index2 = 2;
    vector<int> t(100);
    // exitRecursion(nums, index1, index2, 5, 1000);
    // vector<int> nums(11);
    // nums = {0, 1, 0};
    // int index1 = 2, mid = 2;
    // vector<int> t = nums;
    // for (int i = 1; i <= index1; i++)
    //     t.push_back(t[mid - i + 1]);
    // showve(t);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    // testip();
    tester();
    testvti();
    int a, b;
    cin >> a >> b;
    // 递归改变位数也变，一个循环结束就增加可改变位数
    // 能解决最大位数：
    // 从最大数得到位数，找到需要改变的一半的位数
    // a < b
    int length = 0, t = b;
    while (t)
    {
        length++;
        t /= 10;
    }
    // 用递归从最左边一直找到中间位置，要包含中间的数字
    // length = (length + 1) / 2;
    vector<int> nums(11);
    for (int i = 1; i <= length; i++)
        solve(nums, 1, i, a, b);
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// void showve(vector<int> &a)
// {
//    for (int i = 1; i < a.size(); i++)
//        cout << a[i] << ' ';
//    cout << endl;
// }
// void solve()
// {
// }
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0), cout.tie(0);
//     int a, b;
//     cin >> a >> b;
//     return 0;
// }