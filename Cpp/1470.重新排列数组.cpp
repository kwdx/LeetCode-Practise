/*
 * @lc app=leetcode.cn id=1470 lang=cpp
 *
 * [1470] 重新排列数组
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans;
        int i = 0, j = n;
        while (i < n) {
            ans.emplace_back(nums[i++]);
            ans.emplace_back(nums[j++]);
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> nums;
    int n;
    vector<int> res;
    
    /**
     输入：nums = [2,5,1,3,4,7], n = 3
     输出：[2,3,5,4,1,7]
     解释：由于 x1=2, x2=5, x3=1, y1=3, y2=4, y3=7 ，所以答案为 [2,3,5,4,1,7]
     */
    nums = {2,5,1,3,4,7};
    n = 3;
    res = {2,3,5,4,1,7};
    assert(res == Solution().shuffle(nums, n));
    
    /**
     输入：nums = [1,2,3,4,4,3,2,1], n = 4
     输出：[1,4,2,3,3,2,4,1]
     */
    nums = {1,2,3,4,4,3,2,1};
    n = 4;
    res = {1,4,2,3,3,2,4,1};
    assert(res == Solution().shuffle(nums, n));
    
    /**
     输入：nums = [1,1,2,2], n = 2
     输出：[1,2,1,2]
     */
    nums = {1,1,2,2};
    n = 2;
    res = {1,2,1,2};
    assert(res == Solution().shuffle(nums, n));

    cout << "OK~" << endl;
    
    return 0;
}
