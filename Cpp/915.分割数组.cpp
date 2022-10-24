/*
 * @lc app=leetcode.cn id=915 lang=cpp
 *
 * [915] 分割数组
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = (int)nums.size();
        vector<int> mins(n + 1);
        mins[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            mins[i] = min(mins[i + 1], nums[i]);
        }
        int maxNum = 0;
        for (int i = 0; i < n - 1; ++i) {
            maxNum = max(maxNum, nums[i]);
            if (maxNum <= mins[i + 1]) {
                return i + 1;
            }
        }
        return -1;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> nums;
    int res;
    
    /**
     输入：nums = [5,0,3,8,6]
     输出：3
     解释：left = [5,0,3]，right = [8,6]
     */
    nums = {5,0,3,8,6};
    res = 3;
    assert(res == Solution().partitionDisjoint(nums));
    
    /**
     输入：nums = [1,1,1,0,6,12]
     输出：4
     解释：left = [1,1,1,0]，right = [6,12]
     */
    nums = {1,1,1,0,6,12};
    res = 4;
    assert(res == Solution().partitionDisjoint(nums));
    
    cout << "OK~" << endl;
    
    return 0;
}
