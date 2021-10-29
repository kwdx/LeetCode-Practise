/*
 * @lc app=leetcode.cn id=869 lang=cpp
 *
 * [869] 重新排序得到 2 的幂
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// @lc code=start
class Solution {
private:
    vector<int> vis;
    
    bool isPowerOf2(int n) {
        return (n & (n - 1)) == 0;
    }
    
    bool backtrace(string& nums, int idx, int num) {
        if (idx == nums.size()) {
            return isPowerOf2(num);
        }
        
        for (int i = 0; i < nums.size(); ++i) {
            if ((num == 0 && nums[i] == '0') ||
                vis[i] == 1 ||
                (i > 0 && vis[i - 1] == 0 && nums[i] == nums[i - 1])) {
                continue;
            }
            
            vis[i] = 1;
            if (backtrace(nums, idx + 1, num * 10 + nums[i] - '0')) {
                return true;
            }
            vis[i] = 0;
        }
        return false;
    }
    
public:
    bool reorderedPowerOf2(int n) {
        string nums = to_string(n);
        sort(nums.begin(), nums.end());
        vis.resize(nums.size());
        return backtrace(nums, 0, 0);
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int n;
    bool res;
    
    /**
     输入：1
     输出：true
     */
    n = 1;
    res = true;
    assert(res == Solution().reorderedPowerOf2(n));

    /**
     输入：10
     输出：false
     */
    n = 10;
    res = false;
    assert(res == Solution().reorderedPowerOf2(n));

    /**
     输入：16
     输出：true
     */
    n = 16;
    res = true;
    assert(res == Solution().reorderedPowerOf2(n));

    /**
     输入：24
     输出：false
     */
    n = 24;
    res = false;
    assert(res == Solution().reorderedPowerOf2(n));

    /**
     输入：46
     输出：true
     */
    n = 46;
    res = true;
    assert(res == Solution().reorderedPowerOf2(n));

    /**
     输入：4609
     输出：true
     */
    n = 4609;
    res = true;
    assert(res == Solution().reorderedPowerOf2(n));
    
    /**
     输入：56635
     输出：true
     */
    n = 56635;
    res = true;
    assert(res == Solution().reorderedPowerOf2(n));
    
    cout << "OK~" << endl;
    
    return 0;
}
