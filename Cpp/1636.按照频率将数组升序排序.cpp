/*
 * @lc app=leetcode.cn id=1636 lang=cpp
 *
 * [1636] 按照频率将数组升序排序
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> cnts;
        for (int& num : nums) {
            cnts[num] += 1;
        }
        sort(nums.begin(), nums.end(), [&](int& a, int& b) {
            if (cnts[a] == cnts[b]) {
                return a > b;
            } else {
                return cnts[a] < cnts[b];
            }
        });
        return nums;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> nums;
    vector<int> res;
    
    /**
     输入：nums = [1,1,2,2,2,3]
     输出：[3,1,1,2,2,2]
     解释：'3' 频率为 1，'1' 频率为 2，'2' 频率为 3 。
     */
    nums = {1,1,2,2,2,3};
    res = {3,1,1,2,2,2};
    assert(res == Solution().frequencySort(nums));
    
    /**
     输入：nums = [2,3,1,3,2]
     输出：[1,3,3,2,2]
     解释：'2' 和 '3' 频率都为 2 ，所以它们之间按照数值本身降序排序。
     */
    nums = {2,3,1,3,2};
    res = {1,3,3,2,2};
    assert(res == Solution().frequencySort(nums));
    
    /**
     输入：nums = [1,1,2,2,2,3]
     输出：[3,1,1,2,2,2]
     */
    nums = {1,1,2,2,2,3};
    res = {3,1,1,2,2,2};
    assert(res == Solution().frequencySort(nums));

    cout << "OK~" << endl;
    
    return 0;
}
