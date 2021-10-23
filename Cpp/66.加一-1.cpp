/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = (int)digits.size();
        for (int i = n - 1; i >= 0; --i) {
            if (digits[i] != 9) {
                ++digits[i];
                for (int j = i + 1; j < n; ++j) {
                    digits[j] = 0;
                }
                return digits;
            }
        }
        
        vector<int> ans(n + 1);
        ans[0] = 1;
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> digits, res;
    
    /**
     输入：digits = [1,2,3]
     输出：[1,2,4]
     解释：输入数组表示数字 123。
     */
    digits = {1,2,3};
    res = {1,2,4};
    assert(res == Solution().plusOne(digits));
    
    /**
     输入：digits = [4,3,2,1]
     输出：[4,3,2,2]
     解释：输入数组表示数字 4321。
     */
    digits = {4,3,2,1};
    res = {4,3,2,2};
    assert(res == Solution().plusOne(digits));
    
    /**
     输入：digits = [0]
     输出：[1]
     */
    digits = {0};
    res = {1};
    assert(res == Solution().plusOne(digits));
    
    /**
     输入：digits = [9]
     输出：[1,0]
     */
    digits = {0};
    res = {1};
    assert(res == Solution().plusOne(digits));
    
    cout << "OK~" << endl;

    return 0;
}
