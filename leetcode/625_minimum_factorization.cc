#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
    int smallestFactorization(int a) {
        if (a < 10) return a;
        long ret = 0, mul = 1;
        for (int i = 9; i > 1; i--) {
            while (a % i == 0) {
                a = a / i;
                ret += mul * i;
                mul *= 10;
            }
        }
        return (a > 1 || ret > INT_MAX) ? 0 : (int)ret;
    }
};

int main(int argc, const char *argv[])
{
    Solution solution;
    cout << solution.smallestFactorization(1800000) << endl;
    return 0;
}
