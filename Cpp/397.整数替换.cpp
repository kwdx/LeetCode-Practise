/*
 * @lc app=leetcode.cn id=397 lang=cpp
 *
 * [397] 整数替换
 */

#include <iostream>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
private:
    unordered_map<int, int> memo;
public:
    int integerReplacement(int n) {
        if (n == 1) {
            return 0;
        }
        if (memo.count(n)) {
            return memo[n];
        }
        if (n % 2 == 0) {
            memo[n] = 1 + integerReplacement(n / 2);
        } else {
            memo[n] = 2 + min(integerReplacement(n / 2), integerReplacement(n / 2 + 1));
        }
        return memo[n];
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int n;
    int res;
    
    /**
     输入：n = 8
     输出：3
     解释：8 -> 4 -> 2 -> 1
     */
    n = 8;
    res = 3;
    assert(res == Solution().integerReplacement(n));
    
    /**
     输入：n = 7
     输出：4
     解释：7 -> 8 -> 4 -> 2 -> 1
     或 7 -> 6 -> 3 -> 2 -> 1
     */
    n = 7;
    res = 4;
    assert(res == Solution().integerReplacement(n));
    
    /**
     输入：n = 4
     输出：2
     */
    n = 4;
    res = 2;
    assert(res == Solution().integerReplacement(n));

    cout << "OK~" << endl;

    return 0;
}
