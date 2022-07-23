/*
 * @lc app=leetcode.cn id=757 lang=cpp
 *
 * [757] 设置交集大小至少为2
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [&](const auto& a, const auto& b) {
            return a[1] == b[1] ? a[0] > b[0] : a[1] < b[1];
        });
        vector<int> ans;
        for (const auto& interval : intervals) {
            int a = interval[0];
            int b = interval[1];
            if (ans.empty()) {
                ans = {b - 1, b};
            } else {
                size_t s = ans.size();
                if (ans[s - 1] < a) {
                    ans.push_back(b - 1);
                }
                if (ans[s - 2] < a) {
                    ans.push_back(b);
                }
            }
        }
        return (int)ans.size();
    }
};
// @lc code=end


int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<vector<int>> intervals;
    int res;
    
    /**
     输入: intervals = [[1, 3], [1, 4], [2, 5], [3, 5]]
     输出: 3
     解释:
     考虑集合 S = {2, 3, 4}. S与intervals中的四个区间都有至少2个相交的元素。
     且这是S最小的情况，故我们输出3。
     */
    intervals = {{1, 3}, {1, 4}, {2, 5}, {3, 5}};
    res = 3;
    assert(res == Solution().intersectionSizeTwo(intervals));
    
    /**
     输入: intervals = [[1, 2], [2, 3], [2, 4], [4, 5]]
     输出: 5
     解释:
     最小的集合S = {1, 2, 3, 4, 5}.
     */
    intervals = {{1, 2}, {2, 3}, {2, 4}, {4, 5}};
    res = 5;
    assert(res == Solution().intersectionSizeTwo(intervals));
    
    cout << "OK~" << endl;
    
    return 0;
}
