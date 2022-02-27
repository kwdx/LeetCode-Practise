/*
 * @lc app=leetcode.cn id=553 lang=cpp
 *
 * [553] 最优除法
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        int n = (int)nums.size();
        string ans = to_string(nums[0]) + "/";
        if (n > 2) ans.append("(");
        for (int i = 1; i < n; ++i) {
            ans.append(to_string(nums[i]) + "/");
        }
        ans.pop_back();
        if (n > 2) {
            ans.append(")");
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> nums;
    string res;
    
    /**
     输入: [1000,100,10,2]
     输出: "1000/(100/10/2)"
     解释:
     1000/(100/10/2) = 1000/((100/10)/2) = 200
     但是，以下加粗的括号 "1000/((100/10)/2)" 是冗余的，
     因为他们并不影响操作的优先级，所以你需要返回 "1000/(100/10/2)"。

     其他用例:
     1000/(100/10)/2 = 50
     1000/(100/(10/2)) = 50
     1000/100/10/2 = 0.5
     1000/100/(10/2) = 2
     */
    nums = {1000,100,10,2};
    res = "1000/(100/10/2)";
    assert(res == Solution().optimalDivision(nums));

    cout << "OK~" << endl;
    
    return 0;
}
