#include <iostream>
#include <cmath>
using namespace std;
int main() {
    double x = 233, y = 666;
    double R = sqrt(x*x + y*y);
    double theta = atan2(y, x);
    double ans = R * (1 + theta);
    cout << round(ans) << endl;
    return 0;
}