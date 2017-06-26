#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int min1 = INT_MAX, min2 = INT_MAX;
        int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;

        for (int i : nums) {
            if (i < min1) {
                min2 = min1;
                min1 = i;
            } else if (i < min2) {
                min2 = i;
            }

            if (i > max3) {
                max1 = max2;
                max2 = max3;
                max3 = i;
            } else if (i > max2) {
                max1 = max2;
                max2 = i;
            } else if (i > max1) {
                max1 = i;
            }
        }

        return max(min1 * min2 * max3, max1 * max2 * max3);
    }
};

int main(int argc, const char *argv[])
{
    vector<int> v = {-1, -2, -3};
    Solution solution;
    cout << solution.maximumProduct(v) << endl;
    return 0;
}
