/*
 * @lc app=leetcode.cn id=793 lang=cpp
 *
 * [793] 阶乘函数后 K 个零
 */

#include <iostream>
#include <unordered_map>
#include "TreeNode.h"

using namespace std;

// @lc code=start
class Solution {
public:
    int preimageSizeFZF(int k) {
        return (int)(help(k + 1) - help(k));
    }
    int zeta(int x) {
        int ans = 0;
        while (x > 0) {
            ans += x / 5;
            x /= 5;
        }
        return ans;
    }
    
    long long help(int k) {
        long long r = k * 5LL;
        long long l = 0;
        while (l <= r) {
            long long mid = (l + r) >> 1;
            if (zeta((int)mid) < k) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return r + 1;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int k;
    int res;
    
    /**
     输入：k = 0
     输出：5
     解释：0!, 1!, 2!, 3!, 和 4! 均符合 k = 0 的条件。
     */
    k = 0;
    res = 5;
    assert(res == Solution().preimageSizeFZF(k));
    
    /**
     输入：k = 5
     输出：0
     解释：没有匹配到这样的 x!，符合 k = 5 的条件。
     */
    k = 5;
    res = 0;
    assert(res == Solution().preimageSizeFZF(k));

    /**
     输入: k = 3
     输出: 5
     */
    k = 3;
    res = 5;
    assert(res == Solution().preimageSizeFZF(k));

    cout << "OK~" << endl;
    
    return 0;
}
