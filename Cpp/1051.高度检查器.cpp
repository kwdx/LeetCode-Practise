/*
 * @lc app=leetcode.cn id=1051 lang=cpp
 *
 * [1051] 高度检查器
 */

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

// @lc code=start
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> expected = heights;
        sort(expected.begin(), expected.end());
        int ans = 0;
        for (int i = 0; i < expected.size(); ++i) {
            if (expected[i] != heights[i]) {
                ++ans;
            }
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> heights;
    int res;
    
    /**
     输入：heights = [1,1,4,2,1,3]
     输出：3
     解释：
     高度：[1,1,4,2,1,3]
     预期：[1,1,1,2,3,4]
     下标 2 、4 、5 处的学生高度不匹配。
     */
    heights = {1,1,4,2,1,3};
    res = 3;
    assert(res == Solution().heightChecker(heights));
    
    /**
     输入：heights = [5,1,2,3,4]
     输出：5
     解释：
     高度：[5,1,2,3,4]
     预期：[1,2,3,4,5]
     所有下标的对应学生高度都不匹配。
     */
    heights = {5,1,2,3,4};
    res = 5;
    assert(res == Solution().heightChecker(heights));
    
    /**
     输入：heights = [1,2,3,4,5]
     输出：0
     解释：
     高度：[1,2,3,4,5]
     预期：[1,2,3,4,5]
     所有下标的对应学生高度都匹配。
     */
    heights = {1,2,3,4,5};
    res = 0;
    assert(res == Solution().heightChecker(heights));
    
    cout << "OK~" << endl;
    
    return 0;
}
