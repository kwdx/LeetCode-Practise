/*
 * @lc app=leetcode.cn id=1995 lang=cpp
 *
 * [1995] 统计特殊四元组
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int res = 0;

        for (int i = (int)nums.size() - 1; i > 2; --i) {
            int sum = nums[i];
            for (int j = i - 1; j > 1; --j) {
                int target = sum - nums[j];
                if (target <= 1) continue;
                for (int left = 0; left < j - 1; ++left) {
                    int targetRight = target - nums[left];
                    if (targetRight < 1) {
                        continue;
                    }
                    
                    int right = j - 1;
                    while (left < right) {
                        if (nums[right] == targetRight) {
                            ++res;
                        }
                        --right;
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> nums;
    int res;
    
    /**
     输入：nums = [1,2,3,6]
     输出：1
     解释：满足要求的唯一一个四元组是 (0, 1, 2, 3) 因为 1 + 2 + 3 == 6 。
     */
    nums = {1,2,3,6};
    res = 1;
    assert(res == Solution().countQuadruplets(nums));
    
    /**
     输入：nums = [3,3,6,4,5]
     输出：0
     解释：[3,3,6,4,5] 中不存在满足要求的四元组。
     */
    nums = {3,3,6,4,5};
    res = 0;
    assert(res == Solution().countQuadruplets(nums));

    /**
     输入：nums = [1,1,1,3,5]
     输出：4
     解释：满足要求的 4 个四元组如下：
     - (0, 1, 2, 3): 1 + 1 + 1 == 3
     - (0, 1, 3, 4): 1 + 1 + 3 == 5
     - (0, 2, 3, 4): 1 + 1 + 3 == 5
     - (1, 2, 3, 4): 1 + 1 + 3 == 5
     */
    nums = {1,1,1,3,5};
    res = 4;
    assert(res == Solution().countQuadruplets(nums));

    cout << "OK~" << endl;

    return 0;
}
