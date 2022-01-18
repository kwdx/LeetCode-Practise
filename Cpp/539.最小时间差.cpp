/*
 * @lc app=leetcode.cn id=539 lang=cpp
 *
 * [539] 最小时间差
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = (int)timePoints.size();
        if (n >= 1440) return 0;
        vector<int> cnts(1440 * 2 + 1);
        for (string& s : timePoints) {
            auto idx = s.find(":");
            int hour = atoi(s.substr(0, idx).c_str());
            int minute = atoi(s.substr(idx + 1).c_str());
            if (cnts[hour * 60 + minute]++ == 1) return 0;
            ++cnts[hour * 60 + minute + 1440];
        }
        int ans = 1440, last = -1;
        for (int i = 0; i <= 1440 * 2 && ans != 0; ++i) {
            if (cnts[i] == 0) continue;
            else if (last != -1) ans = min(ans, i - last);
            last = i;
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<string> timePoints;
    int res;
    
    /**
     输入：timePoints = ["23:59","00:00"]
     输出：1
     */
    timePoints = {"23:59","00:00"};
    res = 1;
    assert(res == Solution().findMinDifference(timePoints));
    
    /**
     输入：timePoints = ["00:00","23:59","00:00"]
     输出：0
     */
    timePoints = {"00:00","23:59","00:00"};
    res = 0;
    assert(res == Solution().findMinDifference(timePoints));

    cout << "OK~" << endl;

    return 0;
}
