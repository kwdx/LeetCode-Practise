/*
 * @lc app=leetcode.cn id=1748 lang=cpp
 *
 * [1748] 唯一元素的和
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int cnts[101] = {0};
        for (int num : nums) {
            cnts[num] += 1;
        }
        int ans = 0;
        for (int num : nums) {
            if (cnts[num] == 1) {
                ans += num;
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
     输入：nums = [1,2,3,2]
     输出：4
     解释：唯一元素为 [1,3] ，和为 4 。
     */
    nums = {1,2,3,2};
    res = 4;
    assert(res == Solution().sumOfUnique(nums));
    
    /**
     输入：nums = [1,1,1,1,1]
     输出：0
     解释：没有唯一元素，和为 0 。
     */
    nums = {1,1,1,1,1};
    res = 0;
    assert(res == Solution().sumOfUnique(nums));
    
    /**
     输入：nums = [1,2,3,4,5]
     输出：15
     解释：唯一元素为 [1,2,3,4,5] ，和为 15 。
     */
    nums = {1,2,3,4,5};
    res = 15;
    assert(res == Solution().sumOfUnique(nums));

    cout << "OK~" << endl;

    return 0;
}
