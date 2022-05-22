/*
 * @lc app=leetcode.cn id=436 lang=cpp
 *
 * [436] 寻找右区间
 */

#include <iostream>
#include <vector>
#include <map>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = (int)intervals.size();
        map<int, int> m;
        for (int i = 0; i < n; ++i) {
            m[intervals[i][0]] = i;
        }
        vector<int> ans(n, -1);
        for (int i = 0; i < n; ++i) {
            auto it = m.lower_bound(intervals[i][1]);
            if (it != m.end()) {
                ans[i] = (*it).second;
            }
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<vector<int>> intervals;
    vector<int> res;
    
    /**
     输入：intervals = [[1,2]]
     输出：[-1]
     解释：集合中只有一个区间，所以输出-1。
     */
    intervals = {{1,2}};
    res = {-1};
    assert(res == Solution().findRightInterval(intervals));
    
    /**
     输入：intervals = [[3,4],[2,3],[1,2]]
     输出：[-1,0,1]
     解释：对于 [3,4] ，没有满足条件的“右侧”区间。
     对于 [2,3] ，区间[3,4]具有最小的“右”起点;
     对于 [1,2] ，区间[2,3]具有最小的“右”起点。
     */
    intervals = {{3,4},{2,3},{1,2}};
    res = {-1,0,1};
    assert(res == Solution().findRightInterval(intervals));
    
    /**
     输入：intervals = [[1,4],[2,3],[3,4]]
     输出：[-1,2,-1]
     解释：对于区间 [1,4] 和 [3,4] ，没有满足条件的“右侧”区间。
     对于 [2,3] ，区间 [3,4] 有最小的“右”起点。
     */
    intervals = {{1,4},{2,3},{3,4}};
    res = {-1,2,-1};
    assert(res == Solution().findRightInterval(intervals));
    
    cout << "OK~" << endl;
    
    return 0;
}
