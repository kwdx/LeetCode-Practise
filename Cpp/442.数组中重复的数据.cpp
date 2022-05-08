/*
 * @lc app=leetcode.cn id=442 lang=cpp
 *
 * [442] 数组中重复的数据
 */

#include <iostream>
#include <vector>

using namespace std;


// @lc code=start
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        int n = (int)nums.size();
        for (int i = 0; i < n; ++i) {
            int num = nums[i];
            if (num < 0 || num == i + 1) {
                continue;
            }
            if (nums[num - 1] == num) {
                ans.emplace_back(num);
                nums[i] *= -1;
            } else {
                int c = nums[num - 1];
                nums[num - 1] = num;
                nums[i--] = c;
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end


int main(int argc, const char * argv[]) {
    // insert code here...

    vector<int> nums;
    vector<int> res;
    
    /**
     输入：nums = [4,3,2,7,8,2,3,1]
     输出：[2,3]
     */
    nums = {4,3,2,7,8,2,3,1};
    res = {2,3};
    assert(res == Solution().findDuplicates(nums));
    
    /**
     输入：nums = [1,1,2]
     输出：[1]
     */
    nums = {1,1,2};
    res = {1};
    assert(res == Solution().findDuplicates(nums));
    
    /**
     输入：nums = [1]
     输出：[]
     */
    nums = {1};
    res = {};
    assert(res == Solution().findDuplicates(nums));
    
    cout << "OK~" << endl;
    
    return 0;
}
