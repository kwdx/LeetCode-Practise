/*
 * @lc app=leetcode.cn id=1342 lang=cpp
 *
 * [1342] 将数字变成 0 的操作次数
 */

#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    int numberOfSteps(int num) {
        int ans = 0;
        while (num != 0) {
            if ((num & 1) == 1) {
                num -= 1;
            } else {
                num >>= 1;
            }
            ans += 1;
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int num;
    int res;
    
    /**
     输入：num = 14
     输出：6
     解释：
     步骤 1) 14 是偶数，除以 2 得到 7 。
     步骤 2） 7 是奇数，减 1 得到 6 。
     步骤 3） 6 是偶数，除以 2 得到 3 。
     步骤 4） 3 是奇数，减 1 得到 2 。
     步骤 5） 2 是偶数，除以 2 得到 1 。
     步骤 6） 1 是奇数，减 1 得到 0 。
     */
    num = 14;
    res = 6;
    assert(res == Solution().numberOfSteps(num));
    
    /**
     输入：num = 8
     输出：4
     解释：
     步骤 1） 8 是偶数，除以 2 得到 4 。
     步骤 2） 4 是偶数，除以 2 得到 2 。
     步骤 3） 2 是偶数，除以 2 得到 1 。
     步骤 4） 1 是奇数，减 1 得到 0 。
     */
    num = 8;
    res = 4;
    assert(res == Solution().numberOfSteps(num));
    
    /**
     输入：num = 123
     输出：12
     */
    num = 123;
    res = 12;
    assert(res == Solution().numberOfSteps(num));

    cout << "OK~" << endl;

    return 0;
}
