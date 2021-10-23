/*
 * @lc app=leetcode.cn id=229 lang=cpp
 *
 * [229] 求众数 II
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <stack>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> valToFreqs;
        for (int& num : nums) {
            valToFreqs[num]++;
        }
        int n = (int)nums.size();
        vector<int> ans;
        for (auto& v : valToFreqs) {
            if (v.second > n / 3) {
                ans.push_back(v.first);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> nums, res;
    
    /**
     输入：[3,2,3]
     输出：[3]
     */
    nums = {3,2,3};
    res = {3};
    assert(res == Solution().majorityElement(nums));
    
    /**
     输入：nums = [1]
     输出：[1]
     */
    nums = {1};
    res = {1};
    assert(res == Solution().majorityElement(nums));

    /**
     输入：[1,1,1,3,3,2,2,2]
     输出：[1,2]
     */
    nums = {1,1,1,3,3,2,2,2};
    res = {1,2};
    assert(res == Solution().majorityElement(nums));
    
    cout << "OK~" << endl;
    
    return 0;
}
