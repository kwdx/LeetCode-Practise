/*
 * @lc app=leetcode.cn id=464 lang=cpp
 *
 * [464] 我能赢吗
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
private:
    int n, t;
    vector<int> f;
    
    int dfs(int state, int tot) {
        if (f[state] != 0) return f[state];
        for (int i = 0; i < n; i++) {
            if (((state >> i) & 1) == 1) continue;
            if (tot + i + 1 >= t) return f[state] = 1;
            if (dfs(state | (1 << i), tot + i + 1) == -1) return f[state] = 1;
        }
        return f[state] = -1;
    }

public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        f.resize(1 << 20);
        n = maxChoosableInteger;
        t = desiredTotal;
        if (n * (n + 1) / 2 < t) return false;
        if (t == 0) return true;
        return dfs(0, 0) == 1;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int maxChoosableInteger;
    int desiredTotal;
    bool res;
    
    /**
     输入：maxChoosableInteger = 10, desiredTotal = 11
     输出：false
     解释：
     无论第一个玩家选择哪个整数，他都会失败。
     第一个玩家可以选择从 1 到 10 的整数。
     如果第一个玩家选择 1，那么第二个玩家只能选择从 2 到 10 的整数。
     第二个玩家可以通过选择整数 10（那么累积和为 11 >= desiredTotal），从而取得胜利.
     同样地，第一个玩家选择任意其他整数，第二个玩家都会赢。
     */
    maxChoosableInteger = 10;
    desiredTotal = 11;
    res = false;
    assert(res == Solution().canIWin(maxChoosableInteger, desiredTotal));
    
    /**
     输入：maxChoosableInteger = 10, desiredTotal = 0
     输出：true
     */
    maxChoosableInteger = 10;
    desiredTotal = 0;
    res = true;
    assert(res == Solution().canIWin(maxChoosableInteger, desiredTotal));

    /**
     输入：maxChoosableInteger = 10, desiredTotal = 1
     输出：true
     */
    maxChoosableInteger = 10;
    desiredTotal = 1;
    res = true;
    assert(res == Solution().canIWin(maxChoosableInteger, desiredTotal));

    cout << "OK~" << endl;
    
    return 0;
}
