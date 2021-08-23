/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> rnums;
        unordered_map<int, int> valToIndexes;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            if (valToIndexes.count(num)) {
                return {valToIndexes[num], i};
            }
            valToIndexes[target - num] = i;
        }
        return {-1, -1};
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    vector<int> nums, res;
    int target;

    /**
     输入：nums = [2,7,11,15], target = 9
     输出：[0,1]
     解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。
     */
//    nums = {2,7,11,15};
//    target = 9;
//    res = {0,1};
//    assert(res == Solution().twoSum(nums, target));

    /**
     输入：nums = [3,2,4], target = 6
     输出：[1,2]
     */
    nums = {3,2,4};
    target = 6;
    res = {1,2};
    assert(res == Solution().twoSum(nums, target));

    /**
     输入：nums = [3,3], target = 6
     输出：[0,1]
     */
    nums = {3,3};
    target = 6;
    res = {0,1};
    assert(res == Solution().twoSum(nums, target));

    cout << "OK~" << endl;

    return 0;
}
