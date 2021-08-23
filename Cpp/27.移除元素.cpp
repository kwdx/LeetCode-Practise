/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int left = 0, right = 0;
        while (right < nums.size()) {
            while (right < nums.size() && nums[right] == val) {
                right++;
            }
            if (right < nums.size()) {
                nums[left++] = nums[right++];
            }
        }
        nums.resize(left);
        return left;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    vector<int> nums, result;
    int val, res;

    /**
     输入：nums = [3,2,2,3], val = 3
     输出：2, nums = [2,2]
     解释：函数应该返回新的长度 2, 并且 nums 中的前两个元素均为 2。你不需要考虑数组中超出新长度后面的元素。例如，函数返回的新长度为 2 ，而 nums = [2,2,3,3] 或 nums = [2,2,0,0]，也会被视作正确答案。
     */
    nums = {3,2,2,3};
    val = 3;
    res = 2;
    result = {2,2};
    assert(res == Solution().removeElement(nums, val));
    assert(result == nums);

    /**
     输入：nums = [0,1,2,2,3,0,4,2], val = 2
     输出：5, nums = [0,1,3,0,4]
     解释：函数应该返回新的长度 5, 并且 nums 中的前五个元素为 0, 1, 3, 0, 4。注意这五个元素可为任意顺序。你不需要考虑数组中超出新长度后面的元素。
     */
    nums = {0,1,2,2,3,0,4,2};
    val = 2;
    res = 5;
    result = {0,1,3,0,4};
    assert(res == Solution().removeElement(nums, val));
    assert(result == nums);

    cout << "OK~" << endl;

    return 0;
}
