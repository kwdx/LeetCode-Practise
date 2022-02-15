/*
 * @lc app=leetcode.cn id=540 lang=cpp
 *
 * [540] 有序数组中的单一元素
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = (int)nums.size();
        for (int i = 0; i < n - 1; i += 2)
            if (nums[i] != nums[i + 1]) return nums[i];
        return nums[n - 1];
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> nums;
    int res;
    
    /**
     输入: nums = [1,1,2,3,3,4,4,8,8]
     输出: 2
     */
    nums = {1,1,2,3,3,4,4,8,8};
    res = 2;
    assert(res == Solution().singleNonDuplicate(nums));
    
    /**
     输入: nums =  [3,3,7,7,10,11,11]
     输出: 10
     */
    nums = {3,3,7,7,10,11,11};
    res = 10;
    assert(res == Solution().singleNonDuplicate(nums));

    cout << "OK~" << endl;

    return 0;
}
