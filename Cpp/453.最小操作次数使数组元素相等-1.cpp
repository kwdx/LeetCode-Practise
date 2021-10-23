/*
 * @lc app=leetcode.cn id=453 lang=cpp
 *
 * [453] 最小操作次数使数组元素相等
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int totalNum = 0, minNum = nums[0];
        for (int & num : nums) {
            totalNum += num;
            minNum = min(minNum, num);
        }
        return totalNum - minNum * (int)nums.size();
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> nums;
    int res;
    
    /**
     输入：nums = [1,2,3]
     输出：3
     解释：
     只需要3次操作（注意每次操作会增加两个元素的值）：
     [1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]
     */
    nums = {1,2,3};
    res = 3;
    assert(res == Solution().minMoves(nums));
    
    /**
     输入：nums = [1,1,1]
     输出：0
     */
    nums = {1,1,1};
    res = 0;
    assert(res == Solution().minMoves(nums));
    
    cout << "OK~" << endl;

    return 0;
}
