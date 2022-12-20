/*
 * @lc app=leetcode.cn id=1785 lang=cpp
 *
 * [1785] 构成特定和需要添加的最少元素
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long long sum = 0;
        for (int &num : nums) {
            sum += num;
        }
        long long diff = abs(sum - goal);
        return int((diff + limit - 1) / limit);
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> nums;
    int limit;
    int goal;
    int res;
    
    /**
     输入：nums = [1,-1,1], limit = 3, goal = -4
     输出：2
     解释：可以将 -2 和 -3 添加到数组中，数组的元素总和变为 1 - 1 + 1 - 2 - 3 = -4 。
     */
    nums = {1,-1,1};
    limit = 3;
    goal = -4;
    res = 2;
    assert(res == Solution().minElements(nums, limit, goal));
    
    /**
     输入：nums = [1,-10,9,1], limit = 100, goal = 0
     输出：1
     */
    nums = {1,-10,9,1};
    limit = 100;
    goal = 0;
    res = 1;
    assert(res == Solution().minElements(nums, limit, goal));

    cout << "OK~" << endl;
    
    return 0;
}
