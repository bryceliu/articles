#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int ret = 0, minVal = arrays[0].front(), maxVal = arrays[0].back();
        for (int i = 1; i < arrays.size(); i++) {
            ret = max({ret, abs(arrays[i].back() - minVal), abs(maxVal - arrays[i].front())});
            minVal = min(minVal, arrays[i].front());
            maxVal = max(maxVal, arrays[i].back());
        }
        return ret;
    }
};

int main(int argc, const char *argv[])
{
    vector<vector<int>> vv = {
        {1, 2, 3},
        {4, 5},
        {1, 2, 3}
    };
    Solution solution;
    cout << solution.maxDistance(vv) << endl;
    return 0;
}
