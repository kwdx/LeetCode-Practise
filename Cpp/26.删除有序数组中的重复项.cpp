/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left = 0, right = 0;
        while (right < nums.size()) {
            nums[left] = nums[right++];
            while (right < nums.size() && nums[left] == nums[right]) {
                right++;
            }
            left++;
        }
        nums.resize(left);
        return left;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    vector<int> nums, res;
    int num;

    /**
     输入：nums = [1,1,2]
     输出：2, nums = [1,2]
     解释：函数应该返回新的长度 2 ，并且原数组 nums 的前两个元素被修改为 1, 2 。不需要考虑数组中超出新长度后面的元素。
     */
    nums = {1,1,2};
    num = 2;
    res = {1,2};
    assert(num == Solution().removeDuplicates(nums));
    assert(res == nums);

    /**
     输入：nums = [0,0,1,1,1,2,2,3,3,4]
     输出：5, nums = [0,1,2,3,4]
     解释：函数应该返回新的长度 5 ， 并且原数组 nums 的前五个元素被修改为 0, 1, 2, 3, 4 。不需要考虑数组中超出新长度后面的元素。
     */
    nums = {0,0,1,1,1,2,2,3,3,4};
    num = 5;
    res = {0,1,2,3,4};
    assert(num == Solution().removeDuplicates(nums));
    assert(res == nums);

    cout << "OK~" << endl;

    return 0;
}
