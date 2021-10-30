/*
 * @lc app=leetcode.cn id=260 lang=cpp
 *
 * [260] 只出现一次的数字 III
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            ++freq[num];
        }
        vector<int> ans;
        for (auto item : freq) {
            if (item.second == 1) {
                ans.push_back(item.first);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> nums;
    vector<int> res;
    
    /**
     输入：nums = [1,2,1,3,2,5]
     输出：[3,5]
     解释：[5, 3] 也是有效的答案。
     */
    nums = {1,2,1,3,2,5};
    res = {3,5};
    assert(res == Solution().singleNumber(nums));
    
    /**
     输入：nums = [-1,0]
     输出：[-1,0]
     */
    nums = {-1,0};
    res = {-1,0};
    assert(res == Solution().singleNumber(nums));
    
    /**
     输入：nums = [0,1]
     输出：[1,0]
     */
    nums = {0,1};
    res = {1,0};
    assert(res == Solution().singleNumber(nums));

    cout << "OK~" << endl;

    return 0;
}
