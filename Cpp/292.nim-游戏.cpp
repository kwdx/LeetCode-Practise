/*
 * @lc app=leetcode.cn id=292 lang=cpp
 *
 * [292] Nim 游戏
 */

#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    bool canWinNim(int n) {
        return n % 4 != 0;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    int n;
    bool res;
 
    /**
     输入：n = 4
     输出：false
     解释：如果堆中有 4 块石头，那么你永远不会赢得比赛；
          因为无论你拿走 1 块、2 块 还是 3 块石头，最后一块石头总是会被你的朋友拿走。
     */
    n = 4;
    res = false;
    assert(res == Solution().canWinNim(n));
    
    /**
     输入：n = 1
     输出：true
     */
    n = 1;
    res = true;
    assert(res == Solution().canWinNim(n));
    
    /**
     输入：n = 2
     输出：true
     */
    n = 2;
    res = true;
    assert(res == Solution().canWinNim(n));
    
    cout << "OK~" << endl;
    
    return 0;
}
