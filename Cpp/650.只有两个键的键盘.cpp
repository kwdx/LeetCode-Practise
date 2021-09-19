/*
 * @lc app=leetcode.cn id=650 lang=cpp
 *
 * [650] 只有两个键的键盘
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int minSteps(int n) {
        vector<int> f(n + 1);
        
        for (int i = 2; i <= n; ++i) {
            f[i] = INT_MAX;
            for (int j = 1; j * j <= i; ++j) {
                if (i % j == 0) {
                    f[i] = min(f[i], f[j] + i / j);
                    f[i] = min(f[i], f[i / j] + j);
                }
            }
        }
        
        return f[n];
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    int n, res;
 
    /**
     输入：3
     输出：3
     解释：
     最初, 只有一个字符 'A'。
     第 1 步, 使用 Copy All 操作。
     第 2 步, 使用 Paste 操作来获得 'AA'。
     第 3 步, 使用 Paste 操作来获得 'AAA'。
     */
    n = 3;
    res = 3;
    assert(res == Solution().minSteps(n));

    /**
     输入：n = 1
     输出：0
     */
    n = 1;
    res = 0;
    assert(res == Solution().minSteps(n));
    
    /**
     输入：n = 9
     输出：6
     */
    n = 9;
    res = 6;
    assert(res == Solution().minSteps(n));
    
    cout << "OK~" << endl;
    
    return 0;
}

