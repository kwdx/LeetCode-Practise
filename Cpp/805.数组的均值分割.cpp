/*
 * @lc app=leetcode.cn id=805 lang=cpp
 *
 * [805] 数组的均值分割
 */

#include <iostream>
#include <vector>
#include <numeric>
#include <math.h>

using namespace std;

// @lc code=start
class Solution {
public:
    bool splitArraySameAverage(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        unsigned int tbs[300001] = {0};
        tbs[0] = 1;
        for (auto n : nums){
            for (int i=sum - n; i >= 0; i--){
                tbs[i+n] |= tbs[i] << 1;
            }
        }
        unsigned int x = 1;
        for (int i = 1; i < nums.size(); i++){
            x <<= 1;
            double su = (double)sum * i / nums.size();
            if (su != (int)su) continue;
            if (tbs[(int)su] & x) return true;
        }
        return false;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> nums;
    bool res;
    
    /**
     输入: nums = [1,2,3,4,5,6,7,8]
     输出: true
     解释: 我们可以将数组分割为 [1,4,5,8] 和 [2,3,6,7], 他们的平均值都是4.5。
     */
    nums = {1,2,3,4,5,6,7,8};
    res = true;
    assert(res == Solution().splitArraySameAverage(nums));
    
    /**
     输入: nums = [3,1]
     输出: false
     */
    nums = {3,1};
    res = false;
    assert(res == Solution().splitArraySameAverage(nums));
    
    cout << "OK~" << endl;
    
    return 0;
}
