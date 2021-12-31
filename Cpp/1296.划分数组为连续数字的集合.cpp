/*
 * @lc app=leetcode.cn id=1296 lang=cpp
 *
 * [1296] 划分数组为连续数字的集合
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// @lc code=start
class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        unordered_map<int, int> maps;
        priority_queue<int> q;
        for (int num : nums) {
            ++maps[num];
            q.push(num);
        }
        while (!q.empty()) {
            int val = q.top();
            q.pop();
            if (maps[val] == 0) {
                continue;
            }
            --maps[val];
            for (int i = 1; i < k; ++i) {
                if (maps[val - i] < 1) {
                    return false;
                }
                --maps[val - i];
            }
        }
        return true;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> nums;
    int k;
    bool res;
    
    /**
     输入：nums = [1,2,3,3,4,4,5,6], k = 4
     输出：true
     解释：数组可以分成 [1,2,3,4] 和 [3,4,5,6]。
     */
    nums = {1,2,3,3,4,4,5,6};
    k = 4;
    res = true;
    assert(res == Solution().isPossibleDivide(nums, k));
    
    /**
     输入：nums = [3,2,1,2,3,4,3,4,5,9,10,11], k = 3
     输出：true
     解释：数组可以分成 [1,2,3] , [2,3,4] , [3,4,5] 和 [9,10,11]。
     */
    nums = {3,2,1,2,3,4,3,4,5,9,10,11};
    k = 3;
    res = true;
    assert(res == Solution().isPossibleDivide(nums, k));
    
    /**
     输入：nums = [3,3,2,2,1,1], k = 3
     输出：true
     */
    nums = {3,3,2,2,1,1};
    k = 3;
    res = true;
    assert(res == Solution().isPossibleDivide(nums, k));
    
    /**
     输入：nums = [1,2,3,4], k = 3
     输出：false
     解释：数组不能分成几个大小为 3 的子数组。
     */
    nums = {1,2,3,4};
    k = 3;
    res = false;
    assert(res == Solution().isPossibleDivide(nums, k));

    cout << "OK~" << endl;

    return 0;
}
