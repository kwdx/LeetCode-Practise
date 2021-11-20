/*
 * @lc app=leetcode.cn id=594 lang=cpp
 *
 * [594] 最长和谐子序列
 */

#include <iostream>
#include <vector>
#include <map>

using namespace std;

// @lc code=start
class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int, int> cnts;
        for (int num : nums) {
            ++cnts[num];
        }
        int ans = 0;
        for (auto & item : cnts) {
            if (cnts.count(item.first + 1)) {
                ans = max(ans, item.second + cnts[item.first + 1]);
            }
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> nums;
    int res;
    
    /**
     输入：nums = [1,3,2,2,5,2,3,7]
     输出：5
     解释：最长的和谐子序列是 [3,2,2,2,3]
     */
    nums = {1,3,2,2,5,2,3,7};
    res = 5;
    assert(res == Solution().findLHS(nums));
    
    /**
     输入：nums = [1,2,3,4]
     输出：2
     */
    nums = {1,2,3,4};
    res = 2;
    assert(res == Solution().findLHS(nums));
    
    /**
     输入：nums = [1,1,1,1]
     输出：0
     */
    nums = {1,1,1,1};
    res = 0;
    assert(res == Solution().findLHS(nums));

    cout << "OK~" << endl;

    return 0;
}
