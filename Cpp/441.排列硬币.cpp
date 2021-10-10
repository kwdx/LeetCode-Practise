/*
 * @lc app=leetcode.cn id=441 lang=cpp
 *
 * [441] 排列硬币
 */

#include <iostream>
#include <math.h>

using namespace std;

// @lc code=start
class Solution {
public:
    int arrangeCoins(int n) {
        return (int)((sqrt((long)8 * n + 1) - 1) / 2);
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    int n, res;
    
    /**
     输入：n = 5
     输出：2
     解释：因为第三行不完整，所以返回 2 。
     */
    n = 5;
    res = 2;
    assert(res == Solution().arrangeCoins(n));
    
    /**
     输入：n = 8
     输出：3
     解释：因为第四行不完整，所以返回 3 。
     */
    n = 8;
    res = 3;
    assert(res == Solution().arrangeCoins(n));
    
    cout << "OK~" << endl;
    
    return 0;
}
