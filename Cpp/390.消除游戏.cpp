/*
 * @lc app=leetcode.cn id=390 lang=cpp
 *
 * [390] 消除游戏
 */

#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    int lastRemaining(int n) {
        if (n == 1) return 1;
        return 2 * ((n >> 1) + 1 - lastRemaining(n >> 1));
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int n;
    int res;
    
    /**
     输入：n = 9
     输出：6
     解释：
     arr = [1, 2, 3, 4, 5, 6, 7, 8, 9]
     arr = [2, 4, 6, 8]
     arr = [2, 6]
     arr = [6]
     */
    n = 9;
    res = 6;
    assert(res == Solution().lastRemaining(n));
    
    /**
     输入：n = 1
     输出：1
     */
    n = 1;
    res = 1;
    assert(res == Solution().lastRemaining(n));
    
    cout << "OK~" << endl;

    return 0;
}
