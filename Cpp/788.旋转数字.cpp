/*
 * @lc app=leetcode.cn id=788 lang=cpp
 *
 * [788] 旋转数字
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int rotatedDigits(int n) {
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            bool isOK = false;
            bool isBreak = false;
            int x = i;
            while (x != 0) {
                int t = x % 10;
                x /= 10;
                if (t == 2 || t == 5 || t == 6 || t == 9) {
                    isOK = true;
                }
                else if (t != 0 && t != 1 && t != 8) {
                    isBreak = true;
                    break;
                }
            }
            if (isBreak) {
                continue;
            }
            if (isOK) ++ans;
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int n;
    int res;
    
    /**
     输入: 10
     输出: 4
     解释:
     在[1, 10]中有四个好数： 2, 5, 6, 9。
     注意 1 和 10 不是好数, 因为他们在旋转之后不变。
     */
    n = 10;
    res = 4;
    assert(res == Solution().rotatedDigits(n));

    cout << "OK~" << endl;
    
    return 0;
}

